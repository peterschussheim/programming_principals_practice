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
typedef std::vector<std::vector<double>> vector_2d;

//------------------------------------------------------------------------------

vector_2d scale_and_add(const vector_2d& a, double c, const vector_2d& b);
double my_dot_product(const vector_2d& a, const vector_2d& b);
void classical_elim_array(vector_2d A, std::vector<double> b);
std::vector<double> back_substitution(const vector_2d& A,
                                      const std::vector<double>& b);

void solve_random_system(int n);  // solve n-dim system
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

vector_2d scale_and_add(const vector_2d& a, double c, const vector_2d& b)
{
  if (a.size() != b.size()) std::cerr << "wrong sizes for scale_and_add()\n";
  vector_2d res(a.size());
  for (int i = 0; i < a.size(); ++i) { res[i] += a[i] * c + b[i]; }
  return res;
}

//------------------------------------------------------------------------------

double my_dot_product(const vector_2d& a, const vector_2d& b)
{
  if (a.size() != b.size()) std::cerr << "sizes wrong for dot_product()\n";

  double sum = 0.0;
  for (int i = 0; i < a.size(); ++i) { sum += (a[i] * b[i]); }

  return sum;
}

//------------------------------------------------------------------------------

void classical_elim_array(vector_2d A, std::vector<double> b) {}

//------------------------------------------------------------------------------

std::vector<double> back_substitution(const vector_2d& A,
                                      const std::vector<double>& b)
{
  const int n = A.size();
  std::vector<double> x(n);
  for (int i = n - 1; i >= 0; --i) {
    // double s = b[i] - dot_product
  }
  return std::vector<double>();
}

//------------------------------------------------------------------------------

void solve_random_system(int n) {}

//------------------------------------------------------------------------------
