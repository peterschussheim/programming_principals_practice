#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

// get the relevant Leibniz term in the sequence w correct sign
double term(int n)
{
  int denominator = 2 * n + 1;
  denominator *= n % 2 == 0 ? 1 : -1;
  return 1.0 / denominator;
}

double leibniz(int n)
{
  double sum = 0;
  for (int i = 0; i <= n; ++i) {  // sum terms upto n
    sum += term(i);
  }

  return sum;
}

/*
  “Animate” (as in §15.5) the series 1–1/3+1/5–1/7+1/9–1/11+ . . . .
  It is known as Leibniz’s series and converges to pi/4.
*/
void exercise()
{
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

  Point tl{100, 100};
  Simple_window win{tl, 600, 800, "Exercise 5"};

  for (int n = 0; n < 20; ++n) {
    ostringstream ss;
    ss << "exp approximation: n==" << n;
    win.set_label(ss.str());
    // get next approximation
    Function e{[](double n) {return leibniz(n); },
               r_min,
               r_max,
               orig,
               200,
               x_scale,
               y_scale};
    win.attach(e);
    win.wait_for_button();
    win.detach(e);
  }
  /*for (int n = 0; n < 50; ++n) {
    Function leib{[n](double) {return leibniz(n); },
                  r_min,
                  r_max,
                  orig,
                  200,
                  x_scale,
                  y_scale};
    win.attach(leib);
    win.wait_for_button();
    win.detach(leib);
  }*/
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