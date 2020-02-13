/*
  Peter Schussheim
  02/11/20

  Programming Principles and Practice
*/
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

/*
  Exercise 2:

  Draw a box with rounded corners. Define a class Box , consisting of four
  lines and four arcs.
*/

int main()
{
  try {
    Point tl{100, 100};
    Simple_window win{tl, 800, 800, "Arcs"};

    Graph_lib::Arc a1{Point{150, 100}, 100, 50, 45, 175};
    a1.set_color(Color::blue);
    Graph_lib::Arc a2{Point{150, 150}, 50, 90, 10, 170};
    a2.set_color(Color::dark_yellow);
    Graph_lib::Arc a3{Point{150, 200}, 100, 50, 45, 175};
    a3.set_color(Color::red);

    /*win.attach(a1);
    win.attach(a2);
    win.attach(a3);*/

    Box sharp_box{Point{300, 50}, 100, 80};  // regular box with sharp edges
    sharp_box.set_color(Color::blue);

    Box rounded_box{Point{400, 150}, 200, 200, 25};
    rounded_box.set_color(Color::red);
    rounded_box.set_fill_color(Color::blue);

    win.attach(sharp_box);
    win.attach(rounded_box);

    Arrow arrow1{Point{100, 500}, Point{400, 450}};
    arrow1.set_color(Color::dark_green);
    win.attach(arrow1);

    Graph_lib::Rectangle rect1(Point(200, 200), 150, 150);
    rect1.set_color(Color::blue);
    win.attach(rect1);
    Arrow nwr(nw(rect1), Point(nw(rect1).x - 30, nw(rect1).y - 30));
    win.attach(nwr);
    Arrow nr(n(rect1), Point(n(rect1).x, n(rect1).y - 30));
    win.attach(nr);
    Arrow ner(ne(rect1), Point(ne(rect1).x + 30, ne(rect1).y - 30));
    win.attach(ner);
    Arrow er(e(rect1), Point(e(rect1).x + 30, e(rect1).y));
    win.attach(er);
    Arrow ser(se(rect1), Point(se(rect1).x + 30, se(rect1).y + 30));
    win.attach(ser);
    Arrow sr(s(rect1), Point(s(rect1).x, s(rect1).y + 30));
    win.attach(sr);
    Arrow swr(sw(rect1), Point(sw(rect1).x - 30, sw(rect1).y + 30));
    win.attach(swr);
    Arrow wr(w(rect1), Point(w(rect1).x - 30, w(rect1).y));
    win.attach(wr);
    Arrow cr(center(rect1), Point(center(rect1).x + 15, center(rect1).y + 15));
    win.attach(cr);
    nwr.set_color(Color::blue);
    nr.set_color(Color::red);
    ner.set_color(Color::yellow);
    er.set_color(Color::green);
    ser.set_color(Color::cyan);
    sr.set_color(Color::black);
    swr.set_color(Color::blue);
    wr.set_color(Color::dark_yellow);
    cr.set_color(Color::dark_cyan);

    win.wait_for_button();
    keep_window_open("~");
    return 0;
  }
  catch (exception& e) {
    cerr << e.what();
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "unhandled exeption\n";
    keep_window_open("~");
    return 2;
  }
}