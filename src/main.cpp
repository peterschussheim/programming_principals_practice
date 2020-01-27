#include "ch7.cpp"
#include "std_lib_facilities.h"
using namespace std;

int main() {
  try {
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