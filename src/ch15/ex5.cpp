#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

/*
  “Animate” (as in §15.5) the series 1–1/3+1/5–1/7+1/9–1/11+ . . . .
  It is known as Leibniz’s series and converges to pi/4.
*/

void exercise() {}

int main()
{
  try {
    exercise();
    keep_window_open("~");
    return 0;
  }
  catch (exception& e) {
    cerr << e.what();
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "Unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}