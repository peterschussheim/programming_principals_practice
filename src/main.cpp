
#include "ch6.cpp"
#include "std_lib_facilities.h"
using namespace std;

int main() try {
  while (cin) {
    Token t = ts.get();
    double val;
    if (t.kind == 'x') break;  // 'x' for quit
    if (t.kind == '=')         // '=' for "print now"
      cout << "=" << val << '\n';
    else
      ts.putback(t);
    val = expression();
  }
  keep_window_open();
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  keep_window_open();
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  keep_window_open();
  return 2;
}