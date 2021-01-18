// 10) Look at the bitfield example from §25.5.5.
// Write an example that initializes a PPN, then reads and prints each field
// value, then changes each field value (by assigning to the field) and prints
// the result. Repeat this exercise, but store the PPN information in a 32-bit
// unsigned integer and use bit manipulation operators (§25.5.4) to access the
// bits in the word.

// 11) Repeat the previous exercise, but keep the bits in a bitset<32>

#include <iostream>

// 32-bit word representing a bitfield (fixed layout)
// bitfields fill a word from left to right.
struct PPN {              // R6000 Physical page number
  unsigned int PFN : 22;  // Page Frame Number
  int : 3;                // unused
  unsigned int CCA : 3;   // Cache Coherency Algorithm
  bool nonreachable : 1;
  bool dirty : 1;
  bool valid : 1;
  bool global : 1;
};

// TODO: Reread 25.5.5 and complete below
int main()
{
  try {
    // init PPN
    PPN ppn{};
    ppn.PFN = 0x7;
    ppn.CCA = 10;
    // read and print each field value
    std::cout << "ppn.PFN: " << ppn.PFN << '\n';
    // change each field via assignment and print result

    // repeat above using a 32-bit unsigned int using ONLY bit manipulation
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
