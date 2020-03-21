#include <iostream>
#include "Utils.h"

using namespace std;

/*
  Write versions of the cat_dot() s from the previous exercises to take
  C-style strings as arguments and return a free-store-allocated C-style string
  as the result. Do not use standard library functions or types in the im-
  plementation. Test these functions with several strings. Be sure to free
  (using delete ) all the memory you allocated from free store (using new ).
  Compare the effort involved in this exercise with the effort involved for
  exercises 5 and 6
*/

char* cat_dot(const char* s1, const char* s2, char sep = '/.')
{
  // get length of s1 and s2 to allocate new memory on freestore
  int len_s1 = string_length(s1);
  int len_s2 = string_length(s2);

  // Note the 2; we need this for the separator AND null terminator
  // allocate (len(s1) + len(s2) + 2)
  char* result = new char[len_s1 + len_s1 + 2];
  char* p_result = result;  // get a pointer to new block of memory

  while (*s1) {  // copy s1 into result
    *p_result++ = *s1++;
  }

  *p_result++ = sep;  // increment p_result to insert separator

  while (*s2) {  // copy s2 into result
    *p_result++ = *s2++;
  }

  *p_result = 0;  // terminate result with nullptr

  return result;
}

int main()
{
  try {
    char* test_1 = cat_dot("Niels", "Bohr");
    cout << "default separator: " << test_1 << '\n';
    delete[] test_1;

    char* test_2 = cat_dot("Niels", "Bohr", '/*');
    cout << "user-defined separator: " << test_2 << '\n';
    delete[] test_2;

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