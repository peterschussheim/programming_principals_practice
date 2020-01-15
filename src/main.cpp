#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

// Function which accepts an amount of currency as a double
// and a currency to convert from.
// Ex: convert_to_usd(3.33, 'k')
// currency can be either 'y' for yen or 'k' for kroner
// Using switch-statements allows us to refactor and add/remove cases
// more easily than using is-statements.
int main() {
  constexpr double jpy_to_usd = 0.0091;
  constexpr double k_to_usd = 0.11;
  constexpr double yuan_to_usd = 0.15;

  double amount = 1;
  char unit = ' ';

  cout << "Please enter an amount followed by a unit (j for yen or k for kroner or y for "
          "yuan):\n";
  cin >> amount >> unit;

  switch (unit) {
    case 'j': {
      cout << amount << " yen == $" << amount * jpy_to_usd << "\n";
      break;
    }
    case 'k': {
      cout << amount << " kroner == $" << amount * k_to_usd << "\n";
      break;
    }
    case 'y': {
      cout << amount << " yuan == $" << amount * yuan_to_usd << "\n";
      break;
    }
    default: {
      cout << "Sorry, I don't a currency unit called '" << unit << "'\n";
      break;
    }
  }
}
