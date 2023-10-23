#ifndef OMAACS_NUM_LINALG_H
#define OMAACS_NUM_LINALG_H

#include "matrix.h"
#include "vector.h"

// vector operations

// 2d vector operations
vector_2 vector_2_add(vector_2 a, vector_2 b);

vector_2 vector_2_sub(vector_2 a, vector_2 b);

vector_2 vector_2_scale(vector_2 a, double b);

double vector_2_dot(vector_2 a, vector_2 b);

double vector_2_mag(vector_2 a);

vector_2 vector_2_norm(vector_2 a);

// 3d vector operations

vector_3 vector_3_add(vector_3 a, vector_3 b);

vector_3 vector_3_sub(vector_3 a, vector_3 b);

vector_3 vector_3_scale(vector_3 a, double b);

double vector_3_dot(vector_3 a, vector_3 b);

vector_3 vector_3_cross(vector_3 a, vector_3 b);

double vector_3_mag(vector_3 a);

vector_3 vector_3_norm(vector_3 a);

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