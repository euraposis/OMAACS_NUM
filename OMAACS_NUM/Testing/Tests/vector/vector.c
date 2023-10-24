#include "../../Unity/src/unity.h"

#include "../../../src/vector.h"

void setUp() {}

void tearDown() {}

void testvector()
{
    vector_3 v;
    v.x = 1;
    v.y = 2;
    v.z = 3;
    TEST_ASSERT_EQUAL(1, v.x);
    TEST_ASSERT_EQUAL(2, v.y);
    TEST_ASSERT_EQUAL(3, v.z);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(testvector);
    UNITY_END();
    return 0;
}