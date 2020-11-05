// Implement
// Matrix<double> operator*(Matrix<double,2>&,Matrix<double>&); and
// Matrix<double,N> operator+(Matrix<double,N>&,Matrix<double,N>&)
// If you need to, look up the mathematical definitions in a textbook.

#include "Matrix.cpp"
#include <iostream>

namespace Numeric_lib {
  Matrix<double> operator*(Matrix<double, 2>&, Matrix<double>&);

  template<int N>
  Matrix<double, N> operator+(Matrix<double, N>&, Matrix<double, N>&);
}

//------------------------------------------------------------------------------

int main()
{
  try {
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    return 2;
  }
}

//------------------------------------------------------------------------------

// Multiplication operator for Matrix of doubles, 2 dimensions and a
// one of one dimension
Numeric_lib::Matrix<double> operator*(Numeric_lib::Matrix<double, 2>&,
                                      Numeric_lib::Matrix<double>&)
{
  return Matrix<double>();
}

//------------------------------------------------------------------------------