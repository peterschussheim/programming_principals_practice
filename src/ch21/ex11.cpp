// 11. Provide a GUI interface for entering Orders into files.
// 12. Provide a GUI interface for querying a file of Order s; e.g., “Find all
// or- ders from Joe ,” “Find the total value of orders in file Hardware ,” and
// “List all orders in file Clothing .” Hint: First design a non-GUI interface;
// then, build the GUI on top of that.

// Skipping this exercise.  FLTK is not easy to use and requires more time
// learning the "fltk way" to program which I can't invest the required time
// to learn.
#include "Graph.h"
#include "GUI.h"
#include "Point.h"
#include "Window.h"

// GUI Design:
// 2) edit a single text file
// 3) load from a file
// 4) save to a file

class Order_window : Graph_lib::Window {
public:
  Order_window(Graph_lib::Point xy, int w, int h, const std::string &title);

private:
  bool button_pushed;
};

int main()
{
  try {
    // Order_window win{Point{100, 100}, 600, 400, "Order Entry"};
    // return gui_main();
    return 0;
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    return 2;
  }
}
