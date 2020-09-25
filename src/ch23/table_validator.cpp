#include <iostream>
#include <regex>
#include <fstream>
#include <string>

int main()
{
  try {
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}