#include "GUI.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;
using namespace std;

/*
   Make an “analog clock,” that is, a clock with hands that move. You get the
   time of day from the operating system through a library call. A major part
   of this exercise is to find the functions that give you the time of day and
   a way of waiting for a short period of time (e.g., a second for a clock tick)
   and to learn to use them based on the documentation you found. Hint:
   clock() , sleep().

   NOTE: This exercise is not yet complete.  Currently, it draws a circle and
   the vector of minute markers but does NOT draw the hands and does not update
   as a clock should.
*/

int main()
{
  try {
    Simple_window win{Point{100, 100}, 600, 600, "Analog Clock"};
    Clock c{Point{250, 250}, 150};
    win.attach(c);

    for (int i = 0; i < 3; ++i) {
      Sleep(1000);
      c.increase_time();
      c.update_hands();
      win.redraw();
    }
    win.wait_for_button();
    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << '\n';
    return 1;
  }

  catch (...) {
    cerr << "Unhandled exception\n";
    return 2;
  }
}