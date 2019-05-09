package raytracer;

class sphere extends vec3 {
    vec3 center;
    vec3 surfaceColor;
    vec3 emissionColor;
    float radius;
    float radius_squared;
    float transparency;
    float reflection;

    sphere(vec3 c, vec3 sc, vec3 ec, float r, float refl, float trans) {
        center = c;
        surfaceColor = sc;
        emissionColor = ec;
        radius = r;
        reflection = refl;
        transparency = trans;
    }

    boolean intersect(vec3 ray_origin, vec3 ray_dir, float t0, float t1) {
        vec3 l = minus(center, ray_origin);
        float tca = l.dotSelf(ray_dir);
        if (tca < 0) return false;
        float d_squared = l.dotSelf(l) - (tca * tca);
        if (d_squared > radius_squared) return false;
        float thc = (float)Math.sqrt((double)radius_squared - (double)d_squared);
        t0 = tca - thc;
        t1 = tca + thc;
        return true;
    }
}