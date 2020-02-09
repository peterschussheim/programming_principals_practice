#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

void ex1() {
  Point tl{100, 100};
  Simple_window win{tl, 800, 600, "Exercise #1"};

  Graph_lib::Rectangle r{Point{200, 200}, 100, 50};
  r.set_color(Color::blue);
  win.attach(r);

  Graph_lib::Closed_polyline poly_rect;
  poly_rect.add(Point{100, 50});
  poly_rect.add(Point{200, 50});
  poly_rect.add(Point{200, 100});
  poly_rect.add(Point{100, 100});
  poly_rect.set_color(Color::red);
  win.attach(poly_rect);

  win.wait_for_button();
}

void ex2() {
  // draw a 100x30 Rectangle and place the text "Howdy!" inside.
  Point tl{100, 100};
  Graph_lib::Rectangle r{tl, 100, 30};
  Graph_lib::Text t{Point{125, 120}, "Howdy!"};
  r.set_color(Color::red);
  t.set_color(Color::blue);
  Simple_window win{tl, 800, 600, "Exercise #2"};
  win.attach(r);
  win.attach(t);
  win.wait_for_button();
}

void ex3() {
  // draw your initials 150 pixels high, use a thick line and
  // a different color for each letter.
  Point tl{100, 100};
  Graph_lib::Text t_p{Point{125, 120}, "P"};
  t_p.set_font_size(150);
  t_p.set_color(Color::red);
  // t_p.set_style(5);

  Graph_lib::Text t_d{Point{220, 120}, "D"};  // offset each letter by 100 pixels?
  t_d.set_font_size(150);
  t_d.set_color(Color::white);

  Graph_lib::Text t_s{Point{325, 120}, "S"};
  t_s.set_font_size(150);
  t_s.set_color(Color::blue);

  Simple_window win{tl, 800, 600, "Exercise #3"};
  win.attach(t_p);
  win.attach(t_d);
  win.attach(t_s);
  win.wait_for_button();
}

int main() {
  try {
    // ex1();
    // ex2();
    ex3();
    // keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << e.what();
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "unknown error";
    keep_window_open("~");
    return 2;
  }
}
