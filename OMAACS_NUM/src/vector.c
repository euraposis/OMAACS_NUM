#include "vector.h"
#include "math.h"

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