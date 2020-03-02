
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

/*
  2) Make a window (based on My_window ) with a 4-by-4 checkerboard of
    square buttons. When pressed, a button performs a simple action, such as
    printing its coordinates in an output box, or turns a slightly different
    color (until another button is pressed).
*/
struct Checker_window : Graph_lib::Window {
  Checker_window(Point xy, int w, int h, const string& title);

private:
  bool button_pushed;

  // widgets
  Button next_button;
  Button quit_button;
  Out_box coords;  // updates with relevant coordinates after a user clicks

  /*
     to workaround a proper Matrix class, (we could use MatrixIO but
     I am choosing not to since we haven't yet convered it) we will build
     a 4x4 grid of buttons (square) and 'stack' each row vertically
     to create a 'grid' effect.
  */
  Menu row1;
  Menu row2;
  Menu row3;
  Menu row4;

  /*
    A bit ugly however, I spent a long time trying to figure out
    a better way to build a grid while reducing copy-paste
    but I think this is acceptable given what I've learned so far.

    There are nuances of callbacks,pointers in cpp that
    I am not familiar with yet whcih may make the solution
    presented below more robust.
  */
  void action(Button& b);  // generic action for a Button
  void action11() { action(row1.selection[0]); }
  void action12() { action(row1.selection[1]); }
  void action13() { action(row1.selection[2]); }
  void action14() { action(row1.selection[3]); }
  void action21() { action(row2.selection[0]); }
  void action22() { action(row2.selection[1]); }
  void action23() { action(row2.selection[2]); }
  void action24() { action(row2.selection[3]); }
  void action31() { action(row3.selection[0]); }
  void action32() { action(row3.selection[1]); }
  void action33() { action(row3.selection[2]); }
  void action34() { action(row3.selection[3]); }
  void action41() { action(row4.selection[0]); }
  void action42() { action(row4.selection[1]); }
  void action43() { action(row4.selection[2]); }
  void action44() { action(row4.selection[3]); }

  void next();
  void quit();

  // callbacks

  static void cb_action11(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action11();
  }

  static void cb_action12(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action12();
  }

  static void cb_action13(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action13();
  }

  static void cb_action14(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action14();
  }

  static void cb_action21(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action21();
  }

  static void cb_action22(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action22();
  }

  static void cb_action23(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action23();
  }

  static void cb_action24(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action24();
  }

  static void cb_action31(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action31();
  }

  static void cb_action32(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action32();
  }

  static void cb_action33(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action33();
  }

  static void cb_action34(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action34();
  }

  static void cb_action41(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action41();
  }

  static void cb_action42(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action42();
  }

  static void cb_action43(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action43();
  }

  static void cb_action44(Address, Address pw)
  {
    reference_to<Checker_window>(pw).action44();
  }

  static void cb_next(Address, Address);
  static void cb_quit(Address, Address);
};

//------------------------------------------------------------------------------
/*
  int x_size = x_max();
  int y_size = y_max();
  int x_grid = 80;
  int y_grid = 80;


  USE THE ABOVE VALS WHEN constructing the grid
*/
Checker_window::Checker_window(Point xy, int w, int h, const string& title)
    : Window{xy, w, h, title},
      row1{Point{x_max() - 400, 50}, 25, 25, Menu::horizontal, "row1"},
      row2{Point{x_max() - 400, 75}, 25, 25, Menu::horizontal, "row2"},
      row3{Point{x_max() - 400, 100}, 25, 25, Menu::horizontal, "row3"},
      row4{Point{x_max() - 400, 125}, 25, 25, Menu::horizontal, "row4"},
      next_button{Point{x_max() - 70, 30}, 70, 20, "Next", cb_next},
      quit_button{Point{x_max() - 70, 50}, 70, 20, "Quit", cb_quit},
      coords{Point{x_max() - 400, 0}, 100, 20, "position of last button press"}
{
  row1.attach(new Button{Point{0, 0}, 0, 0, "1", cb_action11});
  row1.attach(new Button{Point{0, 0}, 0, 0, "2", cb_action12});
  row1.attach(new Button{Point{0, 0}, 0, 0, "3", cb_action13});
  row1.attach(new Button{Point{0, 0}, 0, 0, "4", cb_action14});

  // TODO: iterate over each row and set each cell to either black
  // or red, alternating.

  attach(row1);

  row2.attach(new Button{Point{0, 0}, 0, 0, "5", cb_action21});
  row2.attach(new Button{Point{0, 0}, 0, 0, "6", cb_action22});
  row2.attach(new Button{Point{0, 0}, 0, 0, "7", cb_action23});
  row2.attach(new Button{Point{0, 0}, 0, 0, "8", cb_action24});
  attach(row2);

  row3.attach(new Button{Point{0, 0}, 0, 0, "9", cb_action31});
  row3.attach(new Button{Point{0, 0}, 0, 0, "10", cb_action32});
  row3.attach(new Button{Point{0, 0}, 0, 0, "11", cb_action33});
  row3.attach(new Button{Point{0, 0}, 0, 0, "12", cb_action34});
  attach(row3);

  row4.attach(new Button{Point{0, 0}, 0, 0, "13", cb_action41});
  row4.attach(new Button{Point{0, 0}, 0, 0, "14", cb_action42});
  row4.attach(new Button{Point{0, 0}, 0, 0, "15", cb_action43});
  row4.attach(new Button{Point{0, 0}, 0, 0, "16", cb_action44});
  attach(row4);

  attach(next_button);
  attach(quit_button);
  attach(coords);
  coords.put("nothing clicked yet");
}

//------------------------------------------------------------------------------

void Checker_window::cb_quit(Address, Address pw)
{
  reference_to<Checker_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Checker_window::quit() { hide(); }

//------------------------------------------------------------------------------

void Checker_window::cb_next(Address, Address pw)
{
  reference_to<Checker_window>(pw).next();
}

//------------------------------------------------------------------------------

void Checker_window::next()
{
  button_pushed = true;
  int x = next_button.loc.x;
  int y = next_button.loc.y;

  // update out_box
  ostringstream ss;
  ss << '(' << x << ',' << y << ')';
  coords.put(ss.str());
  redraw();
}

//------------------------------------------------------------------------------

void Checker_window::action(Button& b)
{
  int x = b.loc.x;
  int y = b.loc.y;

  ostringstream ss;
  ss << '(' << x << ',' << y << ')';  // format the string stream
  coords.put(ss.str());
  redraw();
}

//------------------------------------------------------------------------------
int main()
{
  try {
    Checker_window win{Point{100, 100}, 600, 400, "Exercise 2"};
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