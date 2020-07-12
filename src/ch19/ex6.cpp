/*
  Repeat the previous exercise, but with a class Number<T> where T can be
  any numeric type. Try adding % to Number and see what happens when
  you try to use % for Number<double> and Number<int>
*/

#include <iostream>
#include <stdexcept>

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

template<class T>
Number<T> operator%(const Number<T>& lhs, const Number<T>& rhs)
{
  return {lhs.get() % rhs.get()};
}

template<class T>
std::ostream& operator<<(std::ostream& os, Number<T>& i)
{
  os << i.get();
  return os;
}

int main()
{
  try {
    Number<int> my_int{100};
    Number<int> my_default_int;
    Number<int> sum = my_int + Number<int>{99};
    Number<int> sub = sum - Number<int>{3};
    Number<int> multiply = sub * Number<int>{10};
    Number<int> div = Number<int>{1000} / Number<int>{5};
    Number<double> large{984.3};
    Number<double> assignment_test = large;

    Number<int> mod_1{1699};
    Number<int> ten{10};
    Number<int> res = mod_1 % ten;

    Number<double> mod_2{1.97};
    Number<int> mod_3{9};
    // This fails as the question suggested.  FIX IT!
    Number<double> res_2 = mod_2 % mod_3;

    std::cout << "my_int\t\t" << my_int << '\n';
    std::cout << "default\t\t" << my_default_int << '\n';
    std::cout << "sum\t\t" << sum << '\n';
    std::cout << "sub\t\t" << sub << '\n';
    std::cout << "mult\t\t" << multiply << '\n';
    std::cout << "div\t\t" << div << '\n';
    std::cout << "double\t\t" << assignment_test << '\n';
    std::cout << "1000 mod 10\t\t" << res << '\n';

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