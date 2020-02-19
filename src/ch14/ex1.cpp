#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

/*
  Define two classes Smiley and Frowny, which are both derived from class
  Circle and have two eyes and a mouth. Next, derive classes from Smiley and
  Frowny which add an appropriate hat to each.
*/

/*
  define an abstract class and try to define an object of that class.

  Abstract Writing_utensil class to be a base class for specific
  types of writing tools such as a pen, crayon, marker, pencil, etc.
*/
class Writing_utensil {
public:
  void virtual write_char() const = 0;  // write a single char to the screen

private:
  Point start;  // x, y coord of the point where we begin to write a char
};

int main()
{
  try {
    Point tl{100, 100};
    Simple_window win{tl, 800, 800, "Smiley and Frowny"};

    Smiley sm{Point{100, 100}, 50};
    sm.set_color(Color::blue);
    sm.set_style(Graph_lib::Line_style(Line_style::dashdot));

    Frowny fr{Point{200, 100}, 50};
    fr.set_color(Color::red);

    Hat_smiley hs{Point{300, 100}, 50};
    hs.set_color(Color::magenta);

    Hat_frowny hf{Point{400, 100}, 50};
    hf.set_color(Color::dark_green);

    /*
    Exercise #2: try to copy a shape
    compiler error due to Shape's copy constructor being deleted
    Hat_frowny hf_copy = hf;
    */

    /*
      we cannot create an object of ann abstract class unless
      ALL of the abstract class's virtual functions are overridden.
    */
    // Writing_utensil wu;

    Immobile_circle ic{Point{100, 100}, 50};

    ic.set_color(Color::black);

    win.attach(ic);
    win.wait_for_button();
    // ic.move(300, 450); will not work since we've set Circle::move as private
    /*win.attach(sm);
    win.attach(fr);
    win.attach(hf);
    win.attach(hs);*/

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
    cerr << "Unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}