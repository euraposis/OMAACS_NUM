/**
 * @file vectortest.c
 * @brief vector definitions
 * 
 * @author David Heine <david.heine@magenta.de>
 * @date 2021-02-24
 * 
*/
#ifndef OMAACS_NUM_VECTOR_H
#define OMAACS_NUM_VECTOR_H

// vector definitons

typedef struct vector_2{
    double x;
    double y;
} vector_2;

typedef struct vector_3{
    double x;
    double y;
    double z;
} vector_3;

// 2d vector operations

vector_2 vector_2_init(double x, double y);

vector_2 vector_2_zero();

vector_2 vector_2_add(vector_2 a, vector_2 b);

vector_2 vector_2_sub(vector_2 a, vector_2 b);

vector_2 vector_2_scale(vector_2 a, double b);

double vector_2_dot(vector_2 a, vector_2 b);

double vector_2_mag(vector_2 a);

vector_2 vector_2_norm(vector_2 a);

// 3d vector operations

vector_3 vector_3_init(double x, double y, double z);

vector_3 vector_3_zero();

vector_3 vector_3_add(vector_3 a, vector_3 b);

vector_3 vector_3_sub(vector_3 a, vector_3 b);

vector_3 vector_3_scale(vector_3 a, double b);

double vector_3_dot(vector_3 a, vector_3 b);

vector_3 vector_3_cross(vector_3 a, vector_3 b);

double vector_3_mag(vector_3 a);

vector_3 vector_3_norm(vector_3 a);

vector_3 vector_3_cross(vector_3 a, vector_3 b);

#endif