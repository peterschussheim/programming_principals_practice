#include <iostream>
#include "Utils.h"

using namespace std;

/*
  Which way does the stack grow:
    - up (toward higher addresses)?
    - or down (to-ward lower addresses)?
    - Which way does the free store initially grow (before you use delete)?

  Write a program to determine the answers.
*/

/*
  the idea here is to figure out how the system (OS + compiler) handles memory
  addressing and determine which direction the addresses 'grow'.


*/
int main()
{
  try {
    // stack
    int is = 0;
    int is1 = 0;
    int is2 = 0;
    cout << "Addresses on the stack:\n"
         << &is << '\n'
         << &is1 << '\n'
         << &is2 << '\n';
    int stack_diff = &is1 - &is;

    if (stack_diff > 0)
      cout << "Stack grows upward\n";
    else
      cout << "Stack grows downward\n";

    cout << '\n';

    // heap growth
    int* ih = new int(0);
    int* ih1 = new int(0);
    int* ih2 = new int(0);
    cout << "Addresses on the heap:\n"
         << ih << '\n'
         << ih1 << '\n'
         << ih2 << '\n';
    int heap_diff = ih1 - ih;

    if (heap_diff > 0)
      cout << "Heap grows upward\n";
    else
      cout << "Heap grows downward\n";

    delete ih;
    delete ih1;
    delete ih2;

    keep_window_open();
    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}