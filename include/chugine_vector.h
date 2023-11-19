#ifndef _CHUGINE_VECTOR_H
#define _CHUGINE_VECTOR_H

#include <chugine.h>

typedef struct __chugine_vec2_t {
    long x, y;
} chugine_vec2_t;

typedef struct __chugine_vec3_t {
    long x, y, z;
} chugine_vec3_t;

#define CHUGINE_VEC2(x, y)    ((chugine_vec2_t){x,y})
#define CHUGINE_VEC3(x, y, z) ((chugine_vec3_t){x,y,z})

#endif /* _CHUGINE_VECTOR_H */
