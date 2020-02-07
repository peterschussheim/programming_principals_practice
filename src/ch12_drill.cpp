#include <FL/Fl.H>
#include <FL/Fl_Box.h>
#include <FL/Fl_Window.h>

int main() {
  Fl_Window window(800, 800, "Window title");
  Fl_Box box(0, 0, 200, 200, "Hey, I mean, Hello, World!");
  window.show();
  return Fl::run();
}