#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//---------------------------------------------------------------------------

struct Lines_window : Graph_lib::Window {
  Lines_window(Point xy, int w, int h, const string& title);

private:
  // data
  Open_polyline lines;

  // widgets
  Button next_button;  // add (next_x, next_y) to lines
  Button quit_button;
  In_box next_x;
  In_box next_y;
  Out_box xy_out;
  Menu color_menu;
  Button menu_button;  // toggles visibility of color_menu

  void change(Color c) { lines.set_color(c); }
  void hide_menu();

  // actions
  void red_pressed();
  void blue_pressed();
  void black_pressed();
  void menu_pressed();
  void next();
  void quit();

  // Callbacks for various buttons that trigger a color change
  static void cb_red(Address, Address);
  static void cb_blue(Address, Address);
  static void cb_black(Address, Address);
  static void cb_menu(Address, Address);
  static void cb_next(Address, Address);  // cb for next_button
  static void cb_quit(Address, Address);  // cb for quit_button
};