// Without using any standard headers (such as <limits> ) or documenta-
// tion, compute the number of bits in an int and determine whether char is
// signed or unsigned on your implementation.

#include <iostream>

int main()
{
  try {
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
