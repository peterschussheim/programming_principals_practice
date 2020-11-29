#include <iostream>
#include <bitset>
#include <iomanip>
#include <sstream>

struct Message {
  int a;
  int b;
  int c;
};

struct Node {
  int a;
  int b;
};

// demomstrate fragmented memory from incorrect free store usage
void fragmented()
{
  Message* p = new Message();
  Node* n1 = new Node();
  delete p;

  Node* n2 = new Node();
  Message* pp = 0;
  Node* nn1 = 0;
  Node* nn2 = 0;

  for (int i = 0; i < 100; ++i) {
    pp = new Message();
    nn1 = new Node();
    delete pp;

    nn2 = new Node();
  }

  std::cout << "Address gap with fragmentation: " << nn2 - n1 << '\n';
}

void non_fragmented()
{
  Node* n1 = new Node();
  Node* n2 = new Node();

  Message* p = new Message();
  delete p;
  Message* pp = 0;

  Node* nn1 = 0;
  Node* nn2 = 0;

  for (int i = 0; i < 100; ++i) {
    // Avoid fragmentation by allocating the two Nodes first,
    // then allocate the Message:
    nn1 = new Node();
    nn2 = new Node();
    pp = new Message();
    delete pp;
  }

  std::cout << "Address gap without fragmentation: " << nn2 - nn1 << '\n';
}

void try_this_1()
{
  std::cout << "sizeof(Message): " << sizeof(Message) << '\n';
  std::cout << "sizeof(Node): " << sizeof(Node) << '\n';
  fragmented();
  non_fragmented();
}

void try_this_2()
{
  // Read integers in decimal notation from stdin and print decimal, hex
  // and binary representations on one line.
  for (unsigned i; std::cin >> i;) {
    std::cout << std::dec << i << "==" << std::hex << "0x" << i
              << "==" << std::bitset<8 * sizeof(unsigned)>{i} << '\n';
  }
}

// center-aligns string within a field of width w to enforce alignment.
std::string center(const std::string s, const int w)
{
  std::stringstream ss;
  std::stringstream spaces;
  int padding = w - s.size();
  for (int i = 0; i < padding / 2; ++i) { spaces << " "; }
  ss << spaces.str() << s << spaces.str();
  if (padding > 0 && padding % 2 != 0) { ss << " "; }
  return ss.str();
}

// print value x with specified amount of left padding pad.
template<typename T> std::string prt(T x, const int width)
{
  std::stringstream ss;
  ss << std::fixed << std::right;
  ss.fill(' ');     // fill space around display
  ss.width(width);  // set width around printed val

  ss << x;
  return ss.str();
}

void print_dec_to_hex()
{
  const int small_col_width = 8 - 2;
  const int large_col_width = 48 - 2;
  std::cout << center("Decimal", small_col_width) << " | "
            << center("Hex", small_col_width) << " | "
            << center("Binary", large_col_width) << '\n';
  std::cout << std::string(small_col_width * 2 + large_col_width + 2 * 3, '-')
            << '\n';
  for (unsigned int i = 0; i < 255; ++i) {
    std::cout << std::dec << prt(i, small_col_width) << " | " << std::hex
              << "0x" << i << std::setfill(' ') << std::setw(small_col_width)
              << " | "
              << prt(std::bitset<8 * sizeof(unsigned int)>{i}, large_col_width)
              << '\n';
  }
}

void infinite()
{
  // This function runs for ever due to a mismatch of unsigned and signed
  // integers.  The largest decimal value that an unsigned char can hold
  // is 160 whereas for a signed char, the max decimal value is 128.
  // So, with this in mind, we predict that when the loop variable i is
  // incremented past its maximum, it starts returning negative values.
  // Ex: signed char (essentially modulo arithmetic), loop terminates at 0.
  //     1 2 ... 126 127 -128 -127 ... -2 -1
  // As a rule, avoid mixing unsigned and signed types and more specifically,
  // use signed integers for numbers and unsigned integers for set of bits.
  unsigned char max = 127;  // very large
  for (signed char i = 0; i < max; ++i) { std::cout << int(i) << '\n'; }
}

//------------------------------------------------------------------------------

// We need to define the following templated function and overloads to treat
// each integer type the same, otherwise we'd print a char rather than the int
// representation.

template<typename T> void print(T i) { std::cout << i << '\t'; }
void print(char i) { std::cout << int(i) << '\t'; }
void print(signed char i) { std::cout << int(i) << '\t'; }
void print(unsigned char i) { std::cout << int(i) << '\t'; }

//------------------------------------------------------------------------------

void try_this_3()
{
  int si = 257;  // doesn't fit into signed integer
  char c = si;   // implicit conversion to char (char is a signed int!!)
  unsigned char uc = si;
  signed char sc = si;
  print(si);
  print(c);
  print(uc);
  print(sc);
  std::cout << '\n';

  si = 128;  // doesn't fit into a signed char
  c = si;
  uc = si;
  sc = si;
  print(si);
  print(c);
  print(uc);
  print(sc);
  std::cout << '\n';
}

int main()
{
  // try_this_1();
  // try_this_2();
  // std::cout << "sizeof(signed char): " << sizeof(signed char) << '\n';
  // infinite();
  try_this_3();
  // print_dec_to_hex();
  return 0;
}