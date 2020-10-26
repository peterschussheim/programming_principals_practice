// 4) Get the Gaussian elimination program to work; that is, complete it, get it
// to compile, and test it with a simple example.
//
// 5) Try the Gaussian elimination program with A=={ {0 1} {1 0} } and b=={ 5
// 6 } and watch it fail. Then, try elim_with_partial_pivot()

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
using Numeric_lib::dot_product;
using Numeric_lib::Index;
using Numeric_lib::scale_and_add;

//------------------------------------------------------------------------------
// Forward declarations:

Vector random_vector(Index n);
Matrix random_matrix(Index n);
void classical_elimination(Matrix& A, Vector& b);
Vector classical_gaussian_elimination(Matrix A, Vector b);
Vector back_substitution(const Matrix& A, const Vector& b);
void elim_with_partial_pivot(Matrix& A, Vector& b);
Vector partial_gaussian_elimination(Matrix A, Vector b);
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

void elim_with_partial_pivot(Matrix& A, Vector& b)
{
  const Index n = A.dim1();
  for (Index j = 0; j < n; ++j) {
    Index pivot_row = j;

    // look for suitable pivot:
    for (Index k = j + 1; k < n; ++k) {
      if (std::abs(A(k, j)) > std::abs(A(pivot_row, j))) pivot_row = k;

      // swap the rows if we found a better pivot:
      if (pivot_row != j) {
        A.swap_rows(j, pivot_row);
        std::swap(b(j), b(pivot_row));
      }

      // elimination:
      for (Index i = j + 1; i < n; ++i) {
        const double pivot = A(j, j);
        if (pivot == 0) throw std::runtime_error("can't solve: pivot==0");
        const double mult = A(i, j) / pivot;
        A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
        b(i) -= mult * b(j);
      }
    }
  }
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

void solve_random_system_partial_pivot(Index n)
{
  Matrix A = random_matrix(n);
  Vector b = random_vector(n);
  std::cout << "A = " << std::defaultfloat << A << "\n\n";
  std::cout << "b = " << std::defaultfloat << b << "\n\n";
  try {
    Vector x = partial_gaussian_elimination(A, b);
    std::cout << "partial_gaussian_elimination solution is x = "
              << std::defaultfloat << x << '\n';
    Vector v = A * x;
    std::cout << "A*x = " << std::defaultfloat << v << '\n';
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

//------------------------------------------------------------------------------

void ex5()
{
  double a1[][2] = {{0, 1}, {1, 0}};
  double b1[] = {5, 6};

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

void ex5_partial_pivot()
{
  double a1[][2] = {{0, 1}, {1, 0}};
  double b1[] = {5, 6};

  Matrix A(a1);
  Vector b(b1);

  std::cout << "A = " << A << "\n\n";
  std::cout << "b = " << b << "\n\n";
  try {
    Vector x = partial_gaussian_elimination(A, b);
    std::cout << "partial_gaussian_elimination solution is x = " << x << '\n';
    Vector v = A * x;
    std::cout << "A*x = " << v << '\n';
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

//------------------------------------------------------------------------------

int main()
{
  /*solve_random_system(3);
  std::cout << "------------------------------------------------------------\n";
  solve_random_system(4);
  std::cout << "------------------------------------------------------------\n";
  solve_random_system(5);
  std::cout <<
  "------------------------------------------------------------\n";*/

  ex5();  // as expected, elimination step fails
  std::cout << "------------------------------------------------------------\n";
  ex5_partial_pivot();  // works, no problems
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
// Could not get random vector generator written below to work correctly.
// Repeatidly received nand results
// Vector random_vector(Index n)
//{
//  Vector v(n);
//  std::default_random_engine ran{};  // generates integers
//
//  // maps ints into doubles in [0:max)
//  std::uniform_real_distribution<> ureal{0,
//  std::numeric_limits<double>::max()};
//
//  for (Index i = 0; i < n; ++i) v(i) = ureal(ran);
//  return v;
//}

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

Vector partial_gaussian_elimination(Matrix A, Vector b)
{
  elim_with_partial_pivot(A, b);
  return back_substitution(A, b);
}

//------------------------------------------------------------------------------