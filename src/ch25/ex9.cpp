// Without using any standard headers (such as <limits> ) or documenta-
// tion, compute the number of bits in an int and determine whether char is
// signed or unsigned on your implementation.

#include <iostream>

int main()
{
  try {
    // TODO: Write out a few notes on the code below.
    // TODO: Write a few static assertions to validate the results below with
    // <limits>.

    int n = 0;
    int i = 1;
    while (true) {
      std::cout << "bit " << n << " set: " << (i << n) << '\n';
      if ((i << n) < (i << (n - 1))) break;
      ++n;
    }

    std::cout << "int has " << n + 1 << " bits, shifting by " << n
              << " positions.\n\n";

    char ch = -1;
    if (ch == -1)
      std::cout << "char is signed\n";
    else
      std::cout << "char is unsigned\n";

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
