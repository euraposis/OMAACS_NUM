/**
 * This is more or less the driving test for the numerics library.
 * 
 * 
*/

#include "../../Unity/src/unity.h"


void setUp() {}
void tearDown() {}

void testnumerics()
{
    TEST_FAIL_MESSAGE("There is no implementation for numerics yet.");
}


int main()
{
    UNITY_BEGIN();
    RUN_TEST(testnumerics);
    UNITY_END();
    return 0;
}
