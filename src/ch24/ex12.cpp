// Implement
// Matrix<double> operator*(Matrix<double,2>&,Matrix<double>&); and
// Matrix<double,N> operator+(Matrix<double,N>&,Matrix<double,N>&)
// If you need to, look up the mathematical definitions in a textbook.

#include "Matrix.h"
#include "MatrixIO.h"
#include <iostream>

namespace Numeric_lib {
  Matrix<double> operator*(Matrix<double, 2>& m, Matrix<double>& v)
  {
    if (m.dim1() != v.size() || m.dim2() != v.size()) {
      error("matrix vector multiplication dimension mismatch");
    }
    Matrix<double> res(v.size());
    for (Index i = 0; i < res.size(); ++i) { res(i) = dot_product(m[i], v); }
    return res;
  }

  template<int N>
  Matrix<double, N> operator+(const Matrix<double, N>& m1,
                              const Matrix<double, N>& m2)
  {
    // use MUST ensure dimensions of m1 and m2 match

    if (m1.size() != m2.size()) {
      error("matrix addition requires identical dimension");
    }

    Matrix<double, N> m3 = m1;

    double* ptr_3 = m3.data();
    const double* ptr_2 = m2.data();

    for (Index i = 0; i < m3.size(); ++i) { ptr_3[i] += ptr_2[i]; }

    return m3;
  }
}

//------------------------------------------------------------------------------

int main()
{
  try {
    // 2 dim matrix of doubles:
    double m2_arr[][3] = {
        {00.1, 9, 3},      // row 0
        {10.1, 0.2, 1.1},  // row 1
        {50.1, 5.2, 5.1}   // row 2
    };

    Numeric_lib::Matrix<double, 2> m2 = m2_arr;
    double v_arr[] = {221.9, 2.1, 44.3};
    Numeric_lib::Matrix<double> v = v_arr;
    Numeric_lib::Matrix<double> m2_v = m2 * v;
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\nmultiplication:\n";
    std::cout << m2 << "\n *\n" << v << "\n =\n" << m2_v << '\n';

    double v_21_arr[] = {1, 2, 3};
    double v_22_arr[] = {10, 20, 30};
    Numeric_lib::Matrix<double> v21 = v_21_arr;
    Numeric_lib::Matrix<double> v22 = v_22_arr;
    Numeric_lib::Matrix<double> v23 = v21 + v22;
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\naddition:\n";
    std::cout << '\n' << v21 << "\n +\n" << v22 << "\n =\n" << v23 << '\n';

    double m21_arr[][3] = {{111, 112, 113}, {121, 122, 123}, {131, 132, 133}};
    double m22_arr[][3] = {{211, 212, 213}, {221, 222, 223}, {231, 232, 233}};
    Numeric_lib::Matrix<double, 2> m21 = m21_arr;
    Numeric_lib::Matrix<double, 2> m22 = m22_arr;
    Numeric_lib::Matrix<double, 2> m23 = m21 + m22;

    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\n2-dimension matrix addition:\n";
    std::cout << '\n' << m21 << "\n +\n" << m22 << "\n =\n" << m23 << '\n';

    Numeric_lib::Matrix<double, 3> m31(3, 3, 3);
    const int THREE_DIM = 3;
    for (int i = 0; i < THREE_DIM; ++i) {
      for (int j = 0; j < THREE_DIM; ++j) {
        for (int k = 0; k < THREE_DIM; ++k) {
          m31(i, j, k) = 100 * (i + 1) + 10 * (j + 1) + k + 1;
        }
      }
    }

    Numeric_lib::Matrix<double, 3> m32(3, 3, 3);
    for (int i = 0; i < THREE_DIM; ++i) {
      for (int j = 0; j < THREE_DIM; ++j) {
        for (int k = 0; k < THREE_DIM; ++k) {
          m32(i, j, k) = 300 + 100 * (i + 1) + 10 * (j + 1) + k + 1;
        }
      }
    }

    Numeric_lib::Matrix<double, 3> m33 = m31 + m32;

    std::cout << "\n-----------------------------------------------------\n";
    for (int i = 0; i < THREE_DIM; ++i) { std::cout << m31[i] << '\n'; }
    // TODO: Complete remainder of this exercise
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
