
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

/*
  Make a My_window that’s a bit like Simple_window except that it has
  two buttons, next and quit.
*/
struct My_window : Graph_lib::Window {
  My_window(Point xy, int w, int h, const string& title);
  bool button_pushed;

private:
  // widgets
  Button next_button;
  Button quit_button;

  // actions
  void next();
  void quit();

  // callbacks
  static void cb_next(Address, Address);
  static void cb_quit(Address, Address);
};

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title)
    : Window{xy, w, h, title},
      button_pushed{false},
      next_button{Point{x_max() - 70, 30}, 70, 20, "Next", cb_next},
      quit_button{Point{x_max() - 70, 100}, 70, 20, "Quit", cb_quit}
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