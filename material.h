//
//  material.h
//  ray tracer
//
//  Created by Sahith Nallapareddy on 11/16/17.
//  Copyright © 2017 Sahith Nallapareddy. All rights reserved.
//

#ifndef material_h
#define material_h

#include "hitable.h"

class material {
public:
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
};

#endif /* material_h */
