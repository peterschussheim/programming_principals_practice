// 6. In the Gaussian elimination example, replace the vector operations
// dot_product() and scale_and_add() with loops. Test, and comment on the
// clarity of the code

#include <algorithm>
#include <iostream>
#include <random>
#include <functional>
#include <limits>
#include <chrono>
#include <utility>
#include "Matrix.cpp"
#include "MatrixIO.cpp"

//------------------------------------------------------------------------------
// Simplify notation for two types used in this exercise:

typedef Numeric_lib::Matrix<double, 2> Matrix;
typedef Numeric_lib::Matrix<double, 1> Vector;
using Numeric_lib::Index;

//------------------------------------------------------------------------------
// Forward declarations:

Vector random_vector(Index n);
Matrix random_matrix(Index n);
void classical_elimination(Matrix& A, Vector& b);
Vector classical_gaussian_elimination(Matrix A, Vector b);
Vector back_substitution(const Matrix& A, const Vector& b);
Vector partial_gaussian_elimination(Matrix A, Vector b);

bool operator==(const Vector& lhs, const Vector& rhs);
Vector operator*(const Matrix& m, const Vector& u);

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

using Numeric_lib::Back_subst_failure;
using Numeric_lib::Elim_failure;

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
      // Replaces scale_and_add with raw loop
      if (A[j].slice(j).size() != A[i].slice(j).size()) {
        std::cerr << "wrong sizes for dot product\n";
      }

      for (Index k = j; k < n; ++k) { A(i, k) -= A(j, k) * mult; }

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
    // Replaces dot_product with raw loop
    double s = b(i);
    for (Index j = i + 1; j < n; ++j) { s -= A(i, j) * x(j); }
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
  std::cout << "A = " << std::defaultfloat << A << "\n\n";
  std::cout << "b = " << std::defaultfloat << b << "\n\n";
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

void ex6()
{
  double a1[][3] = {{1, -2, -3}, {0, 1, 2}, {-1, 1, 2}};
  double b1[] = {5, -8, 3};

  Matrix A(a1);
  Vector b(b1);

  std::cout << "A = " << std::defaultfloat << A << "\n\n";
  std::cout << "b = " << std::defaultfloat << b << "\n\n";
  try {
    Vector x = classical_gaussian_elimination(A, b);
    std::cout << "classical_gaussian_elimination solution is x = "
              << std::defaultfloat << x << '\n';
    Vector v = A * x;
    std::cout << "A*x = " << std::defaultfloat << v << '\n';
    if (v != b) std::cout << "error\n";
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

//------------------------------------------------------------------------------

int main()
{
  /*solve_random_system(3);
  std::cout <<
  "------------------------------------------------------------\n";
  solve_random_system(4);
  std::cout <<
  "------------------------------------------------------------\n";
  solve_random_system(5);
  std::cout <<
  "------------------------------------------------------------\n";*/

  ex6();  // as expected, elimination step fails
  std::cout << "------------------------------------------------------------\n";

  std::cout << "------------------------------------------------------------\n";

  return 0;
}

//------------------------------------------------------------------------------

Vector random_vector(Index n)
{
  Vector v(n);

  for (Index i = 0; i < n; ++i) v(i) = (1.0 * n * rand()) / RAND_MAX;

  return v;
}

//------------------------------------------------------------------------------

Matrix random_matrix(Index n)
{
  Matrix m(n, n);

  for (Index i = 0; i < m.dim1(); ++i) { m[i] = random_vector(n); }
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

Vector operator*(const Matrix& m, const Vector& u)
{
  const Index n = m.dim1();
  Vector v(n);
  for (Index i = 0; i < n; ++i) { v(i) = dot_product(m[i], u); }
  return v;
}

//------------------------------------------------------------------------------

// Allows comparison of two Vectors passed by reference
bool operator==(const Vector& lhs, const Vector& rhs)
{
  if (lhs.size() != rhs.size()) {
    throw std::runtime_error("both vectors must be same size!\n");
  }

  for (Index i = 0; i != lhs.dim1(); ++i) {
    if (lhs[i] != rhs[i]) return false;
  }

  return true;
}

bool operator!=(const Vector& lhs, const Vector& rhs) { return !(lhs == rhs); }

//------------------------------------------------------------------------------
