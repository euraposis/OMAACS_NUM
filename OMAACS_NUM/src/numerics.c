#include "numerics.h"
#include <stdlib.h>

void explicite_euler_cauchy(ode* ode_sys, double t, double dt)
{
  void* direction = malloc(ode_sys->state_size);
  ode_sys->lhs_pointer(direction, ode_sys->state, t);
  void* newstate = malloc(ode_sys->state_size);
  ode_sys->propagator(newstate, ode_sys->state, direction, dt);
  free(ode_sys->state);
  ode_sys->state = newstate;
  free(direction);
}