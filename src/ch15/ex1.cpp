#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

/*
  Here is another way of defining a factorial function:

  int fac(int n) { return n>1 ? n*fac(n–1) : 1; } // factorial n!

  It will do fac(4) by first deciding that since 4>1 it must be 4*fac(3) , and
  that’s obviously 4*3*fac(2) , which again is 4*3*2*fac(1) , which is 4*3*2*1 .
  Try to see that it works. A function that calls itself is said to be
  recursive. The alternative implementation in §15.5 is called iterative because
  it iter-ates through the values (using while ). Verify that the recursive
  fac() works and gives the same results as the iterative fac() by calculating
  the factorial of 0, 1, 2, 3, 4, up until and including 20. Which
  implementation of fac() do you prefer, and why?

  So, both implementations produce identical and correct results, up to and
  including 19.  When either implementation calculates the 20th factorial,
  the result is -2102132736 which is the int type's min value possible.

  In terms of a preference, if we are talking about a preference for the most
  efficient implementation, neither would fit that description as both are
  highly inefficent.  If we narrow the comparison to these two functions, the
  iterative implementation is more efficient since it avoids the problem of
  recurisve implementation's and their high stack frame cost.

  To clarify what I mean, recursive functions 'load up' the stack with recursive
  calls, which when the base case is reached in the execution, the stack frames
  pop off, providing the callee with the result.  The iterative implementation
  doesn't have this problem as it uses a while loop which also enables compiler
  optimizations.

  If we look at the question from the point of readibility, the recursive
  function is much more readible in my opinion due to the straightforward
  way it is expressed in code, very close to the mathmatical exprerssion.
*/

int fac(int n) { return n > 1 ? n * fac(n - 1) : 1; }

int factorial_iterative(int n)
{
  int r = 1;
  while (n > 1) {
    r *= n;
    --n;
  }
  return r;
}

int main()
{
  try {
    int fac_4 = fac(4);
    cout << "fac(4) = " << fac_4 << '\n';

    int fac_5 = fac(5);
    cout << "fac(5) = " << fac_5 << '\n';

    int fact_19 = fac(19);
    cout << "Factorial(19) = " << fact_19 << '\n';

    int fact_20 = fac(20);
    cout << "Factorial(20) = " << fact_20 << '\n';

    int iterative_fac_19 = factorial_iterative(19);
    cout << "factorial_iterative(19): " << iterative_fac_19 << '\n';

    int iterative_fac_20 = factorial_iterative(20);
    cout << "factorial_iterative(20): " << iterative_fac_20 << '\n';

    keep_window_open("~");
    return 0;
  }
  catch (exception& e) {
    cerr << e.what();
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "Unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}