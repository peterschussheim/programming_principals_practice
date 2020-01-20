#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

using namespace std;

int main() {
  cout << "Enter two integers, hit 'enter' after typing each\n";
  double num1;
  double num2;
  while (cin >> num1, cin >> num2) {
    double smallest = num1 < num2 ? num1 : num2;
    double largest = num1 > num2 ? num1 : num2;

    if (num1 == num2) {
      cout << "the numbers are equal\n";
    } else {
      cout << "the smaller value is: " << smallest << "    "
           << "the larger value is: " << largest << "\n";

      double diff = largest - smallest;
      if (diff < (1.0 / 100)) {
        cout << "the numbers are almost equal\n";
      }
    }
  }
}
