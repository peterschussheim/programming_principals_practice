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

int main() {
  try {
    string iname;  // input filename
    string oname;  // output filename
    char ch;       // variable to store chars from input file

    cout << "Please enter a filename to open (try uppers.txt): ";
    cin >> iname;
    ifstream ifs{iname};  // create ifstream
    if (!ifs) error("cannot open input file: ", iname);

    cout << "Please enter a filename for the transformed text: ";
    cin >> oname;
    ofstream ofs{oname};  // create ofstream
    if (!ofs) error("cannot open input file: ", oname);

    while (ifs.get(ch)) {
      if (isalpha(ch)) ch = tolower(ch);
      ofs << ch;
    }

    cout << "File written to: " << oname << '\n';

    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}