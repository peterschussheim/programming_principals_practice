#include <iostream>
//#include "Utils.h"
#include "std_lib_facilities.h"

using namespace std;

/*
  Write a function, char* strdup(const char*) , that copies a C-style string
  into memory it allocates on the free store. Do not use any standard li-
  brary functions. Do not use subscripting; use the dereference operator *
  instead.
*/

/*
  copies a C-style string into memory allocated on the free store.
  ONLY use the dereference operator *; no subscripting.

  Caller must use delete[] operator upon completion.
*/
char* strduplicate(const char* s)
{
  // get the length of arg s
  int n = 0;
  const char* p = s;
  while (*p++) ++n;

  char* copy = new char[n + 1];  // n+1 memory for terminating 0

  char* p_copy = copy;  // get a pointer to th enew block of memory
  while (*s) {          // while s isn't null
    *p_copy++ = *s++;
  }

  *p_copy = 0;  // terminate the copied string
  return copy;
}

/*
  accepts a pointer to a C-style string and iterates via dereferencing s to
  prevent accessing nullptr, and prints to cout the value while incrementing
  s via pointer arithmetic.
*/
void print_str(const char* s)
{
  if (s == nullptr) error("Cannot print empty string!");
  while (*s) cout << *s++;

  cout << '\n';
}

int main()
{
  try {
    // const char* ch = "computer";
    const char ch[] = "computer";  // alternative definition of C-style string
    cout << "ch: ";
    print_str(ch);

    cout << "ch_cpy: ";
    char* ch_cpy = strduplicate(ch);
    print_str(ch_cpy);
    delete[] ch_cpy;

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