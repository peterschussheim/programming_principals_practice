
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

/*
  1) Make a My_window that’s a bit like Simple_window except that it has
    two buttons, next and quit.

  2) Make a window (based on My_window ) with a 4-by-4 checkerboard of
    square buttons. When pressed, a button performs a simple action, such as
    printing its coordinates in an output box, or turns a slightly different
    color (until another button is pressed).

*/
struct My_window : Graph_lib::Window {
  My_window(Point xy, int w, int h, const string& title);

private:
  bool button_pushed;

  int x_size = x_max();
  int y_size = y_max();
  int x_grid = 80;
  int y_grid = 80;

  // widgets
  Button next_button;
  Button quit_button;
  // Menu checker_board;
  // Out_box coords;  // updates with relevant coordinates after a user clicks

  // actions

  // updates Out_box coords with the position of the button clicked
  // void print();
  void next();
  void quit();

  // callbacks

  // cb that maps to member which updates out_box coords
  // with the x,y coordinates of the specific button pressed.
  // static void cb_print_coords(Address, Address);

  static void cb_next(Address, Address);
  static void cb_quit(Address, Address);
};

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title)
    : Window{xy, w, h, title},
      next_button{Point{x_max() - 70, 30}, 70, 20, "Next", cb_next},
      quit_button{Point{x_max() - 70, 50}, 70, 20, "Quit", cb_quit}
{
  attach(next_button);
  attach(quit_button);
}

//------------------------------------------------------------------------------

void My_window::cb_quit(Address, Address pw)
{
  reference_to<My_window>(pw).quit();
}

//------------------------------------------------------------------------------

void My_window::quit() { hide(); }

//------------------------------------------------------------------------------

void My_window::cb_next(Address, Address pw)
{
  reference_to<My_window>(pw).next();
}

//------------------------------------------------------------------------------

void My_window::next()
{
  button_pushed = true;
  hide();
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int main()
{
  try {
    My_window win{Point{100, 100}, 600, 400, "My_window"};
    return gui_main();
    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << '\n';
    return 1;
  }

  catch (...) {
    cerr << "Unhandled exception\n";
    return 2;
  }
}