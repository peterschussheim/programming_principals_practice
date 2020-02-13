/*
  Peter Schussheim
  02/10/20

  Programming Principals and Practice
  Chapter 13 Drills
*/

/*
  - [x] Make an 800-by-1000 Simple_window.
    - NOTE: although the book tells us to create an 800x1000 window, I
      will swap the x and y to get 1000x800 so that we can fit it in our screen.

  - [x] Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that
     each square is 100 by 100).

  - [x] Make the eight squares on the diagonal starting from the top left corner
     red (use Rectangle).

  - [ ] Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it
     on the grid (each image covering four squares). If you can’t find an image
     that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of
     a larger image. Don’t obscure the red squares.

  - [ ] Add a 100-by-100 image. Have it move around from square to square
     when you click the “Next” button. Just put wait_for_button() in a loop
     with some code that picks a new square for your image.
*/

#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
  try {
    Point tl{0, 0};
    Simple_window win{tl, 1000, 800, "Drill"};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*"
        << win.y_max();
    Text sizes{Point{100, 20}, oss.str()};
    sizes.set_color(Color::black);

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;
    Lines grid;

    for (int x = x_grid; x < x_size; x += x_grid) {
      grid.add(Point{x, 0}, Point{x, y_size});  // vertical line
    }

    for (int y = y_grid; y < y_size; y += y_grid) {
      grid.add(Point{0, y}, Point{x_size, y});  // horizontal line
    }
    // win.wait_for_button();
    /*
      Create a Vector containing references to Rectangle objects,
      specifically, color the 8 rectangles on the top-left to lower-right
      diagonal red.
    */
    Vector_ref<Graph_lib::Rectangle> vr;
    for (int i = 0; i < 8; ++i) {
      vr.push_back(new Graph_lib::Rectangle{Point{i * 100, i * 100}, 101, 101});
      vr[vr.size() - 1].set_fill_color(Color::red);
      win.attach(vr[vr.size() - 1]);
    }

    win.attach(grid);
    win.attach(sizes);

    /*
      Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it
      on the grid (each image covering four squares). If you can’t find an image
      that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of
      a larger image. Don’t obscure the red squares.
    */
    // Image img{Point{200, 200}, "200x200.jpg", Suffix::jpg};
    // win.attach(img);
    // win.wait_for_button();
    // win.put_on_top(img);

    Image plane1(Point(200, 200), "resources/200x200.jpg");
    // plane1.set_mask(Point(200, 0), 200, 200);
    win.attach(plane1);
    Image plane2(Point(500, 200), "resources/200x200.jpg");
    // plane2.set_mask(Point(200, 0), 200, 200);
    win.attach(plane2);
    Image plane3(Point(100, 500), "resources/200x200.jpg");
    // plane3.set_mask(Point(200, 0), 200, 200);
    win.attach(plane3);

    // grid.set_color(Color::black);
    win.wait_for_button();

    keep_window_open("~");
    return 0;
  }
  catch (exception& e) {
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    keep_window_open("~");
    return 2;
  }
}