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

    /*Graph_lib::Arc a1{Point{150, 100}, 100, 50, 45, 175};
    a1.set_color(Color::blue);
    Graph_lib::Arc a2{Point{150, 150}, 50, 90, 10, 170};
    a2.set_color(Color::dark_yellow);
    Graph_lib::Arc a3{Point{150, 200}, 100, 50, 45, 175};
    a3.set_color(Color::red);
    win.attach(a1);
    win.attach(a2);
    win.attach(a3);*/

    Box sharp_box{Point{300, 50}, 100, 80};  // regular box with sharp edges
    sharp_box.set_color(Color::blue);

    Box rounded_box{Point{400, 150}, 200, 200, 25};
    rounded_box.set_color(Color::red);
    rounded_box.set_fill_color(Color::blue);

    /*win.attach(sharp_box);
    win.attach(rounded_box);*/

    // Arrow arrow1{Point{100, 500}, Point{400, 450}};
    // arrow1.set_color(Color::dark_green);
    // win.attach(arrow1);

    // Graph_lib::Rectangle rect1(Point(200, 200), 150, 150);
    // rect1.set_color(Color::blue);
    // win.attach(rect1);
    // Arrow nwr(nw(rect1), Point(nw(rect1).x - 30, nw(rect1).y - 30));
    // win.attach(nwr);
    // Arrow nr(n(rect1), Point(n(rect1).x, n(rect1).y - 30));
    // win.attach(nr);
    // Arrow ner(ne(rect1), Point(ne(rect1).x + 30, ne(rect1).y - 30));
    // win.attach(ner);
    // Arrow er(e(rect1), Point(e(rect1).x + 30, e(rect1).y));
    // win.attach(er);
    // Arrow ser(se(rect1), Point(se(rect1).x + 30, se(rect1).y + 30));
    // win.attach(ser);
    // Arrow sr(s(rect1), Point(s(rect1).x, s(rect1).y + 30));
    // win.attach(sr);
    // Arrow swr(sw(rect1), Point(sw(rect1).x - 30, sw(rect1).y + 30));
    // win.attach(swr);
    // Arrow wr(w(rect1), Point(w(rect1).x - 30, w(rect1).y));
    // win.attach(wr);
    // Arrow cr(center(rect1), Point(center(rect1).x + 15, center(rect1).y +
    // 15)); win.attach(cr); nwr.set_color(Color::blue);
    // nr.set_color(Color::red);
    // ner.set_color(Color::yellow);
    // er.set_color(Color::green);
    // ser.set_color(Color::cyan);
    // sr.set_color(Color::black);
    // swr.set_color(Color::blue);
    // wr.set_color(Color::dark_yellow);
    // cr.set_color(Color::dark_cyan);

    Textbox tb_win{Point{100, 50}, 70, "Window"};
    tb_win.set_fill_color(Color::dark_green);
    win.attach(tb_win);

    Textbox tb_s_win{Point{70, 135}, 130, "Simple_window"};
    tb_s_win.set_fill_color(Color::dark_green);
    tb_s_win.label.set_font(Font::helvetica_bold);
    win.attach(tb_s_win);

    Arrow a1(Graph_lib::n(tb_s_win), Graph_lib::s(tb_win));
    win.attach(a1);

    Textbox tb_ls(Point(200, 50), 85, "Line_style");
    tb_ls.set_fill_color(Color::dark_green);
    tb_ls.label.set_font(Font::helvetica_bold);
    win.attach(tb_ls);

    Textbox tb_col(Point(315, 50), 55, "Color");
    tb_col.set_fill_color(Color::dark_green);
    tb_col.label.set_font(Font::helvetica_bold);
    win.attach(tb_col);

    Textbox tb_pt(Point(340, 135), 52, "Point");
    tb_pt.set_fill_color(Color::dark_green);
    tb_pt.label.set_font(Font::helvetica_bold);
    win.attach(tb_pt);

    Textbox tb_shp(Point(240, 120), 58, "Shape");
    tb_shp.set_fill_color(Color::dark_green);
    tb_shp.label.set_font(Font::helvetica_bold);
    win.attach(tb_shp);

    Textbox tb_ln(Point(50, 210), 50, "Line");
    tb_ln.set_fill_color(Color::dark_green);
    tb_ln.label.set_font(Font::helvetica_bold);
    win.attach(tb_ln);

    Textbox tb_lns(Point(110, 210), 50, "Lines");
    tb_lns.set_fill_color(Color::dark_green);
    tb_lns.label.set_font(Font::helvetica_bold);
    win.attach(tb_lns);

    Textbox tb_plg(Point(170, 210), 70, "Polygon");
    tb_plg.set_fill_color(Color::dark_green);
    tb_plg.label.set_font(Font::helvetica_bold);
    win.attach(tb_plg);

    Textbox tb_ax(Point(250, 210), 40, "Axis");
    tb_ax.set_fill_color(Color::dark_green);
    tb_ax.label.set_font(Font::helvetica_bold);
    win.attach(tb_ax);

    Textbox tb_rect(Point(300, 210), 85, "Rectangle");
    tb_rect.set_fill_color(Color::dark_green);
    tb_rect.label.set_font(Font::helvetica_bold);
    win.attach(tb_rect);

    Textbox tb_txt(Point(395, 210), 45, "Text");
    tb_txt.set_fill_color(Color::dark_green);
    tb_txt.label.set_font(Font::helvetica_bold);
    win.attach(tb_txt);

    Textbox tb_img(Point(450, 210), 55, "Image");
    tb_img.set_fill_color(Color::dark_green);
    tb_img.label.set_font(Font::helvetica_bold);
    win.attach(tb_img);

    Arrow a_ln(n(tb_ln), sw(tb_shp));
    win.attach(a_ln);
    Arrow a_lns(n(tb_lns), Point(sw(tb_shp).x + 10, sw(tb_shp).y));
    win.attach(a_lns);
    Arrow a_plg(n(tb_plg), Point(sw(tb_shp).x + 20, sw(tb_shp).y));
    win.attach(a_plg);
    Arrow a_ax(n(tb_ax), s(tb_shp));
    win.attach(a_ax);
    Arrow a_rect(n(tb_rect), Point(se(tb_shp).x - 20, se(tb_shp).y));
    win.attach(a_rect);
    Arrow a_txt(n(tb_txt), Point(se(tb_shp).x - 10, se(tb_shp).y));
    win.attach(a_txt);
    Arrow a_img(n(tb_img), se(tb_shp));
    win.attach(a_img);

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