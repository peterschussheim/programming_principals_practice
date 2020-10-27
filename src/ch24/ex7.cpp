// 7. Rewrite the Gaussian elimination program without using the Matrix li-
// brary; that is, use built-in arrays or vector s instead of Matrix es.

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
