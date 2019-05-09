package raytracer;

public class vec3 {
    private float x, y, z;

    // constructors
    vec3() {}
    vec3(float val) {
        this.x = val;
        this.y = val;
        this.z = val;
    }
    vec3(float xval, float yval, float zval) {
        this.x = xval;
        this.y = yval;
        this.z = zval;
    }

    // FIX THIS
    // IS THIS CORRECT??
    public vec3 length_sqrt() {
        vec3 c = new vec3(
                (float)Math.sqrt(this.x),
                (float)Math.sqrt(this.y),
                (float)Math.sqrt(this.z)
        );
        return c;
    }

    private float length_squared() {
        return x*x + y+y + z*z;
    }

    vec3 normalize() {
        float norm = length_squared();
        if (norm > 0) {
            float inverse_norm = 1 / (float)Math.sqrt((double)norm);
            x *= inverse_norm;
            y *= inverse_norm;
            z *= inverse_norm;
        }
        return this;
    }

    // dot operator . . . we'll need this!
    float dotSelf(vec3 v) {
        return this.x*v.x +
               this.y*v.y +
               this.z*v.z;
    }

    float dot(vec3 a, vec3 b) {
        return a.x*b.x +
               a.y*b.y +
               a.z*b.z;
    }

    // no operator overloading in java
    // create functions for each operation
    // we will need to ray trace
    vec3 addToSelf(vec3 b) {
        return new vec3(this.x+b.x, this.y+b.y, this.z+b.z);
    }

    vec3 add(vec3 a, vec3 b) {
        return new vec3(a.x+b.x, a.y+b.y, a.z+b.z);
    }

    vec3 minusFromSelf(vec3 b) {
        return new vec3(this.x-b.x, this.y-b.y, this.z-b.z);
    }

    vec3 minus(vec3 a, vec3 b) {
        return new vec3(a.x-b.x, a.y-b.y, a.z-b.z);
    }

    vec3 scalarMultSelf(float scalar) {
        return new vec3(this.x*scalar, this.y*scalar, this.z*scalar);
    }

    vec3 scalarMult(vec3 a, float scalar) {
        return new vec3(a.x*scalar, a.y*scalar, a.z*scalar);
    }

    vec3 multiplySelf(vec3 b) {
        return new vec3(this.x*b.x, this.y*b.y, this.z*b.z);
    }

    vec3 multiply(vec3 a, vec3 b) {
        return new vec3(a.x*b.x, a.y*b.y, a.z*b.z);
    }

    vec3 negateSelf() {
        return new vec3(-this.x, -this.y, -this.z);
    }
}