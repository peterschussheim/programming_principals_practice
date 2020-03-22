#include <iostream>
#include "Utils.h"

/*
  Rewrite all the functions in §18.7 to use the approach of making a back-
  ward copy of the string and then comparing; for example, take "home" ,
  generate "emoh" , and compare those two strings to see that they are
  different, so home isn’t a palindrome.
*/

int main()
{
  try {
    keep_window_open();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}