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
  Int() : value{0} {}
  Int(int n) : value{n} {}
  Int& get();
  const Int& get() const;
  Int& operator=(const Int& i);  // copy assignment
  Int& operator=(Int&& i);       // move assignment
  Int& operator+(const Int& rhs);

  friend std::ostream& operator<<(std::ostream& os, Int& i);
};

Int& Int::get() { return Int{value}; }

//------------------------------------------------------------------------------

const Int& Int::get() const { return Int{value}; }

//------------------------------------------------------------------------------

Int& Int::operator=(const Int& i)
{
  if (value == i.value) return *this;  // check if same object
  value = i.value;
  return *this;
}

//------------------------------------------------------------------------------

Int& Int::operator=(Int&& i)
{
  // TODO: insert return statement here
}

//------------------------------------------------------------------------------

Int& Int::operator+(const Int& rhs) { return Int{value + rhs.value}; }

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

    std::cout << my_int << '\n';
    std::cout << my_default_int << '\n';

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
