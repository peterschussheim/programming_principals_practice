/*
  Peter Schussheim
  02/11/20

  Programming Principles and Practice
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

/*
  Exercise 1:

  Define a class Arc, which draws a part of an ellipse. Hint: fl.arc().
*/

int main()
{
  try {
    Point tl{100, 100};
    Simple_window win{tl, 800, 800, "Arcs"};

    Graph_lib::Arc a1{Point{150, 100}, 100, 50, 45, 175};
    a1.set_color(Color::blue);
    Graph_lib::Arc a2{Point{150, 150}, 50, 90, 10, 170};
    a2.set_color(Color::dark_yellow);
    Graph_lib::Arc a3{Point{150, 200}, 100, 50, 45, 175};
    a3.set_color(Color::red);

    win.attach(a1);
    win.attach(a2);
    win.attach(a3);
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
    cerr << "unhandled exeption\n";
    keep_window_open("~");
    return 2;
  }
}