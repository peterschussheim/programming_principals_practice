#include <iostream>
#include "GUI.h"

using namespace Graph_lib;

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