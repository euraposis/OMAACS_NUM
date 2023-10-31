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

void runge_kutta_4(ode* ode_sys, double t, double dt)
{
  // calculate k1
  void* k1 = malloc(ode_sys->state_size);
  ode_sys->lhs_pointer(k1, ode_sys->state, t);

  // calculate k2
  void* state_plus_k1_dt_half = malloc(ode_sys->state_size);
  ode_sys->propagator(state_plus_k1_dt_half, ode_sys->state, k1, dt/2);
  void* k2 = malloc(ode_sys->state_size);
  ode_sys->lhs_pointer(k2, state_plus_k1_dt_half, t + (dt/2));
  free(state_plus_k1_dt_half);

  // calculate k3
  void* state_plus_k2_dt_half = malloc(ode_sys->state_size);
  ode_sys->propagator(state_plus_k2_dt_half, ode_sys->state, k2, dt/2);
  void* k3 = malloc(ode_sys->state_size);
  ode_sys->lhs_pointer(k3, state_plus_k2_dt_half, t + (dt/2));
  free(state_plus_k2_dt_half);

  // calculate k4
  void* state_plus_k3_dt = malloc(ode_sys->state_size);
  ode_sys->propagator(state_plus_k3_dt, ode_sys->state, k3, dt);
  void* k4 = malloc(ode_sys->state_size);
  ode_sys->lhs_pointer(k4, state_plus_k3_dt, t + dt);
  free(state_plus_k3_dt);

  // update state
  ode_sys->propagator(ode_sys->state, ode_sys->state, k1, dt/6);
  ode_sys->propagator(ode_sys->state, ode_sys->state, k2, dt/3);
  ode_sys->propagator(ode_sys->state, ode_sys->state, k3, dt/3);
  ode_sys->propagator(ode_sys->state, ode_sys->state, k4, dt/6);
  free(k1);
  free(k2);
  free(k3);
  free(k4);
}