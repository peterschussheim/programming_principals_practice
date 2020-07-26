/*
  Define a class Int having a single member of class int.
  Define constructors, assignment, and operators + , – , * , / for it.
  Test it, and improve its design as needed (e.g., define operators << and >>
  for convenient I/O).
*/

#include <iostream>
#include <stdexcept>

class Int {
  int value;

public:
  Int() : value{0} {}       // default constructor
  Int(int n) : value{n} {}  // initialize member

  // Int(const Int&);               // copy constructor
  Int& operator=(const Int& i);  // copy assignment

  // Int(Int&&);               // move constructor
  // Int& operator=(Int&& i);  // move assignment

  Int operator+(const Int& rhs);
  Int operator-(const Int& rhs);
  Int operator*(const Int& rhs);
  Int operator/(const Int& rhs);

  const int get() const;

  friend std::ostream& operator<<(std::ostream& os, Int& i);
};

//------------------------------------------------------------------------------

const int Int::get() const { return value; }

//------------------------------------------------------------------------------

Int& Int::operator=(const Int& i)
{
  if (value == i.value) return *this;  // check if same object
  value = i.value;
  return *this;
}

//------------------------------------------------------------------------------

// Int& Int::operator=(Int&& i)
//{
//  value = i.get();  // copy i's value to this->value
//  return *this;
//}

//------------------------------------------------------------------------------

Int Int::operator+(const Int& rhs) { return {value + rhs.get()}; }

Int Int::operator-(const Int& rhs) { return {value - rhs.get()}; }

Int Int::operator*(const Int& rhs) { return {value * rhs.get()}; }

Int Int::operator/(const Int& rhs) { return {value / rhs.get()}; }

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, Int& i)
{
  os << i.value;
  return os;
}

int main()
{
  try {
    Int my_int{100};
    Int my_default_int;
    Int sum = my_int + Int{99};
    Int sub = sum - Int{3};
    Int multiply = sub * Int{10};
    Int div = Int{1000} / Int{5};
    Int large{99999999};
    Int assignment_test = large;

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
