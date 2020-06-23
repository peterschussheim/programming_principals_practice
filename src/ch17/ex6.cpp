#include <iostream>
#include "Utils.h"

using namespace std;

/*
  This chapter does not say what happens when you run out of memory
  using new. That's called memory exhaustion. Find out what happens. You have
  two obvious alternatives: look for documentation, or write a program with
  an infinite loop that allocates but never deallocates. Try both. Approxi-
  mately how much memory did you manage to allocate before failing?

  I managed to run the program infinite_loop for about 2 minutes on my machine
  with 32gb of memory and to my surprise, the program did NOT fail.  While not
  certain, I think that after a certain point, the OS begins to use the disk
  as swap (incorrect term?).

  According to the isocpp.com memory FAQ, malloc() reports memory exhaustion
  by returning 0 and the new operator throws a bad_alloc exception.

*/

void infinite_loop()
{
  while (true) { string* n = new string{"Jeff"}; }
}

int main()
{
  try {
    // infinite_loop();

    keep_window_open("~");
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