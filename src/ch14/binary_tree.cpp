#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

int main()
{
  try {
    Point tl{100, 100};
    Simple_window win{tl, 800, 800, "Binary Tree"};
    Binary_tree zero_levels{Point{150, 150}, 0};

    win.attach(zero_levels);
    win.wait_for_button();
    keep_window_open("~");
    return 0;
  }
  catch (exception& e) {
    cerr << e.what();
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}