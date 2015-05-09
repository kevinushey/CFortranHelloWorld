#include <R.h>
#include <Rinternals.h>

// By default, FORTRAN name mangling simply takes the subroutine name, and
// append an underscore to the end. So, given a subroutine named
// 'fortran_double', we need to let the compiler know that the symbol name
// would be made available as 'fortran_double_'.
//
// Furthermore, FORTRAN expects all arguments as 'references' (FORTRAN
// is pass-by-ref, as opposed to C's pass-by-value), and so the prototype should
// always include pointers.
//
// Note that if this were a C++ program, you would need an 'extern "C"' before
// this function's prototype.
void fortran_double_(double* data, int* sz);

// Functions which we want to use with R's `.Call` interface must take all
// parameters as a SEXP, and return a SEXP.
SEXP hello_fortran(SEXP valueSEXP)
{
  if (TYPEOF(valueSEXP) != REALSXP)
    error("Expecting a numeric vector");

  // Extract the actual data from the SEXP (the data as well as its size)
  int sz = Rf_length(valueSEXP);
  double* data = REAL(valueSEXP);

  // Call out to our FORTRAN routine.
  fortran_double_(data, &sz);

  // Return the result (note that we've modified our object in place)
  return valueSEXP;
}
