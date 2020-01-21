#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

using namespace std;

int main() {
  cout << "Enter a value including a valid unit."
       << "EX: 12cm || 2.33 m || 9.032in || 44.03 ft\n";

  cout << "When you are finished, enter '|' to exit the program\n";
  double dist;
  string unit;

  while (cin >> dist >> unit) {
    cout << "You entered: " << dist << " and a unit of: " << unit << "\n";
  }
  keep_window_open();
}
