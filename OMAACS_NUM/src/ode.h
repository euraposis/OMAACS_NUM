/**
 * This Tpye represents the left hand side of the ode.
 * 
 * To make it problem independant, we use void* pointer (making things potentially unsafe)
 * 
 * the three function parameters are the return_field_pointer, state_pointer and x_pointer
*/
typedef void(left_hand_side)(void*, void*, double t);
/**
 * The propagator calculates result = x + dx * dt
*/
typedef void(propagator)(void*, void*, void*, double);


/**
 * represents a ode-system where state defines the state x, lhs_pointer is the pointer to the left-hand-side of the system and propagator
 * points to the implementation that proapgates the system 
*/
typedef struct ode{
  void* state;
  left_hand_side* lhs_pointer;
  propagator* propagator;
  unsigned int state_size;
} ode;
