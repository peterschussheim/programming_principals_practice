#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

// Function which accepts an amount of currency as a double
// and a currency to convert from.
// Ex: convert_to_usd(3.33, 'k')
// currency can be either 'y' for yen or 'k' for kroner
int main() {
  constexpr double y_to_usd = 0.0091;
  constexpr double k_to_usd = 0.11;
  double amount = 1;
  char unit = ' ';

  cout << "Please enter an amount followed by a unit (y for yen or k for kroner):\n";
  cin >> amount >> unit;

  if (unit == 'y') {
    cout << amount << " yen == $" << amount * y_to_usd << "\n";
  } else if (unit == 'k') {
    cout << amount << " kroner == $" << amount * k_to_usd << "\n";
  } else {
    cout << "Sorry, I don't a currency unit called '" << unit << "'\n";
  }
}
