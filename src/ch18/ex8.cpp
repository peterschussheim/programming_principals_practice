#include <iostream>
#include <algorithm>
#include <string>

std::istream& read_word(std::istream& is, char* buffer, int max)
{
  // read at most max - 1 chars from is into buffer
  is.width(max);
  is >> buffer;  // read whitespace-terminated word into buffer
  return is;
}

/*
  Rewrite all the functions in 18.7 to use the approach of making a back-
  ward copy of the string and then comparing; for example, take "home" ,
  generate "emoh" , and compare those two strings to see that they are
  different, so home isn't a palindrome.
*/

bool is_palindrome(const std::string& s)
{
  std::string reversed = s;  // make a copy
  /*
    Not entirely sure which is more readible, using the iterator head
    or calling the std::string begin and end methods:

    std::reverse(std::begin(reversed), std::end(reversed));
  */
  std::reverse(reversed.begin(), reversed.end());

  /*for (int i = 0; i < s.size(); ++i) {
    if (s[i] != reversed[i]) return false;
  }*/

  return reversed == s ? true : false;
}

// arrays, bracket operator
bool is_palindrome(const char s[], int n)
{
  // create a backward copy
  char* s_rev = new char[n + 1];  // why do we have to allocate on free store?
  s_rev[n] = 0;                   // terminate the copied string

  for (int i = 0; i < n; ++i) s_rev[n - 1 - i] = s[i];

  if (strcmp(s, s_rev)) {
    delete[] s_rev;
    return false;
  }

  delete[] s_rev;
  return true;
}

// arrays and pointers
// note: this is not exactly the same idea as making a copy in reverse order
bool is_palindrome(const char* first, const char* last)
{
  if (first < last) {
    if (*first != *last) return false;
    return is_palindrome(first + 1, last - 1);
  }
  return true;
}

int main()
{
  try {
    std::cout << "is_palindrome() using std::string:\n";
    std::cout << (is_palindrome("home") == false ? "false\n" : "true\n");
    std::cout << (is_palindrome("boob") == false ? "false\n" : "true\n");
    std::cout << (is_palindrome("toot") == false ? "false\n" : "true\n");
    std::cout << (is_palindrome("pip") == false ? "false\n" : "true\n");

    std::cout << "\nis_palindrome() using C-style strings:\n";
    const int max = 128;
    char s[max];
    while (read_word(std::cin, s, max) && strcmp(s, "quit")) {
      std::cout << s << " is";
      // recall that strlen(s) return the number of chars in the array
      // after the call of read_word()
      if (!is_palindrome(s, std::strlen(s))) std::cout << " not";
      std::cout << " a palindrome\n";
    }

    std::cout << "\nis_palindrome() using pointers:\n";

    while (read_word(std::cin, s, max) && strcmp(s, "quit")) {
      std::cout << s << " is";
      if (!is_palindrome(&s[0], &s[strlen(s) - 1])) std::cout << " not";
      std::cout << " a palindrome\n";
    }

    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;

    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";

    return 2;
  }
}
