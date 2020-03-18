#include <iostream>
#include "Utils.h"

using namespace std;

/*
  Write a function, int strcmp(const char* s1, const char* s2) , that compares
  C-style strings. Let it return a negative number if s1 is lexicographically
  before s2 , zero if s1 equals s2 , and a positive number if s1 is lexicograph-
  ically after s2 . Do not use any standard library functions. Do not use
  subscripting; use the dereference operator * instead.
*/

/*
  compares two C-style strings at a time using lexicographic ordering.

  Returns:
    -1 if s1 < s2
    0 if s1 == s2
    1 if s1 > s2
*/
int strcmp(const char* s1, const char* s2) {}

int main()
{
  try {
    keep_window_open();
    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}