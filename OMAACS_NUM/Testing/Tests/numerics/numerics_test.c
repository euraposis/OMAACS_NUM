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
  long double x;
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
void test_exp_euler(){
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
  free(desc.state);
}

/**
 * setup the ode d²y/dt² = x;
 * y(0) =  0
 * this should be a sin function
*/

struct statespace{
  long double x;
  long double v;
};

void statespace_prop(void* result, void* state, void* direction, double dt)
{
  ((struct statespace*)result)->x = ((struct statespace*)state)->x + ((struct statespace*)direction)->x * dt;
  ((struct statespace*)result)->v = ((struct statespace*)state)->v + ((struct statespace*)direction)->v * dt;
}

void sin_lhs(void* res, void* state, double t)
{
  ((struct statespace*)res)->x = ((struct statespace*)state)->v;
  ((struct statespace*)res)->v = -((struct statespace*)state)->x;
}

void test_sin_euler()
{
  ode desc;
  desc.state = malloc(sizeof(struct statespace));
  ((struct statespace*)desc.state)->x = 0.0;
  ((struct statespace*)desc.state)->v = 1.0;
  desc.lhs_pointer = sin_lhs;
  desc.propagator = statespace_prop;
  desc.state_size = sizeof(struct statespace);

  FILE* out_file = fopen("../output_data/test_sin.dat", "w");

  if(out_file == NULL)
  {
    TEST_FAIL_MESSAGE("Could not open file");
    return;
  }

  long double a = 0;
  long double b = 6.28318530718 * 5;

  unsigned int n = 1000;

  long double h = (b - a) / n;

  for(unsigned int i = 0; i < n; i++)
  {
    explicite_euler_cauchy(&desc, 0, h);
    fprintf(out_file, "%Lf %Lf\n", i * h, ((teststate*)desc.state)->x);
  }
  fclose(out_file);
  TEST_ASSERT_DOUBLE_WITHIN(0.1, sin(b), (((teststate*)desc.state)->x)); // we really relax the epsilon here as euler cuchy is baaad
  free(desc.state);
}

void test_sin_rk4()
{
  ode desc;
  desc.state = malloc(sizeof(struct statespace));
  ((struct statespace*)desc.state)->x = 0.0;
  ((struct statespace*)desc.state)->v = 1.0;
  desc.lhs_pointer = sin_lhs;
  desc.propagator = statespace_prop;
  desc.state_size = sizeof(struct statespace);

  FILE* out_file = fopen("../output_data/test_sin_rk4.dat", "w");

  if(out_file == NULL)
  {
    TEST_FAIL_MESSAGE("Could not open file");
    return;
  }

  long double a = 0;
  long double b = 6.28318530718 * 5;

  unsigned int n = 1000;

  long double h = (b - a) / n;

  for(unsigned int i = 0; i < n; i++)
  {
    runge_kutta_4(&desc, 0, h);
    fprintf(out_file, "%Lf %Lf\n", i * h, ((teststate*)desc.state)->x);
  }
  fclose(out_file);
  TEST_ASSERT_DOUBLE_WITHIN(0.001, sin(b), (((teststate*)desc.state)->x));
  free(desc.state);
}

void testnumerics()
{
  RUN_TEST(test_exp_euler);
  RUN_TEST(test_sin_euler);
  RUN_TEST(test_sin_rk4);
}


int main()
{
    UNITY_BEGIN();
    testnumerics();
    UNITY_END();
    return 0;
}
