//
// Created by kkyse on 12/24/2017.
//

#include <stdlib.h>
#include "vector.h"

const Vector Vector_ZERO = Vector_new(0, 0);

inline Vector Vector_scale(const Vector vector, const float scalar) {
    return Vector_new(vector.x * scalar, vector.y * scalar);
}

inline Vector Vector_normalize(const Vector vector) {
    return Vector_scale(vector, 1 / Vector_norm(vector));
}

inline Vector Vector_add(const Vector vector1, const Vector vector2) {
	return Vector_new(vector1.x + vector2.x, vector1.y + vector2.y);
}

inline float Vector_dist2(const Vector vector1, const Vector vector2) {
    const float dx = vector1.x - vector2.x;
    const float dy = vector1.y - vector2.y;
    return dx * dx + dy * dy;
}

inline Vector Vector_direction(float degrees) {
    const float angle = deg2rad(degrees - 90.0f);
    return Vector_new(cosf(angle), sinf(angle));
}

static inline float random_float(const float min, const float max) {
    union {
        int i;
        float f;
    } x;
    x.i = rand();
    return remainderf(x.f, max - min) + min;
}

inline Vector Vector_random(const Vector min, const Vector max) {
    return Vector_new(random_float(min.x, max.x), random_float(min.y, max.y));
}