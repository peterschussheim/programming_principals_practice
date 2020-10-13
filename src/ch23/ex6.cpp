// Write a program that finds dates in a text file. Write out each line contain-
// ing at least one date in the format line–number: line . Start with a regular
// expression for a simple format, e.g., 12/24/2000, and test the program
// with that. Then, add more formats.

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
