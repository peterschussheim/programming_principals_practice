#include "reverse.h"
#include "std_lib_facilities.h"

using namespace std;

/*
  print elements of vector on single line, seperated by spaces
*/
void print_on_one_line(string label, vector<int> v) {
  cout << label << ' ';
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << '\n';
}

int main() {
  try {
    vector<int> vec{1, 3, 5, 7, 9};  // init a vector of ints
    print_on_one_line("original vector: ", vec);

    vector<int> reversed = reverse_cpy(vec);  // vec is passed by value and returns a new vector
    print_on_one_line("reverse_cpy:     ", reversed);

    reverse_inplace(vec);
    print_on_one_line("reverse_inplace: ", vec);

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