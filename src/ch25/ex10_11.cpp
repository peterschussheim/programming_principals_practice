// 10) Look at the bitfield example from §25.5.5. Write an example that initial-
// izes a PPN , then reads and prints each field value, then changes each field
// value (by assigning to the field) and prints the result. Repeat this
// exercise, but store the PPN information in a 32-bit unsigned integer and use
// bit manipulation operators (§25.5.4) to access the bits in the word.

// 11) Repeat the previous exercise, but keep the bits in a bitset<32>

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
