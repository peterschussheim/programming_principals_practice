// Add the bitwise logical operators & , | , ^ , and ~ to the calculator from
// Chapter 7.

#include "Calculator.h"

int main()
{
  try {
    // system-defined names:
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);
    define_name("k", 1000);

    calculate();

    return 0;
  }
  catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cerr << "exception\n";
    return 2;
  }
}