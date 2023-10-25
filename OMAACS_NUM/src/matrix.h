#ifndef OMAACS_NUM_MATRIX_H
#define OMAACS_NUM_MATRIX_H

// matrix definitions

typedef struct matrix_2x2{
    double a;
    double b;
    double c;
    double d;
} matrix_2x2;

typedef struct matrix_3x3{
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    double g;
    double h;
    double i;
} matrix_3x3;

typedef struct matrix_4x4{
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    double g;
    double h;
    double i;
    double j;
    double k;
    double l;
    double m;
    double n;
    double o;
    double p;
} matrix_4x4;


// matrix operations

// 2x2 matrix operations

matrix_2x2 matrix_2x2_add(matrix_2x2 a, matrix_2x2 b);

matrix_2x2 matrix_2x2_sub(matrix_2x2 a, matrix_2x2 b);

matrix_2x2 matrix_2x2_scale(matrix_2x2 a, double b);

matrix_2x2 matrix_2x2_mult(matrix_2x2 a, matrix_2x2 b);

double matrix_2x2_det(matrix_2x2 a);

matrix_2x2 matrix_2x2_inv(matrix_2x2 a);

// 3x3 matrix operations

matrix_3x3 matrix_3x3_add(matrix_3x3 a, matrix_3x3 b);

matrix_3x3 matrix_3x3_sub(matrix_3x3 a, matrix_3x3 b);

matrix_3x3 matrix_3x3_scale(matrix_3x3 a, double b);

matrix_3x3 matrix_3x3_mult(matrix_3x3 a, matrix_3x3 b);

double matrix_3x3_det(matrix_3x3 a);

matrix_3x3 matrix_3x3_inv(matrix_3x3 a);

// 4x4 matrix operations

matrix_4x4 matrix_4x4_add(matrix_4x4 a, matrix_4x4 b);

matrix_4x4 matrix_4x4_sub(matrix_4x4 a, matrix_4x4 b);

matrix_4x4 matrix_4x4_scale(matrix_4x4 a, double b);

matrix_4x4 matrix_4x4_mult(matrix_4x4 a, matrix_4x4 b);

double matrix_4x4_det(matrix_4x4 a);

matrix_4x4 matrix_4x4_inv(matrix_4x4 a);

#endif