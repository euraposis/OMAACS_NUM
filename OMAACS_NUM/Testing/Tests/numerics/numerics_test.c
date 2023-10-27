/**
 * This is more or less the driving test for the numerics library.
 * 
 * 
*/

#include "../../Unity/src/unity.h"
#include "../../../src/numerics.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void setUp() {}
void tearDown() {}

/**
 * Setup the ode to calculate dx/dt = x
*/

typedef struct teststate{
  double x;
} teststate;

void teststate_prop(void* result, void* state, void* direction, double dt)
{
  ((teststate*)result)->x = ((teststate*)state)->x + ((teststate*)direction)->x * dt;
}

void exp_lhs(void* res, void* state, double t)
{
  ((teststate*)res)->x = ((teststate*)state)->x;
}

/**
 * This should calculate the euler number as we solve dy/dx = x
 * with y(0) = 1 and search y(1) (which should be exp(1))
*/
void test_exp(){
  teststate s;
  s.x = 1.0;
  ode desc;
  desc.state = malloc(sizeof(teststate));
  ((teststate*)desc.state)->x = s.x;
  desc.lhs_pointer = exp_lhs;
  desc.propagator = teststate_prop;
  desc.state_size = sizeof(teststate);
  for(unsigned int i = 0; i < 100000; i++)
    explicite_euler_cauchy(&desc, 0, 0.00001);
  TEST_ASSERT_DOUBLE_WITHIN(0.001, 2.71828, (((teststate*)desc.state)->x));
}

/**
 * setup the ode dy/dt = sin(x);
*/

void sin_lhs(void* res, void* state, double t)
{
  ((teststate*)res)->x = cos(((teststate*)state)->x);
}

void test_sin()
{
  teststate s;
  s.x = 0.0;
  ode desc;
  desc.state = malloc(sizeof(teststate));
  ((teststate*)desc.state)->x = s.x;
  desc.lhs_pointer = sin_lhs;
  desc.propagator = teststate_prop;
  desc.state_size = sizeof(teststate);
  for(unsigned int i = 0; i < 100000000; i++)
    explicite_euler_cauchy(&desc, 0, 0.00000001);
  TEST_ASSERT_DOUBLE_WITHIN(0.001, sin(1.0), (((teststate*)desc.state)->x));
}

void testnumerics()
{
  RUN_TEST(test_exp);
  RUN_TEST(test_sin);
}


int main()
{
    UNITY_BEGIN();
    testnumerics();
    UNITY_END();
    return 0;
}
