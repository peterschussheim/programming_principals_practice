// Write out the numerical values of each character on your keyboard.

#include <iostream>

int main()
{
  try {
    // print row by row
    // qwertyuiop
    // asdfghjkl
    // zxcvbnm
    // control chars

    // function keys
    for (unsigned char ch = 112; ch <= 126; ++ch) {
      std::cout << int(ch) << ": " << ch << '\n';
    }

    // num/symbols
    for (unsigned char ch = 33; ch <= 57; ++ch) {
      std::cout << int(ch) << ": " << ch << '\n';
    }
    // uppercase alphabet
    for (unsigned char ch = 65; ch <= 90; ++ch) {
      std::cout << int(ch) << ": " << ch << '\n';
    }

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
