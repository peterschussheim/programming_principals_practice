// The function arguments f for a.apply(f) and apply(f,a) are different.
// 1) Write a triple() function for each and use each to triple the elements of
// an array { 1 2 3 4 5 }. DONE

// 2) Define a single triple() function that can be used for both
// a.apply(triple) and apply(triple,a).

// 3) Explain why it could be a bad idea to write every function to be used by
// apply() that way.

#include <iostream>
#include "Matrix.cpp"
#include "MatrixIO.cpp"
#include <string>
#include <fstream>

//------------------------------------------------------------------------------

void triple_inplace(int& x) { x *= 3; }
int triple_broadcast(int& n) { return n *= 3; }

//------------------------------------------------------------------------------

template<class T, class Q> void scale(T& n, Q s) { n *= s; }
template<class T, class Q> T scale(T& n, Q s) { return n * s; }

//------------------------------------------------------------------------------

int main()
{
  try {
    using Mat_int = Numeric_lib::Matrix<int>;
    Mat_int a(5);
    for (int i = 0; i < a.size(); ++i) { a(i) = i + 1; }  // fill 1D Matrix

    // call first to get the original data
    Mat_int b = apply(triple_broadcast, a);  // make a new Matrix
    a.apply(triple_inplace);                 // in-place

    std::cout << "triple_inplace: " << a.slice(0);
    std::cout << '\n';
    std::cout << "triple_broadcast: " << b.slice(0);

    Mat_int c(5);
    for (int i = 0; i < c.size(); ++i) { c(i) = i + 1; }  // fill 1D Matrix
    // TODO: Complete a generic triple function
    // Mat_intd = apply(scale)
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}

//------------------------------------------------------------------------------
