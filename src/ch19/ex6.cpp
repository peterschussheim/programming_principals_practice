/*
  Repeat the previous exercise, but with a class Number<T> where T can be
  any numeric type. Try adding % to Number and see what happens when
  you try to use % for Number<double> and Number<int>
*/

/*
  Notes:

  Choosing between member or nonmember implementation

  Here are a few rules of thumb (from C++ Primer) to help decide if it is
  preferable to define overloads (specifically, operator overloads) as members
  vs nonmembers:

    Must be implemented as member:
      - assignment=
      - subscript[]
      - call()
      - member access arrow->

    Should be implemented as member:
      - compound assignments should be members but it is not required
      - operations which mutate their object's state should be members (inc,
        decrement, dereference)

     Should be nonmember:
      - symmetric operators, for example:
        - conversions between operands of different types (equality, relational,
          bitwise, arithmetic)

          int num = 4;
          double num_dbl = 44.03;

          // MyNumber is expected to support this usage, regardless of order
          // of the operands.
          MyNumber sum = num + num_dbl;
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cmath>

// error() simply disguises throws:
inline void error(const std::string& s) { throw std::runtime_error(s); }

inline void error(const std::string& s, const std::string& s2)
{
  error(s + s2);
}

inline void error(const std::string& s, int i)
{
  std::ostringstream os;
  os << s << ": " << i;
  error(os.str());
}

//------------------------------------------------------------------------------

// run-time checked narrowing cast (from PPP)
template<class R, class A>
R narrow_cast(const A& a)
{
  R r = R(a);
  if (A(r) != a) error(std::string("info loss"));
  return r;
}

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

// template<class T>
// Number<T> operator%(const Number<T>& lhs, const Number<T>& rhs)
//{
//  int lhs_int = narrow_cast<int>(lhs.get());
//  int rhs_int = narrow_cast<int>(rhs.get());
//  if (rhs_int == 0) error("%: divide by zero");
//
//  return {lhs_int % rhs_int};
//}

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