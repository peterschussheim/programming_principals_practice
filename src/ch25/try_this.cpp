#include <iostream>
#include <bitset>
#include <iomanip>
#include <sstream>
#include <fstream>

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
  // This function runs forever due to a mismatch of unsigned and signed
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

//------------------------------------------------------------------------------

void encipher(const unsigned long* const v, unsigned long* const w,
              const unsigned long* const k)
{
  static_assert(sizeof(long) == 4, "size of long wrong for TEA");

  unsigned long y = v[0];
  unsigned long z = v[1];
  unsigned long sum = 0;
  const unsigned long delta = 0x9E3779B9;

  for (unsigned long n = 32; n-- > 0;) {
    y += (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
    sum += delta;
    z += (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
  }

  w[0] = y;
  w[1] = z;
}

//------------------------------------------------------------------------------

void decipher(const unsigned long* const v, unsigned long* const w,
              const unsigned long* const k)
{
  static_assert(sizeof(long) == 4, "size of long wrong for TEA");
  unsigned long y = v[0];
  unsigned long z = v[1];
  unsigned long sum = 0xC6EF3720;
  const unsigned long delta = 0x9E3779B9;

  // sum = delta<<5, in general sum = delta * n
  for (unsigned long n = 32; n-- > 0;) {
    z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
    sum -= delta;
    y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
  }

  w[0] = y;
  w[1] = z;
}

//------------------------------------------------------------------------------

// Used by the receiver of an encrypted message to decipher the text.
void decrypt(std::string infile, std::string outfile, std::string key)
{
  const int nchar = 2 * sizeof(long);  // 64 bits
  const int kchar = 2 * nchar;         // 128 bits

  while (key.size() < kchar) key += '0';  // pad key with 0

  std::ifstream inf(infile);
  std::ofstream outf(outfile);
  if (!inf || !outf) std::cerr << "bad file name\n";

  const unsigned long* k = reinterpret_cast<const unsigned long*>(key.data());

  unsigned long inptr[2];
  char outbuf[nchar + 1];
  outbuf[nchar] = 0;  // terminator

  unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
  inf.setf(std::ios_base::hex,
           std::ios_base::basefield);  // use hexadecimal input

  while (inf >> inptr[0] >> inptr[1]) {
    decipher(inptr, outptr, k);
    outf << outbuf;
  }
}

//------------------------------------------------------------------------------
// TODO: Figure out why the encrypted output is generated as many columns
// wide rather than a few as in the example from the book.
// Use to encrypt the contents of a plaintext file.
void encrypt(std::string infile, std::string outfile, std::string key)
{
  const int nchar = 2 * sizeof(long);  // 64 bits
  const int kchar = 2 * nchar;         // 128 bits

  while (key.size() < kchar) key += '0';  // pad key with 0

  std::ifstream inf(infile);
  std::ofstream outf(outfile);
  if (!inf || !outf) std::cerr << "bad file name\n";

  const unsigned long* k = reinterpret_cast<const unsigned long*>(key.data());

  unsigned long outptr[2];
  char inbuf[nchar];
  unsigned long* inptr = reinterpret_cast<unsigned long*>(inbuf);
  int count = 0;

  while (inf.get(inbuf[count])) {
    outf << std::hex;  // use hex for output
    if (++count == nchar) {
      encipher(inptr, outptr, k);
      // pad with leading zeros:
      outf << std::setw(8) << std::setfill('0') << outptr[0] << ' '
           << std::setw(8) << std::setfill('0') << outptr[1] << ' ';
      count = 0;
    }
  }

  if (count)  // pad
  {
    while (count != nchar) inbuf[count++] = '0';
    encipher(inptr, outptr, k);
    outf << outptr[0] << ' ' << outptr[1] << ' ';
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int main()
{
  // try_this_1();
  // try_this_2();
  // std::cout << "sizeof(signed char): " << sizeof(signed char) << '\n';
  // infinite();
  // try_this_3();
  // print_dec_to_hex();
  encrypt("constitution.txt", "encrypted_constitution.txt", "sim");
  // decrypt("encrypted.txt", "decrypted.txt", "bs");
  return 0;
}