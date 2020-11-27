// 1. Run this:
// int v = 1; for (int i = 0; i<sizeof(v)*8; ++i) { cout << v << ' '; v <<=1; }
// 2. Run that again with v declared to be an unsigned int .
// 3. Using hexadecimal literals, define short unsigned int s with:
//   a. Every bit set
//   b. The lowest (least significant bit) set
//   c. The highest (most significant bit) set
//   d. The lowest byte set
//   e. The highest byte set
//   f. Every second bit set (and the lowest bit 1)
//   g. Every second bit set (and the lowest bit 0)
// 4. Print each as a decimal and as a hexidecimal.
// 5. Do 3 and 4 using bit manipulation operations ( | , & , << ) and (only) the
// literals 1 and 0.

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
}