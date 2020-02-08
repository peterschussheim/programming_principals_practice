#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {
  try {
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

    /*
    plot sin() in range [0:100] with (0,0) at (20,150)
    using 1000 points; scale x values by *50, scale y values by *50.
  */
    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
    sine.set_color(Color::magenta);
    win.attach(sine);
    win.set_label("Canvas #4");

    Graph_lib::Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    Graph_lib::Rectangle r{Point{200, 200}, 100, 50};  // top left corner, width, height
    r.set_color(Color::black);
    win.attach(r);
    win.set_label("Canvas #6");

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash, 4));
    win.set_label("Canvas #7");

    Text t{Point{150, 150}, "Hello, cousin Dan!"};
    win.attach(t);
    win.set_label("Canvas #8");

    t.set_font(Font::courier);
    t.set_font_size(20);
    t.set_color(Color::blue);
    win.set_label("Canvas #9");

    Image ii{Point{100, 200}, "..\\resources\\image.jpg", Suffix::jpg};
    win.attach(ii);
    win.set_label("Canvas #10");
    win.resize(600, 400);
    ii.move(100, 200);

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*"
        << win.y_max();
    Text sizes{Point{100, 20}, oss.str()};
    sizes.set_color(Color::dark_cyan);
    Image cal{Point{290, 125}, "..\\resources\\snow_cpp.gif", Suffix::gif};
    cal.set_mask(Point{40, 40}, 200, 150);  // display center part of image
    win.attach(sizes);
    win.attach(cal);
    win.set_label("Canvas #12");

    win.wait_for_button();
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
