#include <iostream>
#include "Utils.h"

using namespace std;

/*
  Write a function, string cat_dot(const string& s1, const string& s2),
  that concatenates two strings with a dot in between. For example,
  cat_dot("Niels", "Bohr") will return a string containing Niels.Bohr.
*/

string cat_dot(const string& s1, const string& s2)
{
  string result = s1;
  result += '.';
  result += s2;
  return result;
}

int main()
{
  try {
    string test_1 = cat_dot("Niels", "Bohr");
    cout << test_1 << '\n';

    string ss1;
    string ss2;
    cout << "enter two strings: ";
    while (cin >> ss1 >> ss2) {
      ss1 += '.';
      ss1 += ss2;
    }

    cout << ss1 << '\n';
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