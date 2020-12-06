// 1. Run this:
// int v = 1; for (int i = 0; i<sizeof(v)*8; ++i) { cout << v << ' '; v <<=1; }
// 2. Run that again with v declared to be an unsigned int .
// 3. Using hexadecimal literals, define short unsigned ints with:
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
#include <iomanip>
#include <limits>
#include <bitset>
#include <vector>

//------------------------------------------------------------------------------
// a few examples of useful bitset types:
using flags = std::bitset<4>;
using dword_bits = std::bitset<128>;

//------------------------------------------------------------------------------
void print_limits();
//------------------------------------------------------------------------------

// Prints to cout each element in vector<T> v.
// Formatted to easily see bit patterns.
template<typename T> void print_bits(std::vector<T>& v);
//------------------------------------------------------------------------------

int main()
{
  try {
    // int v = 1;
    unsigned int v = 1;
    for (int i = 0; i < sizeof(v) * 8; ++i) {
      std::cout << i << ":\t" << v << '\n';
      v <<= 1;
    }
    std::cout << '\n';
    std::vector<short unsigned> v_hexadecimal{
        0xffff,  // a  1111111111111111
        0x0001,  // b  0000000000000001
        0x8000,  // c  1000000000000000
        0x00ff,  // d  0000000011111111
        0xff00,  // e  1111111100000000
        0x5555,  // f  0101010101010101
        0xaaaa,  // g  1010101010101010
    };

    print_bits(v_hexadecimal);  // 4

    // 5: repeat 3 and 4 using only bit manipulation operations (<<, |, &)
    // and only the literals 0 and 1.
    std::vector<short unsigned> v_bit;
    short unsigned a = ~0;
    v_bit.push_back(a);

    short unsigned b = 1;
    v_bit.push_back(b);
    short unsigned c = 1;
    c <<= 15;  // perform left shift on c by 15 bits
    v_bit.push_back(c);

    // right shift on d 8 times
    short unsigned d = ~0;  // start with all bits set
    d >>= 8;
    v_bit.push_back(d);

    short unsigned e = ~0;
    e <<= 8;
    v_bit.push_back(e);

    short unsigned f = 1;
    for (int i = 2; i < 15; i += 2) {
      // std::cout << std::bitset<8 * sizeof(short unsigned)>{f} << '\n';
      short unsigned temp = 1;
      temp <<= i;
      f |= temp;
    }

    v_bit.push_back(f);

    short unsigned g = ~f;
    v_bit.push_back(g);

    std::cout << '\n';
    print_bits(v_bit);

    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}

template<typename T> void print_bits(std::vector<T>& v)
{
  for (auto i : v) {
    std::cout << std::setw(5) << std::dec << i << " == "
              << "0x" << std::setfill('0') << std::setw(4) << std::hex << i
              << " == " << std::setfill(' ')
              << std::bitset<8 * sizeof(unsigned short)>{i} << '\n';
  }
}

void print_limits()
{
  std::cout << "type\tlowest()\tmin()\t\tmax()\n\n"
            << "bool\t" << std::numeric_limits<bool>::lowest() << "\t\t"
            << std::numeric_limits<bool>::min() << "\t\t"
            << std::numeric_limits<bool>::max() << '\n';
  std::cout << "char\t" << +std::numeric_limits<char>::lowest() << "\t\t"
            << +std::numeric_limits<char>::min() << "\t\t"
            << +std::numeric_limits<char>::max() << '\n';
  std::cout << "schar\t" << +std::numeric_limits<signed char>::lowest()
            << "\t\t" << +std::numeric_limits<signed char>::min() << "\t\t"
            << +std::numeric_limits<signed char>::max() << '\n';
  std::cout << "uchar\t" << +std::numeric_limits<unsigned char>::lowest()
            << "\t\t" << +std::numeric_limits<unsigned char>::min() << "\t\t"
            << +std::numeric_limits<unsigned char>::max() << '\n';
  std::cout << "short\t" << std::numeric_limits<short>::lowest() << "\t\t"
            << std::numeric_limits<short>::min() << "\t\t"
            << std::numeric_limits<short>::max() << '\n';
  std::cout << "int\t" << std::numeric_limits<int>::lowest() << "\t"
            << std::numeric_limits<int>::min() << "\t"
            << std::numeric_limits<int>::max() << '\n';
  std::cout << "s int\t" << std::numeric_limits<signed int>::lowest() << "\t"
            << std::numeric_limits<signed int>::min() << '\t'
            << std::numeric_limits<signed int>::max() << '\n';
  std::cout << "u int\t" << std::numeric_limits<unsigned int>::lowest()
            << "\t\t" << std::numeric_limits<unsigned int>::min() << "\t\t"
            << std::numeric_limits<unsigned int>::max() << '\n';
  std::cout << "llong\t" << std::numeric_limits<long long>::lowest() << '\t'
            << std::numeric_limits<long long>::min() << '\t'
            << std::numeric_limits<long long>::max() << '\n';
  std::cout << "float\t" << std::numeric_limits<float>::lowest() << '\t'
            << std::numeric_limits<float>::min() << '\t'
            << std::numeric_limits<float>::max() << '\n';
  std::cout << "double\t" << std::numeric_limits<double>::lowest() << '\t'
            << std::numeric_limits<double>::min() << '\t'
            << std::numeric_limits<double>::max() << '\n';
}