#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

using namespace std;

int main() {
  cout << "Enter two integers, hit 'enter' after typing each\n";
  double current;
  cin >> current;
  double largestSoFar = current;
  double smallestSoFar = current;
  while (cin >> current) {
    if (current > largestSoFar) {
      largestSoFar = current;
      cout << current << " largest so far\n";
    }

    if (current < smallestSoFar) {
      smallestSoFar = current;
      cout << current << " smallest so far\n";
    }
  }
}
