#include <iostream>
#include "Utils.h"

using namespace std;

/*
  Do exercise 7 again, but this time read into a std::string rather than to
  memory you put on the free store (string knows how to use the free store
  for you).

  Write a program that reads characters from cin into a string. Read
  individual characters until an exclamation mark ( ! ) is entered.
*/

/*
  So it seems there is some flexibility with this problem as we can use either
  a char or std::string as a 'buffer' while reading from stdin.
*/

int main()
{
  try {
    string my_string;
    string str;  // read from stdin
    char ch;

    cout
        << "Enter characters below and when complete, enter a \'!' when done\n";
    while (cin >> ch && ch != '!') {
      // my_string += str;
      my_string.push_back(ch);
    }

    cout << '\n';
    cout << "my_string: " << my_string << '\n';

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