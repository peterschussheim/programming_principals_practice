/*
  Try your solution to exercise 2 with some Numbers.
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include "Utils.h"

using namespace std;

//------------------------------------------------------------------------------

template<class T>
class Number {
  T value;

public:
  Number() : value{0} {}     // default constructor
  Number(T n) : value{n} {}  // initialize member

  Number& operator=(const T& v)  // copy assignment
  {
    v = value;
    return *this;
  }

  const T get() const;
};

//------------------------------------------------------------------------------

template<class T>
const T Number<T>::get() const
{
  return value;
}

//------------------------------------------------------------------------------

template<class T>
Number<T> operator+(const Number<T>& lhs, const Number<T>& rhs)
{
  return {lhs.get() + rhs.get()};
}

//------------------------------------------------------------------------------

template<class T>
Number<T> operator-(const Number<T>& lhs, const Number<T>& rhs)
{
  return {lhs.get() - rhs.get()};
}

//------------------------------------------------------------------------------

template<class T>
Number<T> operator*(const Number<T>& lhs, const Number<T>& rhs)
{
  return {lhs.get() * rhs.get()};
}

//------------------------------------------------------------------------------

template<class T>
Number<T> operator/(const Number<T>& lhs, const Number<T>& rhs)
{
  return {lhs.get() / rhs.get()};
}

//------------------------------------------------------------------------------

// I don't think this is the right idea to solve narrowing of different types
template<class T, class U>
Number<T> operator%(const Number<T>& lhs, const Number<U>& rhs)
{
  int lhs_int = narrow_cast<int>(lhs.get());
  int rhs_int = narrow_cast<int>(rhs.get());
  if (rhs_int == 0) error("%: divide by zero");

  Number<T> remainder = lhs_int % rhs_int;
  return remainder;
}

//------------------------------------------------------------------------------

template<class T>
std::ostream& operator<<(std::ostream& os, Number<T>& i)
{
  os << i.get();
  return os;
}

template<class T, class U>
typename std::common_type<T, U>::type f(vector<Number<T>>& vt,
                                        vector<Number<U>>& vu)
{
  typename std::common_type<T, U>::type sum = 0;

  int limit = (vt.size() < vu.size()) ? vt.size() : vu.size();
  for (int i = 0; i < limit; ++i) { sum += vt[i].get() * vu[i].get(); }

  return sum;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
  os << "{";
  for (int i = 0; i < v.size() - 1; ++i) { os << ' ' << v[i].get() << ','; }

  os << ' ' << v[v.size() - 1].get() << " }";
  return os;
}

int main()
{
  try {
    vector<Number<int>> v_int;
    for (int i = 1; i < 10; ++i) { v_int.push_back(Number<int>{i * 25}); }

    vector<Number<double>> v_dbl;
    for (int i = 1; i < 10; ++i) { v_dbl.push_back(Number<double>{i * 0.25}); }

    cout << "v_int: " << v_int << '\n';
    cout << "v_dbl: " << v_dbl << '\n';

    Number<double> s = f(v_int, v_dbl);
    Number<int> int_sum = f(v_int, v_dbl);
    cout << "Number<double> f(v_int, v_dbl): " << s << '\n';
    cout << "Number<int> f(v_int, v_dbl): " << int_sum << '\n';

    cout << '\n';

    vector<Number<int>> v_int_2{1, 2, 3, 4, 3, 2, 1};
    vector<Number<double>> v_dbl_2;
    for (int i = 0; i < v_int_2.size(); ++i) {
      v_dbl_2.push_back(Number<double>{v_int_2[i].get() * 0.3});
    }

    Number<double> s_2 = f(v_int_2, v_dbl_2);
    Number<int> int_sum_2 = f(v_int_2, v_dbl_2);
    cout << "v_int_2: " << v_int_2 << '\n';
    cout << "v_dbl_2: " << v_dbl_2 << '\n';

    cout << "Number<double> f(v_int_2, v_dbl_2): " << s_2 << '\n';
    cout << "Number<int> f(v_int_2, v_dbl_2): " << int_sum_2 << '\n';

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