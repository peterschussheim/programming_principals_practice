// Write an infinite loop that is hard to recognize as an infinite loop. A loop
// that isn’t really infinite because it terminates after completely consuming
// some resource is acceptable.

#include <iostream>

int main()
{
  unsigned char max = 255;
  for (signed char i = 0; i < max; ++i) { std::cout << int(i) << '\n'; }
  return 0;
}