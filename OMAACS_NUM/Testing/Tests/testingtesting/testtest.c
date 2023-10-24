#include "../../Unity/src/unity.h"

void setUp() {}

void tearDown() {}

void testtofail()
{
    TEST_ASSERT_EQUAL(1, 0);
}

void testtopass()
{
    TEST_ASSERT_EQUAL(1, 1);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(testtofail);
    RUN_TEST(testtopass);
    UNITY_END();
    return 0;
}