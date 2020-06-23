#include <iostream>
#include "Utils.h"

using namespace std;

/*
  Modify cat_dot() from the previous exercise to take a string to be used as
  the separator (rather than dot) as its third argument.
*/
string cat_dot(const string& s1, const string& s2, const string& sep = ".")
{
  string result = s1;
  result += sep;
  result += s2;
  return result;
}

int main()
{
  try {
    string test_1 = cat_dot("Niels", "Bohr");
    cout << "default separator: " << test_1 << '\n';

    string test_2 = cat_dot("Niels", "Bohr", "*");
    cout << "user-defined separator: " << test_2 << '\n';

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