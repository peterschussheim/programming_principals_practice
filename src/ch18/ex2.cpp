#include <iostream>
//#include "Utils.h"
#include "std_lib_facilities.h"

using namespace std;

/*
  Write a function, char* findx(const char* s, const char* x) , that finds the
  first occurrence of the C-style string x in s . Do not use any standard li-
  brary functions. Do not use subscripting; use the dereference operator *
  instead
*/

char* findx(const char* s, const char* x)
{
  while (*s && *x) {  // while s and x are not null
    if (*s != *x) {   // if we haven't yet found start of x in s
      ++s;            // clarify when we can use *++s instead of ++s
    }
    else {  // found start of sequence
      while (*s == *x) {
        ++s;
        ++x;
      }
      return const_cast<char*>(s);  // how to solve this without expl cast?
    }
  }
  return nullptr;
}

void test(const char* s, const char* x);  // forward declaration

int main()
{
  try {
    const char str[] = "lolas";
    const char target[] = "ola";
    test(str, target);
    cout << '\n';

    const char str_1[] = "windows";
    const char target_1[] = "bra";

    test(str_1, target_1);
    cout << '\n';
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

void print_str(const char* s)
{
  if (s == nullptr) error("Cannot print empty string!");
  while (*s) cout << *s++;

  cout << '\n';
}

void test(const char* s, const char* x)
{
  char* first_occurance = findx(s, x);
  cout << "Searching for string \"" << x << "\" in c-string \"" << s << "\"\n";

  if (first_occurance) {
    cout << "found the first occurance of "
         << "\"" << x << "\""
         << " at location: " << &first_occurance << ".\n";
    cout << "value: " << first_occurance << '\n';
  }
  else {
    cout << "could not find x in s.\n";
  }
}