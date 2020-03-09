#include "Utils.h"

/*
  Write a function, char* findx(const char* s, const char* x) , that finds the
  first occurrence of the C-style string x in s.
*/
char* findx(const char* s, const char* x)
{
  // return null if unable to find
  //
}

int main()
{
  try {
    const char* ss = "oband";
    const char* xx = "ban";

    char* first_occurance = findx(ss, xx);
    keep_window_open("~");
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled error\n";
    keep_window_open("~");
    return 2;
  }

  return 0;
}
