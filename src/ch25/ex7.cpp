// Write out the hexadecimal values from 0 to 400; write out the hexadeci-
// mal values from –200 to 200.

#include <iostream>
#include <iomanip>

void print_hex(int from, int to)
{
  for (int i = from; i != to + 1; ++i) {
    std::cout << std::setbase(10) << i << ": " << std::setbase(16) << i << '\n';
  }
}

int main()
{
  print_hex(0, 400);
  print_hex(-200, 200);

  return 0;
}