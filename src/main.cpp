#include "std_lib_facilities.h"
using namespace std;

namespace X {
  int var;
  void print() {
    cout << "X::var: " << var << '\n';
  }
}

namespace Y {
  int var;
  void print() {
    cout << "Y::var: " << var << '\n';
  }
}

namespace Z {
  int var;
  void print() {
    cout << "Z::var: " << var << '\n';
  }
}

int main() {
  try {
    X::var = 7;
    X::print();  // print X's var

    using namespace Y;
    var = 9;
    print();  // print Y's var

    {
      using Z::print;
      using Z::var;
      var = 11;
      print();  // print Z's var
    }
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