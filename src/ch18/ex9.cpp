#include <iostream>
#include "Utils.h"

/*
  Consider the memory layout in 17.4. Write a program that tells the order
  in which static storage, the stack, and the free store are laid out in memory.
  In which direction does the stack grow: upward toward higher addresses
  or downward toward lower addresses? In an array on the free store, are
  elements with higher indices allocated at higher or lower addresses?
*/

/*
  start by implementing the same idea from chapter 17 ex 9 except use an array
*/

// void analyze_mem(int )
//{
//
//}

int main()
{
  try {
    keep_window_open();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}