#include "fib.h"
#include "std_lib_facilities.h"

using namespace std;

int main() {
  try {
    // create a vector of fibonacci numbers
    // print vector
    vector<int> v_fib;
    fibonacci(1, 2, v_fib, 40);
    print("Fibonacci number: ", v_fib, true);
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