#include "ch5.cpp"
#include "std_lib_facilities.h"
using namespace std;

int main() {
  try {
    double c = 0;
    cout << "enter a temperature\n";
    cin >> c;
    double k = ctok(c);
    cout << k << '\n';
    keep_window_open();
    return 0;                   // 0 indicates success
  } catch (runtime_error& e) {  // catch runtime errors from invalid arguments
    cerr << "runtime error: " << e.what() << '\n';
    keep_window_open();
    return 1;  // 1 indicates failure
  }
}
