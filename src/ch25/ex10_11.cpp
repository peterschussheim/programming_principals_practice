// 10) Look at the bitfield example from §25.5.5.
// Write an example that initializes a PPN, then reads and prints each field
// value, then changes each field value (by assigning to the field) and prints
// the result. Repeat this exercise, but store the PPN information in a 32-bit
// unsigned integer and use bit manipulation operators (§25.5.4) to access the
// bits in the word.

// 11) Repeat the previous exercise, but keep the bits in a bitset<32>

#include <iostream>
#include <bitset>
#include <iomanip>
#include <string>

//------------------------------------------------------------------------------
void ex10();
void ex11();
//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

// print a bitset with a label, formatted such that the label is aligned to the
// left and the bitset is aligned to the right
template<typename T> void print_bitset(const std::string& label, T& t)
{
  std::bitset<32> bs{t};
  const size_t max_ws = 8;  // max whitespace btwn label and val
  const std::string sep = " | ";
  std::cout << std::left << std::setw(max_ws) << label << std::setfill(' ')
            << sep << bs;
}

//------------------------------------------------------------------------------

int main()
{
  try {
    ex10();
    std::cout << '\n';
    ex11();
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

//------------------------------------------------------------------------------

void ex10()
{
  // init PPN
  PPN ppn{};

  // read and print each field value
  std::cout << "ppn:\n";
  std::cout << "\tppn.PFN: " << ppn.PFN << '\n';
  std::cout << "\tppn.CCA: " << ppn.CCA << '\n';
  std::cout << "\tppn.dirty: " << ppn.dirty << '\n';
  std::cout << "\tppn.valid: " << ppn.valid << '\n';
  std::cout << "\tppn.global: " << ppn.global << '\n';
  std::cout << "\n\n";
  // change each field via assignment and print result
  ppn.PFN = 0x3fffff;
  ppn.CCA = 0x7;
  ppn.dirty = false;
  ppn.valid = true;
  ppn.global = true;
  std::cout << "ppn (after assigning values):\n";
  std::cout << "\tppn.PFN: " << ppn.PFN << '\n';
  std::cout << "\tppn.CCA: " << ppn.CCA << '\n';
  std::cout << "\tppn.dirty: " << ppn.dirty << '\n';
  std::cout << "\tppn.valid: " << ppn.valid << '\n';
  std::cout << "\tppn.global: " << ppn.global << "\n";
  std::cout << "----------------------------------------------------------\n";

  // repeat above using a 32-bit unsigned int using ONLY bit manipulation
  unsigned int ppn_u = 0;
  ppn_u = 4194303 << 10;  // PFN

  // the syntax ppn_u |= 3<<4 shown below can be phrased as "set the 4th bit
  // to 3 and assign the result to ppn_u".
  ppn_u |= 7 << 4;  // CCA
  ppn_u |= 0 << 3;  // nonreachable
  ppn_u |= 1 << 2;  // dirty
  ppn_u |= 1 << 1;  // valid
  ppn_u |= 1;       // global

  // to read each field from ppn_u, shift right by the corresponding position
  // and mask.
  // recall:
  // left shift: bit n of x<<s is bit n+s of x.
  // right shift: bit n of x>>s is bit n-s of x.
  // This is known as "shift and mask" where we "shift" using << or >> to
  // place, the bits we want to consider to the rightmost (least significant
  // bit) part of the word where they are EASY to MANIPULATE. We mask using &
  // and a bit pattern to eliminate (set to zero) the bits we do not want in
  // the result.
  std::cout << "PFN: " << (ppn_u >> 10) << '\n';
  std::cout << "CCA: " << ((ppn_u >> 4) & 0x7) << '\n';
  std::cout << "nonreachable: " << ((ppn_u >> 3) & 1) << '\n';
  std::cout << "dirty: " << ((ppn_u >> 2) & 1) << '\n';
  std::cout << "valid: " << ((ppn_u >> 1) & 1) << '\n';
  std::cout << "global: " << (ppn_u & 1) << '\n';
}

//------------------------------------------------------------------------------

void ex11()
{
  std::bitset<32> ppn;

  ppn = 4194303 << 10;
  ppn |= 7 << 4;
  ppn |= 0 << 3;
  ppn |= 1 << 2;
  ppn |= 1 << 1;
  ppn |= 1;
  std::cout << "PFN: " << (ppn.to_ulong() >> 10) << '\n';
  std::cout << "CCA: " << ((ppn.to_ulong() >> 4) & 0x7) << '\n';
  std::cout << "nonreachable: " << ((ppn.to_ulong() >> 3) & 1) << '\n';
  std::cout << "dirty: " << ((ppn.to_ulong() >> 2) & 1) << '\n';
  std::cout << "valid: " << ((ppn.to_ulong() >> 1) & 1) << '\n';
  std::cout << "global: " << (ppn.to_ulong() & 1) << '\n';
}

//------------------------------------------------------------------------------