#ifndef OMAACS_NUM_QUATERNION_H
#define OMAACS_NUM_QUATERNION_H

#include "vector.h"

// quaternion definitions

typedef struct quaternion{
    double e1;
    double e2;
    double e3;
    double e4;
} quaternion;

typedef struct quaternion_omega{
    vector_3 e;
    double e4;
} quaternion_omega;

#endif