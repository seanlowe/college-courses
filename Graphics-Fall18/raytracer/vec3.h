// contains the vec3 and sphere classes

#pragma once
#include <cmath>
#include <iostream>

template<typename t>
class vec3 {
public: t x, y, z;
public: vec3() : x(t(0)), y(t(0)), z(t(0)) {}
public: vec3(t val) : x(val), y(val), z(val) {}
public: vec3(t xval, t yval, t zval) : x(xval), y(yval), z(zval) {}

    /* Class Functions */

public: vec3 length_sqrt() const {
            return sqrt(length_squared());
        }

public: t length_squared() const {
            return x*x + y*y + z*z;
        }

public: vec3 & normalize() {
            t norm = length_squared();
            if (norm > 0) {
                t inverse_norm = 1 / sqrt(norm);
                x *= inverse_norm;
                y *= inverse_norm;
                z *= inverse_norm;
            }
            return *this;
        }

    // dot operator implementation
public: t dot(const vec3<t> & v) const {
            return x*v.x + y*v.y + z*v.z;
        }

    /* Operator Overloading */
    
public: vec3<t> operator + (const vec3<t> & v) const {
            return vec3<t>(x+v.x, y+v.y, z+v.z);
        }

public: vec3<t> operator - (const vec3<t> & v) const {
            return vec3<t>(x-v.x, y-v.y, z-v.z);
        }

    // multiplication by a scalar
public: vec3<t> operator * (const t & f) const {
            return vec3<t> (x*f, y*f, z*f);
        }

    // multiplication by another vec3
public: vec3<t> operator * (const vec3<t> & v) const {
            return vec3<t>(x*v.x, y*v.y, z*v.z);
        }

    // negation
public: vec3<t> operator - () const {
            return vec3<t> (-x, -y, -z);
        }

public: vec3<t> operator += (const vec3<t> & v) {
            x += v.x; y += v.y; z += v.z;
            return *this;
        }

public: vec3<t> operator *= (const vec3<t> & v) {
            x *= v.x; y *= v.y; z *= v.z;
            return *this;
        }

    // output overloading
    friend std::ostream & operator << (std::ostream & os, const vec3<t> & v) {
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return os;
    }
};

typedef vec3<float> vec3f;

class sphere {
public:
    vec3f center;
    vec3f surfaceColor, emissionColor;
    float radius, radius_squared;
    float transparency, reflection;

    /* Constructor */
    sphere (
        const vec3f & c,
        const float & r,
        const vec3f & sc,
        const float & refl = 0,
        const float & trans = 0,
        const vec3f & ec = 0
        ) :

        center(c), radius(r), radius_squared(r*r),
        surfaceColor(sc), emissionColor(ec), transparency(trans),
        reflection(refl)

        { /* empty constructor body */ }   

    bool intersect(const vec3f & ray_origin, const vec3f & ray_dir, float & t0, float & t1) const {
        vec3f l = center - ray_origin;
        float tca = l.dot(ray_dir);
        if (tca < 0) return false;
        float d_squared = l.dot(l) - tca * tca;
        if (d_squared > radius_squared) return false;
        float thc = sqrt(radius_squared - d_squared);
        t0 = tca - thc;
        t1 = tca + thc;

        return true;
    }
};