#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

/*
  2. Define a class Fct that is just like Function except that it stores its
  constructor arguments. Provide Fct with “reset” operations, so that you can
  use it repeatedly for different ranges, different functions, etc.

  3. Modify Fct from the previous exercise to take an extra argument to con-
  trol precision or whatever. Make the type of that argument a template
  parameter for extra flexibility.
*/

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }

void exercise()
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

  Simple_window win{Point{100, 100}, xmax, ymax,
                    "Chapter 15 exercises 2 and 3"};

  // Setup axis with 1 'notch' equal to 20 pixels
  Axis x{Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
  Axis y{Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
  x.set_color(Color::black);
  y.set_color(Color::black);
  win.attach(x);
  win.attach(y);

  // Functions to graph
  Func f_one{one, r_min, r_max, orig, n_points, x_scale, y_scale};
  Func f_slope{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
  Func f_square{square, r_min, r_max, orig, n_points, x_scale, y_scale};
  Func cosine{[](double x) { return cos(x); },
              r_min,
              r_max,
              orig,
              n_points,
              x_scale,
              y_scale};
  cosine.set_color(Color::blue);
  f_one.set_color(Color::red);
  f_slope.set_color(Color::yellow);
  f_square.set_color(Color::dark_green);
  // f_slope.reset_precision(34);
  // function labels
  Text wun{Point{100, y_orig + y_orig / 2 - 190}, "1"};
  Text sl{Point{100, y_orig + y_orig / 2 - 80}, "x/2"};
  Text sq{Point{220, y_orig + y_orig / 2 - 280}, "x*x"};
  Text cosine_label{Point{470, y_orig + y_orig / 2 - 110}, "cosine"};
  wun.set_color(Color::black);
  sl.set_color(Color::black);
  sq.set_color(Color::black);
  cosine_label.set_color(Color::black);

  win.attach(f_one);
  win.attach(f_slope);
  win.attach(f_square);
  win.attach(cosine);
  win.attach(f_one);
  win.attach(f_slope);
  win.attach(f_square);
  win.attach(wun);
  win.attach(sl);
  win.attach(sq);
  win.attach(cosine_label);
  win.wait_for_button();
}

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