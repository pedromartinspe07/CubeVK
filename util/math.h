#ifndef MATH_H
#define MATH_H

#include <math.h>

typedef struct {
    float x, y, z;
} Vec3;

// Operações com vetores
Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_scale(Vec3 v, float s);
float vec3_dot(Vec3 a, Vec3 b);
Vec3 vec3_cross(Vec3 a, Vec3 b);
float vec3_length(Vec3 v);
Vec3 vec3_normalize(Vec3 v);

// Utilidades
float to_radians(float degrees);
float to_degrees(float radians);

#endif
