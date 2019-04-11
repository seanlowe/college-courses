// code for building a simple ray-tracer following ScratchAPixel's tutorial

#include "vec3.h"
#include "sync.h"
#include <vector>
#include <fstream>
#include <thread>
using namespace std;

#define MAX_RAY_DEPTH 5

typedef vec3<float> vec3f;

float mix(const float & a, const float & b, const float & mix) {
    return b * mix + a * (1 - mix);
}

vec3f trace(
    const vec3f & ray_origin,
    const vec3f & ray_dir,
    const vector<sphere> & spheres,
    const int & depth
) {
    float tnear = INFINITY;
    const sphere * sphere_pointer = NULL;

    // find intersection of ray with sphere in the screen
    for (unsigned i = 0; i < spheres.size(); ++i) {
        float t0 = INFINITY, t1 = INFINITY;
        if (spheres[i].intersect(ray_origin, ray_dir, t0, t1)) {
            if (t0 < 0) t0 = t1;
            if (t0 < tnear) {
                tnear = t0;
                sphere_pointer = &spheres[i];
            }
        }
    }

    // if no intersection, return black or background color
    if (!sphere_pointer) return vec3f(2);

    // color of ray / surface of the object intersected by the ray
    vec3f surfaceColor = 0;
    // point of intersection
    vec3f point_intersect = ray_origin + ray_dir * tnear;
    // normal at the intersection point
    vec3f point_normal = point_intersect - sphere_pointer->center;
    // make sure to normalize the normal point
    point_normal.normalize();

    float bias = 1e-4;
    bool inside = false;
    if (ray_dir.dot(point_normal) > 0) point_normal = -point_normal, inside = true;
    if ((sphere_pointer->transparency > 0 || sphere_pointer->reflection > 0) && depth < MAX_RAY_DEPTH) {
        float facing_ratio = -ray_dir.dot(point_normal);
        
        // fresnel effect --> has to do with reflection
        // change the 'mix' value to change the effect
        float fresnel_effect = mix(pow(1 - facing_ratio, 3), 1, .1);

        // compute reflection direction
        // no need to normalize these vectors
        vec3f refl_dir = ray_dir - point_normal * 2 * ray_dir.dot(point_normal);
        refl_dir.normalize();
        vec3f reflection = trace(point_intersect + point_normal * bias, refl_dir, spheres, depth+1);
        vec3f refraction = 0;
        
        // if sphere is transparent, compute refraction (transmission)
        if (sphere_pointer->transparency) {
            // incident angle of refraction
            float ior = 1.1;
            // is the ray currently inside or outside the sphere?
            float eta = (inside) ? ior : 1 / ior;
            float cosi = -point_normal.dot(ray_dir);
            float k = 1 - eta * eta * (1 - cosi * cosi);
            vec3f refrac_dir = ray_dir * eta + point_normal * (eta * cosi - sqrt(k));
            refrac_dir.normalize();
            refraction = trace(point_intersect - point_normal * bias, refrac_dir, spheres, depth+1);
        }
        // the result is a mix of reflection and refraction, some compute that
        surfaceColor = (
            reflection * fresnel_effect +
            refraction * (1 - fresnel_effect) * sphere_pointer->transparency) *
            sphere_pointer->surfaceColor;
    } else /* sphere is not transparent */ {
        for (unsigned i = 0; i < spheres.size(); i++) {
            if (spheres[i].emissionColor.x > 0) {
                // this just so happens to be a light
                vec3f transmission = 1;
                vec3f light_dir = spheres[i].center - point_intersect;
                light_dir.normalize();
                for (unsigned j = 0; j < spheres.size(); j++) {
                    if (i != j) {
                        float t0, t1;
                        if (spheres[j].intersect(point_intersect + point_normal * bias, 
                        light_dir, t0, t1)) {
                            transmission = 0;
                            break;
                        }
                    }
                }
                surfaceColor += sphere_pointer->surfaceColor * transmission *
                max(float(0), point_normal.dot(light_dir)) * spheres[i].emissionColor;
            }
        }
    }
    return surfaceColor + sphere_pointer->emissionColor;
} // end of trace function

void render(const vector<sphere> & spheres) {
    unsigned width = 1920, height = 1080;
    vec3f * image = new vec3f[width * height], * pixel = image;
    float invWidth = 1 / float(width), invHeight = 1 / float(height);
    float fov = 30, aspect_ratio = width / float(height);
    float angle = tan(M_PI * 0.5 * fov / 180.);

    // trace rays
    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < width; ++x, ++pixel) {
            float xx = (2 * ((x + 0.5) * invWidth) - 1) * angle  * aspect_ratio;
            float yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle;
            vec3f ray_dir(xx, yy, -1);
            ray_dir.normalize();
            * pixel = trace(vec3f(0), ray_dir, spheres, 0);
        }
    }
    // save result to working directory
    ofstream ofs("./render.ppm", ios::out | ios::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (unsigned i = 0; i < width * height; ++i) {
        ofs << (unsigned char)(min(float(1), image[i].x) * 255) <<
               (unsigned char)(min(float(1), image[i].y) * 255) <<
               (unsigned char)(min(float(1), image[i].z) * 255);
    }
    ofs.close();
    delete [] image;
} // end of render function

void some_function() {
	cout << "a second thread exists" << endl;
}

int main() {
    srand48(13);
    vector<sphere> spheres;
    //                                  position                surface color
    //                               x    y    z       radius,          r      g     b      reflectivity, transparency, emission color
    //spheres.push_back(sphere(vec3f( 0.0, -1003.5, -50), 1000,   vec3f(0.30, 1.00, 0.20),        0,          0.00));   // green ground
    //spheres.push_back(sphere(vec3f( 0.0,  0, -1050),    1000,   vec3f(0.00, 0.50, 1.00),        0,          0.50));   // blue background
    spheres.push_back(sphere(vec3f( 0.0,  0, -30),      3.3,     vec3f(0.00, 1.00, 0.00),       0.5,        0.50));   // green middle
    spheres.push_back(sphere(vec3f( 2.5,  3, -27),      1.8,     vec3f(0.00, 0.00, 1.00),       0.7,        0.60));   // blue 
    spheres.push_back(sphere(vec3f( 4.0,  1, -26),      1.0,      vec3f(1.00, 0.00, 0.00),       1,         0.25));   // red 
    spheres.push_back(sphere(vec3f( -1.8, 0, -24),      0.47,    vec3f(0.90, 0.00, 0.90),       0.25,       0.19));   //tiny purple
    
    // light
    spheres.push_back(sphere(vec3f( 0.0, 500, -20),      3,      vec3f(0.00, 0.00, 0.00),       0,           0.0,       vec3f(.5))); 
    //spheres.push_back(sphere(vec3f( 0.0, 500, 20),       3,      vec3f(0.00, 0.00, 0.00),       0,           0.0,       vec3f(.5))); 
	
	std::thread t1(some_function);

    render(spheres); 

	t1.join();
    return 0;
}