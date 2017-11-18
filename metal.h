//
//  metal.h
//  ray tracer
//
//  Created by Sahith Nallapareddy on 11/16/17.
//  Copyright © 2017 Sahith Nallapareddy. All rights reserved.
//

#ifndef metal_h
#define metal_h

#include "material.h"
#include "vec3.h"


class metal: public material {
public:
    metal(const vec3& a, float f) : albedo(a) {
        if (f < 1) {
            fuzz = f;
        } else {
            fuzz = 1;
        }
    }
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }
    vec3 albedo;
    float fuzz;
    
};

#endif /* metal_h */
