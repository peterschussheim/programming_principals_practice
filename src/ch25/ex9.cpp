// Without using any standard headers (such as <limits> ) or documenta-
// tion, compute the number of bits in an int and determine whether char is
// signed or unsigned on your implementation.

#include <iostream>
#include <bitset>

int main()
{
  try {
    std::bitset<8 * sizeof(int)> bin;  // display binary representation
    int n = 0;    // bit position, 0 indicates the least significant bit
    int val = 1;  // integer value in decimal representation
    while (true) {
      bin = val << n;
      std::cout << "bit at position " << n << " set: " << (val << n) << '\t'
                << bin << '\n';

      if ((val << n) < (val << (n - 1)))  // compare current bit to previous bit
      {
        break;  // if the value at n is less than the previous value, break out
                // of the loop, since we are overflowing or going into negative
                // values.
      }

      ++n;  // move to the left, to a more significant bit
    }

    std::cout << "int has " << n + 1 << " bits, shifting left by " << n
              << " positions.\n\n";

    // TODO: Refine the assertions below and play with them before moving on.
    static_assert(4 <= sizeof(int), "ints are too small");
    // static_assert(!std::numeric_limits<char>::is_signed, "char is signed");
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
