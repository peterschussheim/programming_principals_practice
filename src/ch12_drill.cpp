#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {
  Point tl{100, 100};  // top left
  Simple_window win(tl, 600, 400, "Canvas");

  Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
  xa.set_color(Color::black);
  win.attach(xa);
  win.set_label("Canvas #2");

  Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
  ya.set_color(Color::black);
  ya.label.set_color(Color::blue);
  win.attach(ya);
  win.set_label("Canvas #3");

  win.wait_for_button();
}
