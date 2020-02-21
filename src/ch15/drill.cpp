#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

/*
  In the following, use a separate Shape for each function to be graphed:
  1. Graph the function double one(double x) { return 1; } in the range [–10,11]
      with (0,0) at (300,300) using 400 points and no scaling (in the window).
  2. Change it to use x scale 20 and y scale 20.
  3. From now on use that range, scale, etc. for all graphs.
  4. Add double slope(double x) { return x/2; } to the window.
  5. Label the slope with a Text "x/2" at a point just above its bottom left end
      point.
*/

double one(double x) { return 1; }

void drill_part_1()
{
  constexpr int xmax = 600;
  constexpr int ymax = 800;
  constexpr int x_orig = 300;
  constexpr int y_orig = 300;
  Point orig{x_orig, y_orig};
  string label = "1 = = 20 pixels";
  constexpr int r_min = -10;  // range [-10:11)
  constexpr int r_max = 11;
  constexpr int n_points = 400;  // points used in range
  constexpr int x_scale = 30;
  constexpr int y_scale = 30;
  constexpr int xlength = 400;
  constexpr int ylength = 400;

  Point tl{100, 100};
  Simple_window win{tl, xmax, ymax, "Function graphs."};
  Axis x{Axis::x, Point{20, y_orig}, xlength, xlength / x_scale, label};
  Axis y{Axis::y, Point{x_orig, ylength + 20}, ylength, ylength / y_scale,
         label};
  x.set_color(Color::red);
  y.set_color(Color::red);
  win.attach(x);
  win.attach(y);
  win.wait_for_button();
}

int main()
{
  try {
    using namespace Graph_lib;
    drill_part_1();
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