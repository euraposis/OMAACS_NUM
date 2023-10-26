
#include "../../Unity/src/unity.h"
#include "../../../src/vector.h"

void setUp() {}

void tearDown() {}

void test_vector2_init()
{
  vector_2 res = vector_2_init(1, 2);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 1.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 2.0, res.y);
}

void test_vector2_zero()
{
  vector_2 res = vector_2_zero();
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
}

void test_vector2_addition()
{
  vector_2 a;
  a.x = 1;
  a.y = 2;
  vector_2 b;
  b.x = 4;
  b.y = 5;
  vector_2 res = vector_2_add(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 5.0f, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 7.0f, res.y);
}

void test_vector2_subtraction()
{
  vector_2 a;
  a.x = 1;
  a.y = 2;
  vector_2 b;
  b.x = 4;
  b.y = 7;
  vector_2 res = vector_2_sub(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, -3.0f, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, -5.0f, res.y);
}

void test_vector2_scaling()
{
  vector_2 a;
  a.x = 1;
  a.y = 2;
  double b = 3.0;
  vector_2 res = vector_2_scale(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 3.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 6.0, res.y);
  b = 0.01;
  res = vector_2_scale(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.01, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.02, res.y);
  b = 0;
  res = vector_2_scale(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
}

void test_vector2_dot()
{
  vector_2 a;
  a.x = 1;
  a.y = 0;
  vector_2 b;
  b.x = 0;
  b.y = 1;
  double res = vector_2_dot(a, b); // Should be 0 as they are perpendicular
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res);
  a.x = 40;
  a.y = 0.1;
  b.x = 0.5;
  b.y = 100;
  res = vector_2_dot(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 30.0, res);
}

void test_vector2_mag()
{
  vector_2 a;
  a.x = 1;
  a.y = 0;
  double res = vector_2_mag(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 1.0, res);
  a.x = 50;
  a.y = 50;
  res = vector_2_mag(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 70.7106781187, res);
}

void test_vector2_norm()
{
  vector_2 a;
  a.x = 1;
  a.y = 0;
  vector_2 res = vector_2_norm(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 1.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  a.x = 50;
  a.y = 50;
  res = vector_2_norm(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.70710678118, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.70710678118, res.y);
  // test nullvector
  a.x = 0;
  a.y = 0;
  res = vector_2_norm(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
}

void test_vector2_operations()
{
  RUN_TEST(test_vector2_init);
  RUN_TEST(test_vector2_zero);
  RUN_TEST(test_vector2_addition);
  RUN_TEST(test_vector2_subtraction);
  RUN_TEST(test_vector2_scaling);
  RUN_TEST(test_vector2_dot);
  RUN_TEST(test_vector2_mag);
  RUN_TEST(test_vector2_norm);
}

// vector 3 tests


void test_vector3_init()
{
  vector_3 res = vector_3_init(1, 2, 3);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 1.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 2.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 3.0, res.z);
}

void test_vector3_zero()
{
  vector_3 res = vector_3_zero();
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.z);
}

void test_vector3_addition()
{
  vector_3 a;
  a.x = 1;
  a.y = 2;
  a.z = 3;
  vector_3 b;
  b.x = 4;
  b.y = 5;
  b.z = 6;
  vector_3 res = vector_3_add(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 5.0f, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 7.0f, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 9.0f, res.z);
}

void test_vector3_subtraction()
{
  vector_3 a;
  a.x = 1;
  a.y = 2;
  a.z = 3;
  vector_3 b;
  b.x = 4;
  b.y = 5;
  b.z = 6;
  vector_3 res = vector_3_sub(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, -3.0f, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, -3.0f, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, -3.0f, res.z);
}

void test_vector3_scaling()
{
  vector_3 a = vector_3_init(1, 2, 3);
  double b = 3.0;
  vector_3 res = vector_3_scale(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 3.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 6.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 9.0, res.z);
  b = 0.01;
  res = vector_3_scale(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.01, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.02, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.03, res.z);
  b = 0;
  res = vector_3_scale(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.z);
  a = vector_3_zero();
  b = 3.0;
  res = vector_3_scale(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.z);
}

void test_vector3_dot()
{
  vector_3 a = vector_3_init(1, 0, 0);
  vector_3 b = vector_3_init(0, 1, 0);
  double res = vector_3_dot(a, b); // Should be 0 as they are perpendicular
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res);
  a = vector_3_init(40, 0.1, 0);
  b = vector_3_init(0.5, 100, 0);
  res = vector_3_dot(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 30.0, res);
  a = vector_3_init(40, 0.1, 50);
  b = vector_3_init(0.5, 100, 2);
  res = vector_3_dot(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 130, res);
}

void test_vector3_mag()
{
  vector_3 a = vector_3_init(1, 0, 0);
  double res = vector_3_mag(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 1.0, res);
  a = vector_3_init(50, 50, 50);
  res = vector_3_mag(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 86.6025403784, res);
  a = vector_3_init(50, 0, 50);
  res = vector_3_mag(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 70.7106781187, res);
  a = vector_3_init(0, 0, 0);
  res = vector_3_mag(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res);
}

void test_vector3_norm()
{
  vector_3 a = vector_3_init(1, 0, 0);
  vector_3 res = vector_3_norm(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 1.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.z);
  a = vector_3_init(50, 50, 50);
  res = vector_3_norm(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.57735026919, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.57735026919, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.57735026919, res.z);
  a = vector_3_init(50, 0, 50);
  res = vector_3_norm(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.70710678118, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.70710678118, res.z);
  // test nullvector
  a = vector_3_zero();
  res = vector_3_norm(a);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.z);
}

void test_vector3_cross()
{
  vector_3 a = vector_3_init(1, 0, 0);
  vector_3 b = vector_3_init(0, 1, 0);
  vector_3 res = vector_3_cross(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 1.0, res.z);
  a = vector_3_init(1, 0, 0);
  b = vector_3_init(0, 0, 1);
  res = vector_3_cross(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, -1.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.z);
  a = vector_3_init(0, 1, 0);
  b = vector_3_init(0, 0, 1);
  res = vector_3_cross(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 1.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.z);
  // test colinear vectors
  a = vector_3_init(1, 0, 0);
  b = vector_3_init(2, 0, 0);
  res = vector_3_cross(a, b);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.x);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.y);
  TEST_ASSERT_DOUBLE_WITHIN(1e-10, 0.0, res.z);
}

void test_vector3_operations()
{
  RUN_TEST(test_vector3_init);
  RUN_TEST(test_vector3_zero);
  RUN_TEST(test_vector3_addition);
  RUN_TEST(test_vector3_subtraction);
  RUN_TEST(test_vector3_scaling);
  RUN_TEST(test_vector3_dot);
  RUN_TEST(test_vector3_mag);
  RUN_TEST(test_vector3_norm);
  RUN_TEST(test_vector3_cross);
}

int main()
{
    UNITY_BEGIN();
    test_vector2_operations();
    test_vector3_operations();
    UNITY_END();
    return 0;
}