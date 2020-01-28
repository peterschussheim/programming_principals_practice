#include "fib.cpp"
#include "std_lib_facilities.h"

using namespace std;

int main() {
  try {
    // create a vector of fibonacci numbers
    // print vector

    vector<int> v_fib;
    fibonacci(1, 2, v_fib, 10);
    print("Fibonacci number: ", v_fib);
    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "unhandled exception\n\n";
    keep_window_open("~");
    return 2;
  }
}