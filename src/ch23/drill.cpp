// 2. Get the little program from §23.7 to work; that may involve figuring out
// how to set the project and/or command-line options to link to the regex
// library and use the regex headers.
//
// 3. Use the program from drill 2 to test the patterns from §23.7.

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
