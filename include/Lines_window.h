#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//---------------------------------------------------------------------------

struct Lines_window : Graph_lib::Window {
  Lines_window(Point xy, int w, int h, const string& title);
  Open_polyline lines;

private:
  Button next_button;  // add (next_x, next_y) to lines
  Button quit_button;
  In_box next_x;
  In_box next_y;
  Out_box xy_out;

  static void cb_next(Address, Address);  // cb for next_button
  void next();
  static void cb_quit(Address, Address);  // cb for quit_button
  void quit();
};