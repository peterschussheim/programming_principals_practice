/*
  Write a find-and-replace operation for Document s based on §20.6.2.
*/

//#include "std_lib_facilities.h"
#include "Document.h"
#include <iostream>
#include <string>

// TODO: replace std::find with my own simple implementation
// TODO: Write replace function
// TODO: combine find and replace to make a find and replace method
// TODO: write tests for find and replace functionality

bool match(Text_iterator current, Text_iterator last, const std::string& s)
{
  std::string::const_iterator si = s.begin();  // get an iterator to s
  while (current != last) {
    if (!(*current == *s.begin())) { return false; }
    ++current;
    ++si;
  }

  return false;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last,
                       const std::string& s)
{
  if (s.size() == 0) return last;  // cannot find an empty string
  char first_char = s[0];
  while (true) {
    auto p = std::find(first, last, first_char);
    if (p == last || match(p, last, s)) return p;
    first = ++p;  // look at the next character
  }
}

int main()
{
  try {
    // keep_window_open("");
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    return 2;
  }
}