/*
  Implement a simple unique_ptr supporting only a constructor, destructor,
  –> , * , and release() . In particular, don’t try to implement an assignment
  or a copy constructor.
*/

#include <iostream>
#include <stdexcept>
#include <memory>

/*
  TODO:

  - [ ] re-read chapter 19.5.4 on unique_ptr so that I can implement
        one BY MYSELF
  - [ ] complete this exercise, QUICKLY!
*/

int main()
{
  try {
    std::cout << "\n";
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