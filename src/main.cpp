#include "Split.h"
#include "std_lib_facilities.h"

using namespace std;

void print_on_one_line(vector<string> v) {
  for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
  cout << '\n';
}

void print_on_multiline(vector<string> v) {
  for (int i = 0; i < v.size(); ++i) { cout << v[i] << '\n'; }
  cout << '\n';
}

int main() {
  try {
    string test1 = "a man a plan a canal panama";
    vector<string> split_t1 = split(test1);
    print_on_one_line(split_t1);
    cout << '\n';

    // current version will ONLY detect a plain old space
    string test2 = "a man a plan, a canal panama.";
    vector<string> split_t2 = split(test2);
    print_on_multiline(split_t2);

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