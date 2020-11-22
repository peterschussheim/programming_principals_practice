// Implement
// Matrix<double> operator*(Matrix<double,2>&,Matrix<double>&); and
// Matrix<double,N> operator+(Matrix<double,N>&,Matrix<double,N>&)
// If you need to, look up the mathematical definitions in a textbook.

#include "Matrix.h"
#include <iostream>

namespace Numeric_lib {
  Matrix<double> operator*(Matrix<double, 2>& m, Matrix<double>& v)
  {
    if (m.dim1() != v.size() || m.dim2() != v.size()) {
      error("matric vector multiplication dimension mismatch");
    }
    Matrix<double> res(v.size());
    for (Index i = 0; i < res.size(); ++i) { res(i) = dot_product(m[i], v); }
    return res;
  }

  template<int N>
  Matrix<double, N> operator+(Matrix<double, N>& m1, Matrix<double, N>& m2)
  {
    // use MUST ensure dimensions of m1 and m2 match

    if (m1.size() != m2.size()) {
      error("matrix addition requires identical dimension");
    }

    Matrix<double, n> m3 = m1;

    double* ptr_2 = m3.data();
    const double* ptr_3 = m2.data();

    for (Index i = 0; i < m3.size(); ++i) { ptr_3[i] += ptr_2[i]; }

    return m3;
  }
}

//------------------------------------------------------------------------------

int main()
{
  try {
    // 2 dim matrix of doubles:
    double m2_arr[][4] = {
        {00.1, 9, 3, 22.1},     // row 0
        {10.1, 0.2, 1.1, 9.1},  // row 1
        {50.1, 5.2, 5.1, 2.1}   // row 2
    };

    Numeric_lib::Matrix<double, 2> m2 = m2_arr;
    double v_arr[] = {221.9, 2.1, 44.3};
    Numeric_lib::Matrix<double> v = v_arr;
    Numeric_lib::Matrix<double> m2_v = m2 * v;
    // TODO: Complete remainder of tests and move on to next exercise or ch.

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
