/*
  Repeat the previous exercise, but with a class Number<T> where T can be
  any numeric type. Try adding % to Number and see what happens when
  you try to use % for Number<double> and Number<int>
*/

#include <iostream>
#include <stdexcept>

// TODO: fix Number<T> class to correctly make template specializations.
// check how if I am using the correct syntax

template<class T>
class Number {
  T value;

public:
  Number() : value{0} {}     // default constructor
  Number(T n) : value{n} {}  // initialize member

  // Number(const Number&);               // copy constructor
  Number& operator=(const Number<T>& i);  // copy assignment

  Number<T> operator+(const Number<T>& rhs);
  Number operator-(const Number& rhs);
  Number operator*(const Number& rhs);
  Number operator/(const Number& rhs);

  const Number<T> get() const;

  friend std::ostream& operator<<(std::ostream& os, Number& i);
};

//------------------------------------------------------------------------------

template<class T>
const Number<T> Number<T>::get() const
{
  return value;
}

//------------------------------------------------------------------------------

template<class T>
Number<T>& Number<T>::operator=(const Number<T>& i)
{
  if (value == i.value) return *this;  // check if same object
  value = i.value;
  return *this;
}

//------------------------------------------------------------------------------

template<class T>
Number<T> Number<T>::operator+(const Number<T>& rhs)
{
  return {value + rhs.get()};
}

template<class T>
Number<T> Number<T>::operator-(const Number<T>& rhs)
{
  return {value - rhs.get()};
}

template<class T>
Number<T> Number<T>::operator*(const Number<T>& rhs)
{
  return {value * rhs.get()};
}

template<class T>
Number<T> Number<T>::operator/(const Number<T>& rhs)
{
  return {value / rhs.get()};
}

//------------------------------------------------------------------------------

template<class T>
std::ostream& operator<<(std::ostream& os, Number<T>& i)
{
  os << i.value;
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
    Number<int> large{99999999};
    Number<int> assignment_test = large;

    std::cout << "my_int\t\t" << my_int << '\n';
    std::cout << "default\t\t" << my_default_int << '\n';
    std::cout << "sum\t\t" << sum << '\n';
    std::cout << "sub\t\t" << sub << '\n';
    std::cout << "mult\t\t" << multiply << '\n';
    std::cout << "div\t\t" << div << '\n';
    std::cout << "assignment_test\t\t" << assignment_test << '\n';

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