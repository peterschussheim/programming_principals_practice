#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

using namespace std;

int square(int x);

int square(int x) {
  int result = 0;
  for (int count = x; count > 0; --count) {
    result += x;
  }

  return result;
}

int main() {
  int val;
  cout << "Enter an integer to square: \n";
  cin >> val;
  cout << "The square of " << val << " is " << square(val) << "\n";
}
