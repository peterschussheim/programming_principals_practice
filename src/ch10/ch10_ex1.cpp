#include "std_lib_facilities.h"

using namespace std;

int sum_ints(ifstream& ist) {
  int sum = 0;  // holds our result

  for (int i; ist >> i;) { sum += i; }

  if (ist.eof()) return sum;  // eof found, good
}

int main() {
  try {
    string my_file = "ints_whitespace.txt";
    ifstream ist{my_file};  // create ifstream using file name
    if (!ist) error("cannot open input file: ", my_file);
    int sum = sum_ints(ist);
    cout << "sum: " << sum << '\n';
    keep_window_open("~");
    return 0;

  } catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "unhandled exception\n";
    return 2;
  }
}