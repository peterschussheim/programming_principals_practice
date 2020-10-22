// Do exercise 1 again, but with function objects, rather than functions.
// Hint: Matrix.h contains examples.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Matrix.cpp"
#include "MatrixIO.cpp"

template<class T> struct Triple_inplace {
  void operator()(T& a) { a *= 3; }
};
template<class T> struct Triple_fortran {
  T operator()(T& a) { return a *= 3; }
};
template<class T> struct Triple {
  T operator()(T& a) { return a *= 3; }
};

int main()
{
  try {
    using Mat_int = Numeric_lib::Matrix<int>;
    Mat_int a(5);
    for (int i = 0; i < a.size(); ++i) { a(i) = i + 1; }  // fill 1D Matrix

    // call first to get the original data
    Mat_int b = apply(Triple_fortran<int>(), a);  // make a new Matrix
    a.apply(Triple_inplace<int>());               // in-place

    std::cout << "Triple_inplace: " << std::setw(10) << std::right << std::right
              << a.slice(0);
    std::cout << '\n';
    std::cout << "Triple_fortran: " << std::setw(10) << std::right << std::right
              << b.slice(0) << '\n';

    Mat_int c(5);
    for (int i = 0; i < c.size(); ++i) { c(i) = i + 1; }  // fill 1D Matrix

    Mat_int d = apply(Triple<int>(), c);
    c.apply(Triple<int>());
    std::cout << "Triple: " << std::setw(10) << std::right << c.slice(0)
              << '\n';
    std::cout << "Triple (broadcast): " << std::setw(10) << std::right
              << d.slice(0) << '\n';

    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
