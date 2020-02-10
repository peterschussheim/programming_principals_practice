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

/*
  There are a few ways to draw a tic-tac-toe board.
  For this exercise, I chose the simplest implementation
  I could think of; create 9 rectangles each equal in height/width,
  offset each "square" appropriately, in this case, by 50 pixels.
  After this, we need to alternate a square's color.

  A more flexible and robust solution would be to seperate creation of
  squares and the 'laying' out of the squares.  It might be worthwhile to
  use a proper Matrix class to represent an n*n board.  Ex, create a 3x3 matrix,
  where each "cell" contains some data structure representing an individual
  square's properties or even better, store square objects in
  the matrix: coordinates, color, square status(if we were playing a real game,
  we'd want to know if a square is marked and if so, with what symbol).

  We can save that for another exercise.
*/
void ttt_board() {
  // draw the board
  // draw inside the board two horizontal lines and two vertical lines
  Point tl{100, 100};

  // row 1
  Graph_lib::Rectangle sq0{Point{100, 100}, 50, 50};
  sq0.set_fill_color(Color::white);
  Graph_lib::Rectangle sq1{Point{150, 100}, 50, 50};
  sq1.set_fill_color(Color::red);
  Graph_lib::Rectangle sq2{Point{200, 100}, 50, 50};
  sq2.set_fill_color(Color::white);
  // row 2
  Graph_lib::Rectangle sq3{Point{100, 150}, 50, 50};
  sq3.set_fill_color(Color::red);
  Graph_lib::Rectangle sq4{Point{150, 150}, 50, 50};
  sq4.set_fill_color(Color::white);
  Graph_lib::Rectangle sq5{Point{200, 150}, 50, 50};
  sq5.set_fill_color(Color::red);
  // row 3
  Graph_lib::Rectangle sq6{Point{100, 200}, 50, 50};
  sq6.set_fill_color(Color::white);
  Graph_lib::Rectangle sq7{Point{150, 200}, 50, 50};
  sq7.set_fill_color(Color::red);
  Graph_lib::Rectangle sq8{Point{200, 200}, 50, 50};
  sq8.set_fill_color(Color::white);

  Simple_window win{tl, 800, 600, "Tic-Tac-Toe Board"};

  win.attach(sq0);
  win.attach(sq1);
  win.attach(sq2);
  win.attach(sq3);
  win.attach(sq4);
  win.attach(sq5);
  win.attach(sq6);
  win.attach(sq7);
  win.attach(sq8);
  win.wait_for_button();
}

/*
  Draw a red 1/4 inch frame around a rectangle
  that is 3/4 the height of my screen and 2/3 the width.

  How do we determine hopw to construct shapes based off screen size?

  Notice that we are asked to draw a red 1/4 INCH frame around the rect.
  To do this, we need to think about how many pixels are in an inch.
  Unfortunately, this is dependent on the physical screen's dimensions.

  To calculate this, we use the formula provided at
  https://en.wikipedia.org/wiki/Pixel_density#Calculation_of_monitor_PPI
  we can estimate my 27 inch monitor to be have 3840×2160 pixels which
  when used in the functions describes in the article,
  give us 163 pixels per inch.  For convenience, let's get 1/4 of 163 and round
  up to get 41 pixels for our "frame".
*/
void ex5() {
  Point tl{100, 100};
  Simple_window win{tl, 800, 600, "Exercise #5"};

  const int frame_pixels = 41;                         // pixels per inch for my 27inch monitor
  const int rect_width = std::round(x_max() * 0.666);  // get width of screen
  const int rect_height = std::round(y_max() * 0.75);  // get the height of my screen

  Graph_lib::Closed_polyline frame;
  frame.add(Point{100, 50});
  frame.add(Point{200, 50});
  frame.add(Point{200, 100});
  frame.add(Point{100, 100});
  frame.set_fill_color(Color::red);
  win.attach(frame);
  Graph_lib::Rectangle r{tl, rect_width, rect_height};
  r.set_fill_color(Color::cyan);
  r.set_style(Line_style(Line_style::solid, 5));
  r.set_color(Color::red);
  win.attach(r);

  win.wait_for_button();
}

int main() {
  try {
    // ex1();
    // ex2();
    // ex3();
    // ttt_board();
    ex5();
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
