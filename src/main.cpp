#include "ch7.cpp"
#include "std_lib_facilities.h"
using namespace std;

int main() {
  try {
    calculate();
    return 0;
  } catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >> c && c != ';')
      ;
    return 1;
  } catch (...) {
    cerr << "exception\n";
    char c;
    while (cin >> c && c != ';')
      ;
    return 2;
  }
}