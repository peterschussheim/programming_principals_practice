// Implement
// Matrix<double> operator*(Matrix<double,2>&,Matrix<double>&); and
// Matrix<double,N> operator+(Matrix<double,N>&,Matrix<double,N>&)
// If you need to, look up the mathematical definitions in a textbook.

#include "Matrix.h"
#include <iostream>

namespace Numeric_lib {
  Matrix<double> operator*(Matrix<double, 2>& lhs, Matrix<double>& rhs);

  template<int N>
  Matrix<double, N> operator+(Matrix<double, N>& lhs, Matrix<double, N>& rhs);
}

//------------------------------------------------------------------------------

int main()
{
  try {
    // 2 dim matrix of doubles:
    Numeric_lib::Matrix<double, 2> m1(3, 4);
    m1 = {
        {00.1, 9, 3, 22.1},     // row 0
        {10.1, 0.2, 1.1, 9.1},  // row 1
        {50.1, 5.2, 5.1, 2.1}   // row 2
    };

    //// 1 dim matrix of doubles:
    // Numeric_lib::Matrix<double> m2{0.3, 1.2, 1, 0.2};

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
// Numeric_lib::Matrix<double> operator*(Numeric_lib::Matrix<double, 2>& lhs,
//                                      Numeric_lib::Matrix<double>& rhs)
//{
//  return Numeric_lib::Matrix<double>();
//}
//
////------------------------------------------------------------------------------
//
// template<int N>
// Numeric_lib::Matrix<double, N> operator+(Numeric_lib::Matrix<double, N>& lhs,
//                                         Numeric_lib::Matrix<double, N>& rhs)
//{
//}