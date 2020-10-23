// Get the Gaussian elimination program to work; that is, complete it, get it
// to compile, and test it with a simple example.

#include <algorithm>
#include <iostream>
#include <random>
#include <limits>
#include "Matrix.cpp"
#include "MatrixIO.cpp"

//------------------------------------------------------------------------------
// Simplify notation for two types used in this exercise:

typedef Numeric_lib::Matrix<double, 2> Matrix;
typedef Numeric_lib::Matrix<double, 1> Vector;
using Numeric_lib::Index;

//------------------------------------------------------------------------------
// Forward declarations:

void classical_elimination(Matrix& A, Vector& b);
Vector classical_gaussian_elimination(Matrix A, Vector b);
Vector back_substitution(const Matrix& A, const Vector& b);

//------------------------------------------------------------------------------

namespace Numeric_lib {
  struct Elim_failure : std::runtime_error {
    Elim_failure(const Index i)
        : std::runtime_error("Elimination failure at index " +
                             std::to_string(i))
    {
    }
  };
  struct Back_subst_failure : std::runtime_error {
    Back_subst_failure(const Index i)
        : std::runtime_error("Back substitution failure at index " +
                             std::to_string(i))
    {
    }
  };
}  // Numeric_lib

using Numeric_lib::Elim_failure;

using Numeric_lib::Back_subst_failure;

//------------------------------------------------------------------------------

Vector operator*(const Matrix& m, const Vector& u)
{
  const Index n = m.dim1();
  Vector v(n);
  for (Index i = 0; i < n; ++i) { v(i) = dot_product(m[i], u); }
  return v;
}

//------------------------------------------------------------------------------

Vector random_vector(Index n)
{
  Vector v(n);
  std::default_random_engine ran{};  // generates integers

  // maps ints into doubles in [0:max)
  std::uniform_real_distribution<> ureal{0, std::numeric_limits<double>::max()};

  for (Index i = 0; i < n; ++i) v(i) = ureal(ran);
  return v;
}

//------------------------------------------------------------------------------

Matrix random_matrix(Index n)
{
  Matrix m(n, n);
  std::default_random_engine ran{};
  std::uniform_real_distribution<> ureal{0, std::numeric_limits<double>::max()};

  for (Index i = 0; i < m.dim1(); ++i) {
    for (Index j = 0; j < m.dim2(); ++j) { m(i, j) = ureal(ran); }
  }
  return m;
}

//------------------------------------------------------------------------------

// Make copies of inputs A and b (via call by value), call fn to solve the
// system, and calculate the result by back subsitution.
Vector classical_gaussian_elimination(Matrix A, Vector b)
{
  classical_elimination(A, b);
  return back_substitution(A, b);
}

//------------------------------------------------------------------------------

void classical_elimination(Matrix& A, Vector& b)
{
  const Index n = A.dim1();
  // traverse from 1st column to the next-to-last (n - 1)
  // filling zeros intal all elems under the diagonal:
  for (Index j = 0; j < n - 1; ++j) {
    // the pivot is the element that lies on the diagonal of the current row
    // and must not be zero since we are dividing by it.
    const double pivot = A(j, j);
    if (pivot == 0) throw Elim_failure(j);

    // fill zeros into each elem under diagonal of the ith row:
    for (Index i = j + 1; i < n; ++i) {
      const double mult = A(i, j) / pivot;
      A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
      b(i) -= mult * b(j);  // make the corresponding change to b
    }
  }
}

//------------------------------------------------------------------------------

Vector back_substitution(const Matrix& A, const Vector& b)
{
  const Index n = A.dim1();
  Vector x(n);

  for (Index i = n - 1; i >= 0; --i) {
    double s = b(i) - dot_product(A[i].slice(i + 1), x.slice(i + 1));

    if (double m = A(i, i))
      x(i) = s / m;
    else
      throw Back_subst_failure(i);
  }

  return x;
}

//------------------------------------------------------------------------------

void solve_random_system(Index n)
{
  Matrix A = random_matrix(n);
  Vector b = random_vector(n);
  std::cout << "A = " << std::defaultfloat << A << '\n';
  std::cout << "b = " << std::defaultfloat << b << '\n';
  try {
    Vector x = classical_gaussian_elimination(A, b);
    std::cout << "classical elim solution is x = " << std::defaultfloat << x
              << '\n';
    Vector v = A * x;
    std::cout << "A*x = " << std::defaultfloat << v << '\n';
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

//------------------------------------------------------------------------------

int main()
{
  solve_random_system(3);

  // TODO: write elim_with_partial_pivot(Matrix& A, Vector& b);
  // TODO: figure out the reason for - -nan(ind) results
  return 0;
}
