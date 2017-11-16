//
//  hitable.h
//  ray tracer
//
//  Created by Sahith Nallapareddy on 11/15/17.
//  Copyright © 2017 Sahith Nallapareddy. All rights reserved.
//

#ifndef hitable_h
#define hitable_h

#include "ray.h"

struct hit_record {
    float t;
    vec3 p;
    vec3 normal;
};

class hitable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif /* hitable_h */
