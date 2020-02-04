/*
  Peter Schussheim
  02/04/20

  Ch 11, exercise 1

  Write a program that reads a text file and converts its input to all lower
  case, producing a new file.

  Input file location: out/build/.../src/uppers.txt
*/
#include "std_lib_facilities.h"
using namespace std;

// given a reference to a string, iterate over each char
// and if it is an uppercase char, convert to lowercase.
void tolower(string& s) {  // note the use of a reference
  for (char& x : s) {
    if (isupper(x)) {
      // read an uppercase ch
      // write out ch as lowercase
      x = tolower(x);
    }
  }
}

// read uppers.txt
// process input text
// use a vector to store converted text
// convert to lowercase
// read converted_vector and write to a new file
void to_lower() {
  string if_name = "uppers.txt";
  ifstream ifs{if_name};
  for (char ch; cin.get(ch);) { tolower(ch); }
}

int main() {
  to_lower();
  keep_window_open("~");
  return 0;
}