/*
  Write a template function that takes a vector<T> vt and a vector<U> vu as
  arguments and returns the sum of all vt[i]*vu[i].
*/

#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

template<class T, class U> T f(vector<T>& vt, vector<U>& vu)
{
  T sum = 0;  // FIX THIS!
  // handle unequal sizes of vt, vu
  int limit = (vt.size() < vu.size()) ? vt.size() : vu.size();
  for (int i = 0; i < limit; ++i) { sum += vt[i] * vu[i]; }

  return sum;
}

int main()
{
  try {
    vector<int> v_int{1, 2, 3, 4, 3, 2, 1};
    vector<double> v_dbl{0.2, 1.2, 3.3, 99.08, 3.3, 4094.4};

    int s = f(v_int, v_dbl);
    cout << "Result: " << s;

    cout << '\n';
    keep_window_open();
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