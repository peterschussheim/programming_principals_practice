#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

using namespace std;
// Using a while loop, write out a table of chars
// and their int mapping.
// EX:
//
// a  97
// b  98
// z  122
int main() {
  // 48-57 for digits
  cout << "Digits\n";
  for (char start = 47; start < 57; ++start) {
    cout << char(start + 1) << "\t" << int(start + 1) << "\n";
  }

  cout << "\n";
  // 65 - 90 for uppercase
  cout << "Uppercase Letters\n";
  for (char start = 64; start < 90; ++start) {
    cout << char(start + 1) << "\t" << int(start + 1) << "\n";
  }

  cout << "\n";
  cout << "Lowercase Letters\n";
  for (char start = 96; start < 122; ++start) {  // stop at char 'z'
    cout << char(start + 1) << "\t" << int(start + 1) << "\n";
  }
}
