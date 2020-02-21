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
  6. Add double square(double x) { return x*x; } to the window.
  7. Add a cosine to the window (don’t write a new function).
  8. Make the cosine blue.
  9. Write a function sloping_cos() that adds a cosine to slope() (as defined
      above) and add it to the window.
*/

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }

void drill_part_2()
{
  using namespace Graph_lib;
  constexpr int xmax = 600;
  constexpr int ymax = 800;
  constexpr int x_orig = 300;
  constexpr int y_orig = 300;
  Point orig{x_orig, y_orig};

  constexpr int r_min = -10;  // range [-10:11)
  constexpr int r_max = 11;
  constexpr int n_points = 400;  // points used in range
  constexpr int x_scale = 20;
  constexpr int y_scale = 20;
  constexpr int xlength = 400;
  constexpr int ylength = 400;

  Text sl{Point{100, y_orig + y_orig / 2 - 80}, "x/2"};
  Simple_window win{Point{100, 100}, xmax, ymax, "Drill Part 2"};
  Function f_one{one, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function f_slope{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function f_square{square, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function cosine{[](double x) { return cos(x); },
                  r_min,
                  r_max,
                  orig,
                  n_points,
                  x_scale,
                  y_scale};
  Function sloped_cosine{[](double x) { return cos(x) + slope(x); },
                         r_min,
                         r_max,
                         orig,
                         n_points,
                         x_scale,
                         y_scale};
  sloped_cosine.set_color(Color::black);
  cosine.set_color(Color::blue);
  f_one.set_color(Color::black);
  f_slope.set_color(Color::black);
  f_square.set_color(Color::black);
  sl.set_color(Color::black);

  win.attach(f_one);
  win.attach(sloped_cosine);
  win.attach(f_slope);
  win.attach(cosine);
  win.attach(f_square);
  win.attach(sl);
  win.wait_for_button();
}

int main()
{
  try {
    // drill_part_1();
    drill_part_2();
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

// void drill_part_1()
//{
//  constexpr int xmax = 600;
//  constexpr int ymax = 800;
//  constexpr int x_orig = 300;
//  constexpr int y_orig = 300;
//  Point orig{x_orig, y_orig};
//  string label = "1 = = 20 pixels";
//  constexpr int r_min = -10;  // range [-10:11)
//  constexpr int r_max = 11;
//  constexpr int n_points = 400;  // points used in range
//  constexpr int x_scale = 30;
//  constexpr int y_scale = 30;
//  constexpr int xlength = 400;
//  constexpr int ylength = 400;
//
//  Point tl{100, 100};
//  Simple_window win{tl, xmax, ymax, "Function graphs."};
//  Axis x{Axis::x, Point{20, y_orig}, xlength, xlength / x_scale, label};
//  Axis y{Axis::y, Point{x_orig, ylength + 20}, ylength, ylength / y_scale,
//         label};
//  x.set_color(Color::red);
//  y.set_color(Color::red);
//  win.attach(x);
//  win.attach(y);
//  win.wait_for_button();
//}