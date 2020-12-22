// Make a list of words that can be spelled with hexadecimal notation.
// Read 0 as o, read 1 as l, read 2 as to, etc.; for example, Foo1 and Beef.
// Kindly eliminate vulgarities from the list before submitting it for grading.

//------------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

//------------------------------------------------------------------------------

// substitution map
// Hex characters: 0123456789ABCDEF
//
// clang-format off
std::map<char,std::string> sub{
  {'0', "o"},
  {'1', "l"},
  {'2', "to"},
  {'3', ""}, // eliminate?
  {'4', "for"},
  {'5', "s"},
  {'6', "g"}, // eliminate?
  {'7', "T"},
  {'8', "ate"},
  {'9', "g"}
};
// clang-format on

int main() { return 0; }