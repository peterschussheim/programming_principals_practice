// Take the word-frequency example from §21.6.1 and modify it to output
// its lines in order of frequency (rather than in lexicographical order).
// An example line would be 3: C++ rather than C++: 3

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
