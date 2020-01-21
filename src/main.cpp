#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

using namespace std;

int main() {
  double dist;
  string unit;

  cout << "Enter a value including a valid unit."
       << "EX: 12cm || 2.33 m || 9.032in || 44.03 ft\n";
  cout << "When you are finished, enter '|' to exit the program\n";

  while (cin >> dist >> unit) {
    if (unit == "cm") {
      cout << "You entered: " << dist << " and a unit of: " << unit << "\n";
    } else if (unit == "m") {
      cout << "You entered: " << dist << " and a unit of: " << unit << "\n";
    } else if (unit == "in") {
      cout << "You entered: " << dist << " and a unit of: " << unit << "\n";
    } else if (unit == "ft") {
      cout << "You entered: " << dist << " and a unit of: " << unit << "\n";
    } else {
      // Reject any unit not explicitly checked above
      cout << "You entered an illegal unit format: " << unit << "\n";
    }
  }

  keep_window_open();
}
