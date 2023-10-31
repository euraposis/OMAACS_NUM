#ifndef OMAACS_NUM_NUMERICS_H
#define OMAACS_NUM_NUMERICS_H


#include "ode.h"

void explicite_euler_cauchy(ode* ode_sys, double t, double dt);

void runge_kutta_4(ode* ode_sys, double t, double dt);

#endif