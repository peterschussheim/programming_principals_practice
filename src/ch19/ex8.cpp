/*
  Implement an allocator (§19.3.7) using the basic allocation functions mal-
  loc() and free() (§B.11.4). Get vector as defined by the end of §19.4 to
  work for a few simple test cases. Hint: Look up “placement new ” and
  “explicit call of destructor” in a complete C++ reference.
*/

#include <iostream>
#include <stdexcept>

int main()
{
  try {
    std::cout << "hello world!\n";
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