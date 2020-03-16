#include "Utils.h"
#include <iostream>

/*
  my implementation of strlen.
  Given a const pointer to a char,
  return an integer with the length of s.

  NOTE: this function is intended to be used with
  c-style strings and returns the length of the actual string,
  without the 0 terminator.
*/
int c_string_length(const char* s)
{
  int len = 0;
  while (s[len] != 0) { ++len; }

  return len;
}

/*
  Write a function, char* strdup(const char*) , that copies a C-style string
  into memory it allocates on the free store. Do not use any standard library
  functions.
*/
char* strdup(const char* s)
{
  int n = c_string_length(s);
  char* ptr = new char[n + 1];  // allocate n+1 memory

  for (int i = 0; s[i]; ++i) {  // loop and copy into new block
    ptr[i] = s[i];
  }

  // terminate string with zero
  ptr[n] = 0;

  /*
    WHY is this corrupting the heap????
    where should free be called?

    I was under the impression that as an implementor, we should
    be responsible for calling the delete operator whenever we use the
    new operator which is why I am attemping to call delete on s as shown
    below, however, this appears to corrupt the heap as VS crashes.
  */
  // delete s;

  return ptr;
}

int main()
{
  try {
    const char t_1[] = {"Douglass"};
    char* copy_t_1 = strdup(&t_1[0]);

    std::cout << "Original (on stack): " << t_1 << " at location: \t" << &t_1
              << '\n';
    std::cout << "Copy (on free store): " << copy_t_1 << " at location: \t"
              << &copy_t_1 << '\n';

    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
                 "~~~~~~\n\n";

    const char* str_2 = "hello";
    char* copy_str_2 = strdup(str_2);
    std::cout << "Original (on stack): " << str_2 << " at location: \t"
              << &str_2 << '\n';

    std::cout << "Copy (on free store): " << copy_str_2 << " at location: \t"
              << &copy_str_2 << '\n';

    delete[] copy_t_1;
    delete copy_str_2;
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
