# The R function that calls our compiled C routine, which in turn
# calls a compiled Fortran routine.
#
# You probably want to look at the C and Fortran implementation files:
#
#    hello_c.c: The wrapper C function that creates a function which can be used
#               with the .Call interface from R.
#
#    hello_f.f95: A Fortran file with a single subroutine that doubles a
#                 numeric array.
hello_fortran <- function(x = 1:10) {
  .Call("hello_fortran", as.numeric(x))
}
