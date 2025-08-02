#include "math.h"     // seu cabeçalho onde Vec3 e protótipos estão
#include <math.h>     // para sqrtf, M_PI em sistemas POSIX

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Vec3 vec3_add(Vec3 a, Vec3 b) {
    return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
    return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 vec3_scale(Vec3 v, float s) {
    return (Vec3){v.x * s, v.y * s, v.z * s};
}

float vec3_dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
    return (Vec3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

float vec3_length(Vec3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vec3 vec3_normalize(Vec3 v) {
    float len = vec3_length(v);
    if (len == 0.0f) return (Vec3){0, 0, 0};
    return vec3_scale(v, 1.0f / len);
}

float to_radians(float degrees) {
    return degrees * (float)(M_PI / 180.0f);
}

float to_degrees(float radians) {
    return radians * (float)(180.0f / M_PI);
}
