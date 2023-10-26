/**
 * @file vectortest.c
 * @brief Vector operations
 * 
 * @author David Heine <david.heine@magenta.de>
 * @date 2021-02-24
 * 
*/

#include "vector.h"
#include "math.h"

vector_2 vector_2_init(double x, double y)
{
  vector_2 res;
  res.x = x;
  res.y = y;
  return res;
}

vector_2 vector_2_zero()
{
  vector_2 res;
  res.x = 0;
  res.y = 0;
  return res;
}

vector_2 vector_2_add(vector_2 a, vector_2 b)
{
  vector_2 res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  return res;
}

vector_2 vector_2_sub(vector_2 a, vector_2 b)
{
  vector_2 res;
  res.x = a.x - b.x;
  res.y = a.y - b.y;
  return res;
}

vector_2 vector_2_scale(vector_2 a, double b)
{
  vector_2 res;
  res.x = a.x * b;
  res.y = a.y * b;
  return res;
}

double vector_2_dot(vector_2 a, vector_2 b)
{
  return (double) a.x * b.x + a.y * b.y;
}

double vector_2_mag(vector_2 a)
{
  return sqrt(vector_2_dot(a, a));
}

vector_2 vector_2_norm(vector_2 a)
{
  double mag = vector_2_mag(a);
  if (mag <= 1e-8)
    return a;
  return vector_2_scale(a, 1.0 / mag);
}


vector_3 vector_3_init(double x, double y, double z)
{
  vector_3 res;
  res.x = x;
  res.y = y;
  res.z = z;
  return res;
}

vector_3 vector_3_zero()
{
  vector_3 res;
  res.x = 0;
  res.y = 0;
  res.z = 0;
  return res;
}

vector_3 vector_3_add(vector_3 a, vector_3 b)
{
  vector_3 res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  res.z = a.z + b.z;
  return res;
}

vector_3 vector_3_sub(vector_3 a, vector_3 b)
{
  vector_3 res;
  res.x = a.x - b.x;
  res.y = a.y - b.y;
  res.z = a.z - b.z;
  return res;
}

vector_3 vector_3_scale(vector_3 a, double b)
{
  vector_3 res;
  res.x = a.x * b;
  res.y = a.y * b;
  res.z = a.z * b;
  return res;
}

double vector_3_dot(vector_3 a, vector_3 b)
{
  return (double) a.x * b.x + a.y * b.y + a.z * b.z;
}

double vector_3_mag(vector_3 a)
{
  return sqrt(vector_3_dot(a, a));
}

vector_3 vector_3_norm(vector_3 a)
{
  double mag = vector_3_mag(a);
  if (mag <= 1e-8)
    return a;
  return vector_3_scale(a, 1.0 / mag);
}

vector_3 vector_3_cross(vector_3 a, vector_3 b)
{
  vector_3 res;
  res.x = a.y * b.z - a.z * b.y;
  res.y = a.z * b.x - a.x * b.z;
  res.z = a.x * b.y - a.y * b.x;
  return res;
}