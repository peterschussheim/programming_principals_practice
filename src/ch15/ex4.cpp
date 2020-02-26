#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

/*
  Graph a sine (sin()), a cosine (cos()), the sum of those (sin(x)+cos(x)), and
  the sum of the squares of those ( sin(x)*sin(x)+cos(x)*cos(x) ) on a single
  graph. Do provide axes and labels.
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

  Simple_window win{Point{100, 100}, xmax, ymax, "Chapter 15 exercise 4"};

  // Setup axis with 1 'notch' equal to 20 pixels
  Axis x{Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
  Axis y{Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
  x.set_color(Color::black);
  y.set_color(Color::black);

  win.attach(x);
  win.attach(y);

  // Functions to graph
  Func cosine{[](double x) { return cos(x); },
              r_min,
              r_max,
              orig,
              n_points,
              x_scale,
              y_scale};
  Func sine{[](double x) { return sin(x); },
            r_min,
            r_max,
            orig,
            n_points,
            x_scale,
            y_scale};
  Func sum_sin_cos{[](double x) { return cos(x) + sin(x); },
                   r_min,
                   r_max,
                   orig,
                   n_points,
                   x_scale,
                   y_scale};
  Func sq_sum{[](double x) { return cos(x) * cos(x) + sin(x) * sin(x); },
              r_min,
              r_max,
              orig,
              n_points,
              x_scale,
              y_scale};

  cosine.set_color(Color::blue);
  sine.set_color(Color::dark_yellow);
  sum_sin_cos.set_color(Color::dark_magenta);
  sq_sum.set_color(Color::green);

  // function labels
  Text cosine_label{Point{470, y_orig + y_orig / 2 - 110}, "cosine(x)"};
  Text sine_label{Point{55, y_orig + y_orig / 2 - 150}, "sin(x)"};
  Text sum_label{Point{420, y_orig + y_orig / 2 - 190}, "sin(x) + cos(x)"};
  Text sq_sum_label{Point{40, y_orig + y_orig / 2 - 190},
                    "sin(x)*sin(x) + cos(x)*cos(x)"};
  cosine_label.set_color(Color::blue);
  sine_label.set_color(Color::dark_yellow);
  sum_label.set_color(Color::dark_magenta);
  sq_sum_label.set_color(Color::green);

  win.attach(sum_sin_cos);
  win.attach(sq_sum);
  win.attach(cosine);
  win.attach(sine);
  win.attach(cosine_label);
  win.attach(sine_label);
  win.attach(sum_label);
  win.attach(sq_sum_label);
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