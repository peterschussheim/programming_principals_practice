#include "Utils.h"

using namespace std;

/*
  Write a function, char* findx(const char* s, const char* x) , that finds the
  first occurrence of the C-style string x in s.

  If we think about the complexity of the implementation below,
  how would we go about proving it?  Let's try to think of a worst-case
  example, such as a string s equal to length 5 and a string x of length 1;

  Assume for a moment that we know the first occurance of x in s and that
  location is the last index in s (last char, NOT the null terminator);
  Additionally, let's assume that the length of s is a variable n and the
  length of x is a variable called m.

  In this example, we'd need to perform n + m work since we have to scan all
  of s and all of x to find the result.
*/
const char* findx(const char* s, const char* x)
{
  // return null if unable to find
  const char* result;
  int i = 0, j = 0;  // i tracks s and j tracks x

  while (s[i] && x[j]) {  // loop until we encounter nullptr
    if (s[i] != x[j]) {   // have not yet found start of x in s
      ++i;
    }
    else {
      // found start
      result = &s[i];  // get the address of the potential match
      while (s[i] == x[j]) {
        ++i;
        ++j;
      }
      return result;
    }
  }

  return nullptr;  // target not found in s
}

void test(const char* s, const char* x)
{
  const char* first_occurance = findx(s, x);
  cout << "Searching for string \"" << x << "\" in c-string \"" << s << "\"\n";

  if (first_occurance) {
    cout << "found the first occurance of "
         << "\"" << x << "\""
         << " at index " << &first_occurance << ".\n";
  }
  else {
    cout << "could not find x in s.\n";
  }
}

int main()
{
  try {
    char ss[] = "oband";
    char xx[] = "ban";
    test(ss, xx);
    cout
        << "\n------------------------------------------------------------\n\n";
    char ss2[] = "coober";
    char xx2[] = "dewey";
    test(ss2, xx2);

    cout
        << "\n------------------------------------------------------------\n\n";

    char ss3[] = "struct";
    char xx3[] = "duct";
    test(ss3, xx3);

    cout
        << "\n------------------------------------------------------------\n\n";

    char ss4[] = "bend";
    char xx4[] = "end";
    test(ss4, xx4);

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
