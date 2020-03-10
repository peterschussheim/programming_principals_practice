#include <iostream>
#include "Utils.h"

using namespace std;

/*


*/

int main()
{
  try {
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