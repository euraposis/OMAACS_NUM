#include "vector.h"

vector_2 vector_2_add(vector_2 a, vector_2 b)
{
  vector_2 res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  return res;
}