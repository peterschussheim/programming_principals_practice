#include "Split.h"
#include "std_lib_facilities.h"

using namespace std;

void print_on_one_line(vector<string> v) {
  for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
  cout << '\n';
}

void print_on_multiline(vector<string> v) {
  cout << "Results:\n";
  for (string s : v) { cout << s << '\n'; }
}

/*
  overloaded to accept a string label.
*/
void print_on_multiline(vector<string> v, string label) {
  cout << label << ":\n";
  for (string s : v) { cout << s; }
}

/*
  overloaded to handle a string instead of a vector.
*/
void print_on_multiline(string str, string label) {
  cout << label << ":\n";
  for (int i = 0; i < str.size(); ++i) { cout << str[i]; }
}

int main() {
  try {
    // string test1 = "a man a plan a canal panama";
    // vector<string> split_t1 = split(test1);
    // print_on_one_line(split_t1);
    // cout << '\n';

    string test2 = "a man a plan, a canal panama.";
    vector<string> split_t2 = split(test2, ",.");

    print_on_multiline(test2, "Original");
    cout << "\n\n========================================\n\n";
    print_on_multiline(split_t2, "Without whitespace");

    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "unhandled exception\n\n";
    keep_window_open("~");
    return 2;
  }
}