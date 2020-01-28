#include "ch7.cpp"
#include "std_lib_facilities.h"
using namespace std;

int main() {
  try {
    // system-defined names:
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);
    define_name("k", 1000);

    calculate();

    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "exception\n";
    keep_window_open("~");
    return 2;
  }
}