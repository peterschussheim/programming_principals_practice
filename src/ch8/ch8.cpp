void swap_v(int, int);
void swap_v(int a, int b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void swap_r(int&, int&);
void swap_r(int& a, int& b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

// swap_cr is not correctly defined.
// a and b are const references and as such, CANNOT change the values
// of the objects passed in.
/*void swap_cr(const int& a, const int& b)*/;
// void swap_cr(const int& a, const int& b) {
//  int temp;
//  temp = a;
//  a = b;
//  b = temp;
//}

/**
  * Code copied over from main.cpp

  #include "ch8.cpp"

#include "std_lib_facilities.h"
using namespace std;

int main() {
  try {
    int x = 7;
    int y = 9;

    // swap_?(x,y);
    swap_v(x, y);  // compiles but does NOT swap correctly
    cout << "swap_v(x, y); called with x=7 y=9 "
         << "x: " << x << " y: " << y << '\n';

    swap_r(x, y);  // compiles and swaps args correctly
    cout << "swap_r(x, y); called with x=7 y=9 "
         << "x: " << x << " y: " << y << '\n';
    // swap_cr(x, y);

    // swap_?(7,9);
    swap_v(7, 9);
    cout << "swap_v(7, 9); called with "
         << "x: " << x << " y: " << y << '\n';
    // swap_r(7, 9);
    cout << "swap_r(7, 9); called with "
         << "x: " << x << " y: " << y << '\n';
    // swap_cr(7, 9);

    const int cx = 7;
    const int cy = 9;

    // swap_?(cx, cy);
    swap_v(cx, cy);
    cout << "swap_v(cx=7, cy=9); args after calling: "
         << "cx: " << cx << " cy: " << cy << '\n';
    // swap_r(cx, cy);
    // swap_cr(cx, cy);

    // swap_?(7.7, 7.9);
    swap_v(7.7, 7.0);  // compiles and swaps but looses precision from type cast
    cout << "swap_v(7.7, 9.9); args after calling: "
         << "cx: " << cx << " cy: " << cy << '\n';
    // swap_r(7.7, 7.0);
    // swap_cr(7.7, 7.0);

    double dx = 7.7;
    double dy = 9.9;

    // swap_?(dx, dy);
    cout << "dx == " << dx << " dy == " << dy << '\n';
    swap_v(dx, dy);  // compiles but does not swap correctly.
    cout << "dx == " << dx << " dy == " << dy << '\n';
    // swap_r(dx, dy);
    // swap_cr(dx, dy);

    // swap_?(7.7, 9.9);
    swap_v(7.7, 9.9);
    // swap_r(7.7, 9.9);
    // swap_cr(7.7, 9.9);

    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "exception\n";
    keep_window_open("~");
    return 2;
  }
}
  */