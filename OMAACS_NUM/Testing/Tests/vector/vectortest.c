#define UNITY_INCLUDE_DOUBLE
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
    TEST_ASSERT_FLOAT_WITHIN(1e-10, 5 + 1e-8, res.x);
}

void test_vector2_operations()
{
  RUN_TEST(test_vector2_addition);
}

int main()
{
    UNITY_BEGIN();
    test_vector2_operations();
    UNITY_END();
    return 0;
}