#include "ch5.cpp"
#include "std_lib_facilities.h"
using namespace std;

int main() {
  constexpr double abs_zero_celsius = -273.15;
  double c = 0;
  cout << "enter a temperature\n";
  cin >> c;
  if (c < abs_zero_celsius) {
    cerr << "please enter a temperature higher than -273.15\n";
    keep_window_open();
    return 1;
  } else {
    double k = ctok(c);
    cout << k << '\n';
    keep_window_open();
  }
}
