/*
  Write a template function that takes a vector<T> vt and a vector<U> vu as
  arguments and returns the sum of all vt[i]*vu[i].
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include "Utils.h"

using namespace std;

template<class T, class U>
typename common_type<T, U>::type f(vector<T>& vt, vector<U>& vu)
{
  // Need to understand how common_type works.
  typename common_type<T, U>::type sum = 0;

  int limit = (vt.size() < vu.size()) ? vt.size() : vu.size();
  for (int i = 0; i < limit; ++i) { sum += vt[i] * vu[i]; }

  return sum;
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
  os << "{";
  for (int i = 0; i < v.size() - 1; ++i) { os << ' ' << v[i] << ','; }

  os << ' ' << v[v.size() - 1] << " }";
  return os;
}

int main()
{
  try {
    vector<int> v_int{1, 2, 3, 4, 3, 2, 1};
    vector<double> v_dbl;
    for (int i = 0; i < v_int.size(); ++i) { v_dbl.push_back(v_int[i] * 0.25); }

    double s = f(v_int, v_dbl);
    int int_sum = f(v_int, v_dbl);
    cout << "v_int: " << v_int << '\n';
    cout << "v_dbl: " << v_dbl << '\n';

    cout << "double f(v_int, v_dbl): " << s << '\n';
    cout << "int f(v_int, v_dbl): " << int_sum << '\n';

    cout << '\n';

    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}