/*
  Write a template function f() that adds the elements of one vector<T> to
  the elements of another; for example, f(v1,v2) should do v1[i]+=v2[i] for
  each element of v1
*/

#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

template<class T> void f(vector<T>& v1, vector<T>& v2)
{
  // handle unequal sizes of v1, v2
  int limit = (v1.size() < v2.size()) ? v1.size() : v2.size();
  for (int i = 0; i < limit; ++i) { v1[i] += v2[i]; }
}

int main()
{
  try {
    vector<int> v_one{2, 4, 6, 8};
    vector<int> v_two{1, 1, 1, 1};
    f(v_one, v_two);
    cout << "Result: ";
    for (auto i : v_one) cout << i << ' ';
    cout << '\n';

    vector<int> v_3{2, 2, 2, 2, 2, 2, 2, 2};
    vector<int> v_4{1, 1, 1, 1};
    f(v_3, v_4);
    cout << "Result: ";
    for (auto i : v_3) cout << i << ' ';
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