// The function arguments f for a.apply(f) and apply(f,a) are different.
// 1) Write a triple() function for each and use each to triple the elements of
// an array { 1 2 3 4 5 }. DONE

// 2) Define a single triple() function that can be used for both
// a.apply(triple) and apply(triple,a). DONE

// 3) Explain why it could be a bad idea to write every function to be used by
// apply() that way. DONE

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

// single triple() function that can be used for both
// a.apply(triple) and apply(triple,a).
// Note that this style of function is not ideal as it generates potentially
// unnecessary operations. For example, if our apply function expects a void
// function f(), using the single triple function costs an extra machine op.
int triple(int& n) { return n *= 3; }

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
    std::cout << "triple_broadcast: " << b.slice(0) << '\n';

    Mat_int c(5);
    for (int i = 0; i < c.size(); ++i) { c(i) = i + 1; }  // fill 1D Matrix

    Mat_int d = apply(triple, c);
    c.apply(triple);
    std::cout << "triple: " << c.slice(0) << '\n';
    std::cout << "triple broadcast: " << d.slice(0) << '\n';

    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}

//------------------------------------------------------------------------------
