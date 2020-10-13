#include <iostream>
#include <iomanip>
#include <limits>

void f(int i, double fpd);
void g();
void limits_ex();

//------------------------------------------------------------------------------

int main()
{
  try {
    // float x = 1.0 / 333;
    // float sum = 0;
    // for (int i = 0; i < 333; ++i) sum += x;
    // std::cout << std::setprecision(15) << sum << '\n';
    // g();
    // f(9999999, 3.223);
    limits_ex();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}

//------------------------------------------------------------------------------

void f(int i, double fpd)
{
  char c = i;   // yes: chars really are very small integers
  short s = i;  // beware: a large int may not fit in a short
  std::cout << "c: " << c << '\n';
  std::cout << "s: " << s << '\n';

  i = i + 1;  // what if i was the largest int?
  std::cout << "i = i + 1: " << i << '\n';

  long lg = i * i;  // beware: a long may not be any larger than an int
  std::cout << "lg: " << lg << '\n';

  float fps = fpd;  // beware: a large double may not fit in a float
  std::cout << "fpd: " << fpd << '\n';

  i = fpd;  // truncates: e.g. 5.7 -> 5
  std::cout << "i = fpd: " << i << '\n';

  fps = i;  // you can loose precision (for very large int values)
  std::cout << "fps: " << fps << '\n';
}

void g()
{
  char ch = 0;
  for (int i = 0; i < 500; ++i) { std::cout << int(ch++) << '\n'; }
}

void limits_ex()
{
  std::cout << "number of bytes in an int: " << sizeof(int) << '\n';
  std::cout << "largest int: " << INT_MAX << '\n';
  std::cout << "smallest int value: " << std::numeric_limits<int>::min()
            << '\n';

  if (std::numeric_limits<char>::is_signed)
    std::cout << "char is signed\n";
  else
    std::cout << "char is unsigned\n";

  constexpr char ch =
      std::numeric_limits<char>::min();  // smallest positive value
  std::cout << "the char with the smallest positive value: " << ch << '\n';
  std::cout << "the int value of the char with the smallest positive value: "
            << int(ch) << '\n';
}
