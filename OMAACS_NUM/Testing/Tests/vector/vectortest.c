
#include "../../Unity/src/unity.h"
#include "../../../src/vector.h"

void setUp() {}

void tearDown() {}


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

void test_vector_subtraction()
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

void test_vector_scaling()
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
  RUN_TEST(test_vector2_addition);
  RUN_TEST(test_vector_subtraction);
  RUN_TEST(test_vector_scaling);
  RUN_TEST(test_vector2_dot);
  RUN_TEST(test_vector2_mag);
  RUN_TEST(test_vector2_norm);
}

int main()
{
    UNITY_BEGIN();
    test_vector2_operations();
    UNITY_END();
    return 0;
}