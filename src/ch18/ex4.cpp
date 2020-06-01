#include "std_lib_facilities.h"
#include <iostream>
//#include "Utils.h"

using namespace std;

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

  char* p_copy = copy;  // get a pointer to thenew block of memory
  while (*s) {          // while s isn't null
    *p_copy++ = *s++;
  }

  *p_copy = 0;  // terminate the copied string
  return copy;
}

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

/*
  compares two C-style strings at a time using lexicographic ordering.

  Returns:
    -1 if s1 < s2 OR s2 longer than s1
    0 if s1 == s2
    1 if s1 > s2 OR s2 shorter than s1
*/
int strcmp(const char* s1, const char* s2)
{
  while (*s1) {
    if (!*s2) return 1;
    if (*s1 < *s2) return -1;
    if (*s1 > *s2) return 1;
    ++s1;
    ++s2;
  }
  if (*s2) return -1;  // true when s2 is longer than s1
  return 0;
}

/*
    TODO:

  - [ ] Consider what happens if you give strdup(), findx(), and strcmp()
        an argument that is not a C-style string. Try it!

  - [ ] First figure out how to get a char* that doesn't point to a
        zero-terminated array of characters and then use it
        (never do this in real non-experimental code; it can create havoc).

  - [ ] Try it with free-store-allocated and stack-allocated fake C-style
        strings. If the results still look reasonable, turn off debug mode.
        Redesign and re-implement those three functions so that they take
        another argument giving the maximum number of elements allowed in
        argument strings.

  - [ ] Then, test that with correct C-style strings and �bad� strings.
*/

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