#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main() {
  Point tl{100, 100};  // top left
  Simple_window win(tl, 600, 600, "Canvas");
  win.wait_for_button();
}