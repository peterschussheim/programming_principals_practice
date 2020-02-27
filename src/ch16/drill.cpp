#include <iostream>
#include <sstream>
#include "Lines_window.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window{xy, w, h, title},
      color_menu{Point{x_max() - 70, 30}, 70, 20, Menu::vertical, "color"},
      style_menu{Point{x_max() - 70, 100}, 70, 20, Menu::vertical,
                 "line style"},
      menu_button{Point{x_max() - 80, 30}, 80, 20, "Menu", cb_menu},
      next_button{Point{x_max() - 150, 0}, 70, 20, "Next point", cb_next},
      quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit", cb_quit},
      next_x{Point{x_max() - 310, 0}, 50, 20, "next x:"},
      next_y{Point{x_max() - 210, 0}, 50, 20, "next y:"},
      xy_out{Point{100, 0}, 100, 20, "current (x,y):"}
{
  attach(next_button);
  attach(quit_button);
  attach(next_x);
  attach(next_y);
  attach(xy_out);
  xy_out.put("no point");

  // dynamically attach the relevant buttons to the menu
  color_menu.attach(new Button{Point{0, 0}, 0, 0, "red", cb_red});
  color_menu.attach(new Button{Point{0, 0}, 0, 0, "blue", cb_blue});
  color_menu.attach(new Button{Point{0, 0}, 0, 0, "black", cb_black});
  style_menu.attach(new Button{Point{0, 0}, 0, 0, "-------", cb_solid});
  style_menu.attach(new Button{Point{0, 0}, 0, 0, "- - - -", cb_dash});
  style_menu.attach(new Button{Point{0, 0}, 0, 0, ".......", cb_dot});
  style_menu.attach(new Button{Point{0, 0}, 0, 0, "- . - .", cb_dashdot});
  style_menu.attach(new Button{Point{0, 0}, 0, 0, "-..-..", cb_dashdotdot});

  attach(color_menu);
  color_menu.hide();
  attach(style_menu);
  style_menu.hide();

  attach(menu_button);
  attach(lines);
}

void Lines_window::change(Color c) { lines.set_color(c); }
void Lines_window::change_ls(Line_style ls) { lines.set_style(ls); }

void Lines_window::red_pressed()
{
  change(Color::red);
  hide_menu();
}

//------------------------------------------------------------------------------

void Lines_window::blue_pressed()
{
  change(Color::blue);
  hide_menu();
}

void Lines_window::black_pressed()
{
  change(Color::black);
  hide_menu();
}
//------------------------------------------------------------------------------

void Lines_window::solid_pressed()
{
  change_ls(Line_style::solid);
  hide_menu();
}

//------------------------------------------------------------------------------

void Lines_window::dash_pressed()
{
  change_ls(Line_style::dash);
  hide_menu();
}

//------------------------------------------------------------------------------

void Lines_window::dot_pressed()
{
  change_ls(Line_style::dot);
  hide_menu();
}

//------------------------------------------------------------------------------

void Lines_window::dashdot_pressed()
{
  change_ls(Line_style::dashdot);
  hide_menu();
}

//------------------------------------------------------------------------------

void Lines_window::dashdotdot_pressed()
{
  change_ls(Line_style::dashdotdot);
  hide_menu();
}

//------------------------------------------------------------------------------

void Lines_window::menu_pressed()
{
  menu_button.hide();
  color_menu.show();
  style_menu.show();
}

//------------------------------------------------------------------------------

void Lines_window::hide_menu()
{
  color_menu.hide();
  style_menu.hide();
  menu_button.show();
}

//------------------------------------------------------------------------------

void Lines_window::cb_quit(Address, Address pw)
{
  reference_to<Lines_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Lines_window::quit() { hide(); }

//-----------------------------------------------------------------------------

void Lines_window::cb_next(Address, Address pw)
{
  reference_to<Lines_window>(pw).next();
}

//-----------------------------------------------------------------------------

void Lines_window::next()
{
  int x = next_x.get_int();
  int y = next_y.get_int();

  lines.add(Point{x, y});

  // update current pos readout
  ostringstream ss;
  ss << '(' << x << ',' << y << ')';
  xy_out.put(ss.str());
  redraw();
}

//------------------------------------------------------------------------------

void Lines_window::cb_red(Address, Address pw)
{
  reference_to<Lines_window>(pw).red_pressed();
}

//------------------------------------------------------------------------------S

void Lines_window::cb_blue(Address, Address pw)
{
  reference_to<Lines_window>(pw).blue_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_black(Address, Address pw)
{
  reference_to<Lines_window>(pw).black_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_menu(Address, Address pw)
{
  reference_to<Lines_window>(pw).menu_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_solid(Address, Address pw)
{
  reference_to<Lines_window>(pw).solid_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_dash(Address, Address pw)
{
  reference_to<Lines_window>(pw).dash_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_dot(Address, Address pw)
{
  reference_to<Lines_window>(pw).dot_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_dashdot(Address, Address pw)
{
  reference_to<Lines_window>(pw).dashdot_pressed();
}

//------------------------------------------------------------------------------

void Lines_window::cb_dashdotdot(Address, Address pw)
{
  reference_to<Lines_window>(pw).dashdotdot_pressed();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int main()
{
  try {
    Lines_window win{Point{100, 100}, 600, 400, "lines"};

    return gui_main();
  }
  catch (const std::exception& e) {
    std::cerr << e.what();
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled error";
    return 2;
  }
}