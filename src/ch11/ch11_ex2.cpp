/*
  Peter Schussheim
  02/05/20

  PPP Chapter 11 Exercise 2
*/

#include "std_lib_facilities.h"

/*
  Write a program that given a file name and a word,
  outputs each line that contains that word together
  with the line number.  Use `getline()`.
*/

/*
  Program Design:

  - prompt user for a file to read from
  - prompt user for a "target" word to find
  - since we are asked to return the line number where
      our target word was found, we should operate on a single
      line at a time: string line; getline(ifs, line)
  - initialize line_count to 0 and increment by one on each
    successful call to getline
    - once we have a line, iterate over each whitespace deliminated
      string.  Whitespace defined as (" ", ",", ".", "!", "?", "/")
    - if (word == target) return line_count
*/

bool match(const string& s, int i, const string& word) {
  // is s[i] the start of word?
  for (int j = 0; j < word.size(); ++j) {
    if (s.size() <= j + 1) return false;  // is the size of s less than or equal to j+1?
    if (s[i + j] != word[j]) return false;
  }

  return true;  // matched entire word
}

int main() {
  try {
    string iname;   // file name to search
    string target;  // name to find in file
    int line_count = 0;
    int match_count = 0;  // increment each time we have a match

    cout << "Please enter a file name: ";
    cin >> iname;
    ifstream ifs{iname};
    if (!ifs) error("unable to open file: ", iname);

    cout << "Please enter a word you'd like to find: ";
    cin >> target;

    string line;
    while (getline(ifs, line)) {
      ++line_count;  // successfully got a line
      for (int i = 0; i < line.size(); ++i) {
        if (match(line, i, target)) {
          ++match_count;
          cout << line_count << " " << line << '\n';
          break;
        }
      }
    }

    if (match_count == 0) cout << "Could not find any lines containing " << target << '\n';
    cout << "Found " << match_count << " matches of word: " << target << "!\n";
    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "unhandled error" << '\n';
    keep_window_open("~");
    return 2;
  }
}