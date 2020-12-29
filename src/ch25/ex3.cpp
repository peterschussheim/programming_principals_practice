// Initialize a 32-bit signed integer with the bit patterns and print the re-
// sult:
// 0) all zeros
// 1) all ones
// 2) alternating ones and zeros (starting with a left-most one)
// 3) alternating zeros and ones (starting with a leftmost zero)
// 4) the 110011001100 . . . pattern
// 5) the 001100110011 . . . pattern
// 6) the pattern of all-one bytes and all-zero bytes starting with an all-one
// byte
// 7) the pattern of all-one bytes and all-zero bytes starting with an
// all-zero byte.
//
// Repeat that exercise with a 32-bit unsigned integer.

#include <iostream>
#include <bitset>

// To recap, use signed integers (int) for numbers and use unsigned integers
// (unsigned int) for sets of bits.

template<typename T> void print(T v)
{
  std::cout << std::bitset<32>(v) << " -> " << v << '\n';
}

int main()
{
  int i0{0b0000'0000'0000'0000'0000'0000'0000'0000};
  // probably would be a better idea to explicitly cast:
  int i1 = 0b1111'1111'1111'1111'1111'1111'1111'1111;
  int i2 = 0b1010'1010'1010'1010'1010'1010'1010'1010;
  int i3{0b0101'0101'0101'0101'0101'0101'0101'0101};
  int i4 = 0b1100'1100'1100'1100'1100'1100'1100'1100;
  int i5{0b0011'0011'0011'0011'0011'0011'0011'0011};
  int i6 = 0b1111'1111'0000'0000'1111'1111'0000'0000;
  int i7{0b0000'0000'1111'1111'0000'0000'1111'1111};

  unsigned int ui0{0b0000'0000'0000'0000'0000'0000'0000'0000};
  unsigned int ui1{0b1111'1111'1111'1111'1111'1111'1111'1111};
  unsigned int ui2{0b1010'1010'1010'1010'1010'1010'1010'1010};
  unsigned int ui3{0b0101'0101'0101'0101'0101'0101'0101'0101};
  unsigned int ui4{0b1100'1100'1100'1100'1100'1100'1100'1100};
  unsigned int ui5{0b0011'0011'0011'0011'0011'0011'0011'0011};
  unsigned int ui6{0b1111'1111'0000'0000'1111'1111'0000'0000};
  unsigned int ui7{0b0000'0000'1111'1111'0000'0000'1111'1111};

  std::cout << "Signed integers:\n\n";
  print(i0);
  print(i1);
  print(i2);
  print(i3);
  print(i4);
  print(i5);
  print(i6);
  print(i7);
  std::cout << '\n';

  std::cout << "Unsigned integers:\n\n";
  print(ui0);
  print(ui1);
  print(ui2);
  print(ui3);
  print(ui4);
  print(ui5);
  print(ui6);
  print(ui7);

  return 0;
}