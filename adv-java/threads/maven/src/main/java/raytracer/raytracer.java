package raytracer;

public class raytracer implements sphere {
    static final int MAX_RAY_DEPTH = 5;
    static final int INFINITY = (int)1e8;

    public float mix(float a, float b, float mix) {
        return b * mix + a * ( 1 - mix );
    }

    public vec3 trace(vec3 ray_origin, vec3 ray_dir, vector<sphere> spheres, int depth) {
        float tnear = INFINITY;
        sphere * sphere_pointer = null;

        for (int i = 0; i < spheres.size(); i++) {
            float t0 = INFINITY;
            float t1 = INFINITY;
            if (spheres[i].intersect(ray_origin, ray_dir, t0, t1)) {
                if (t0 < 0) t0 = t1;
                if (t0 < tnear) {
                    tnear = t0;
                    sphere_pointer = &spheres[i];
                }
            }
        }
        // if no intersection, return black or background color
        if (!sphere_pointer) return vec3(2);

        // color of ray / surface of object intersected by the ray
        vec3 surfaceColor = new vec3(0);
        // point of intersection
        vec3 point_intersect = scalarMult(add(ray_origin, ray_dir), tnear);
        // normal at the point of intersection
        vec3 point_normal = minus(point_intersect, sphere_pointer -> center);
        // make sure to normalize the Normal
        point_normal = point_normal.normalize();

        float bias = 1e-4;
        boolean inside = false;
        if (ray_dir.dotSelf(point_normal) > 0) point_normal = negateSelf(point_normal);
        inside = true;
        if ((sphere_pointer -> transparency > 0 || sphere_pointer -> reflection > 0) && depth < MAX_RAY_DEPTH) {
            float facing_ratio = -ray_dir.dotSelf(point_normal);

            // fresnel effect --> has to do with reflection properties
            // change the 'mix' value to change the effect
            float fresnel_effect = mix(pow(1 - facing_ratio, 3), 1, .1);

            // compute reflection direction
            // no need to normalize vectors used to calculate
            vec3 refl_dir = scalarMult(scalarMult(minus(ray_dir, point_normal), 2), dot(ray_dir, point_normal));
            refl_dir = refl_dir.normalize();
            vec3 reflection = trace(scalarMult(add(point_intersect, point_normal), bias), refl_dir, spheres, depth + 1);
            vec3 refraction = new vec3(0);
        }
    }
}