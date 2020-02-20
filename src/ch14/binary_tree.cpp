#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

int main()
{
  try {
    Point tl(200, 50);
    Simple_window win(tl, 1200, 800, "My window");

    /*Binary_tree bt(Point(600, 50), 6, "");
    win.attach(bt);
    win.wait_for_button();

    bt.move(50, 50);
    win.wait_for_button();
    bt.move(-50, -50);
    win.wait_for_button();

    win.detach(bt);

    Binary_tree bt2(Point(600, 50), 6, "ad");
    win.attach(bt2);
    win.wait_for_button();

    win.detach(bt2);*/

    // TODO: Why is set_color only affecting the individual nodes (circles)
    // and not the lines as well?  The desired behavior for this method
    // should be to in a single call to set_color, we set the color for
    // the entire tree, meaning, the nodes and edges.
    Binary_tree bt3(Point(600, 50), 6, "");
    bt3.set_color(Color::black);
    win.attach(bt3);

    win.wait_for_button();

    bt3.set_node_label("l", "Root");
    bt3.set_node_label("lr", "lr");
    bt3.set_node_label("lrl", "lrl");
    bt3.set_node_label("lrlr", "lrlr");
    bt3.set_node_label("lrlrl", "lrlrl");
    bt3.set_node_label("lrlrlr", "lrlrlr");
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
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}