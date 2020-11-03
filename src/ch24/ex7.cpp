// 7. Rewrite the Gaussian elimination program without using the Matrix li-
// brary; that is, use built-in arrays or vector s instead of Matrix es.

#include <iostream>
#include <vector>
#include <string>

//------------------------------------------------------------------------------

struct Elim_failure : std::runtime_error {
  Elim_failure(const int i)
      : std::runtime_error("Elimination failure at index " + std::to_string(i))
  {
  }
};
struct Back_subst_failure : std::runtime_error {
  Back_subst_failure(const int i)
      : std::runtime_error("Back substitution failure at index " +
                           std::to_string(i))
  {
  }
};

//------------------------------------------------------------------------------

typedef std::vector<std::vector<double>> Matrix;
typedef std::vector<double> Vector;

//------------------------------------------------------------------------------

void classical_elimination(Matrix& A, Vector& b);
Vector classical_gaussian_elimination(Matrix A, Vector b);
Vector back_substitution(Matrix& A, Vector& b);

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, Vector& v)
{
  os << '{';
  for (int i = 0; i != v.size(); ++i) {
    os << "  ";
    os << v[i];
    os << "  ";
  }
  os << '}';
  return os;
}

std::ostream& operator<<(std::ostream& os, Matrix& m)
{
  os << "{\n";
  for (int i = 0; i != m.size(); ++i) { os << m[i] << '\n'; }
  os << "}";
  return os;
}

//------------------------------------------------------------------------------

int main()
{
  try {
    Matrix A = {{1, -2, -3}, {0, 1, 2}, {-1, 1, 2}};
    Vector b = {5, -8, 3};

    // TODO: debug program, current output is incorrect
    std::cout << "A:\n" << A << '\n';
    std::cout << "\nb:\n" << b << '\n';

    Vector x = classical_gaussian_elimination(A, b);
    std::cout << "\nx:\n" << x << '\n';

    // Vector v = A * x;
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

Vector classical_gaussian_elimination(Matrix A, Vector b)
{
  classical_elimination(A, b);
  return back_substitution(A, b);
}

//------------------------------------------------------------------------------

void classical_elimination(Matrix& A, Vector& b)
{
  const int n = A.size();

  for (int j = 0; j < n - 1; ++j) {
    const double pivot = A[j][j];
    if (pivot == 0) throw Elim_failure(j);

    for (int i = j + 1; i < n; ++i) {
      const double mult = A[i][j] / pivot;
      for (int k = j; k < n; ++k) { A[i][k] -= A[j][k] * mult; }
      b[i] -= mult * b[j];
    }
  }
}

//------------------------------------------------------------------------------

Vector back_substitution(Matrix& A, Vector& b)
{
  const int n = A.size();
  Vector x(n);
  for (int i = n - 1; i >= 0; --i) {
    double s = b[i];
    for (int j = i + 1; j < n; ++j) { s -= A[i][j] * x[j]; }
    if (double m = A[i][i]) { x[i] = s / m; }
    else {
      throw Back_subst_failure(i);
    }
  }
  return x;
}

//------------------------------------------------------------------------------
