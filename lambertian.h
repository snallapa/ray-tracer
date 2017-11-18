//
//  lambertian.h
//  ray tracer
//
//  Created by Sahith Nallapareddy on 11/16/17.
//  Copyright © 2017 Sahith Nallapareddy. All rights reserved.
//

#ifndef lambertian_h
#define lambertian_h

#include "material.h"

class lambertian: public material {
public:
    lambertian(const vec3& a) : albedo(a) {}
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        scattered = ray(rec.p, target-rec.p);
        attenuation = albedo;
        return true;
    }
    vec3 albedo;
};

#endif /* lambertian_h */
