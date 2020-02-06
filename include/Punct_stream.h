#pragma once
#include "../src/std_lib_facilities.h"

/*
  Peter Schussheim
  02/05/20

  The following code is from PPP Chapter 11.
*/

/*
  Punct_stream class provides users with a mechanism
  to specify a string of punctuation symbols to use
  for determining whitespace in a string s, in addition to
  the default whitespace deliminator, ' ' (space).

  Punct_stream is intended to be used in a similar
  manner to an istream with the addition of user-defined
  whitespace symbols.

  For example:
    Punct_stream ps{istream || cin || istringstream}; // construct a Punct_stream with source.
    ps.whitespace(",.?!");        // call member function to set the desired chars
    for(string word; ps >> word;) { ...do something with word }
*/

class Punct_stream {
public:
  Punct_stream(istream& is) : source{is}, sensitive{true} {}
  void whitespace(const string& s) { white = s; }  // set whitespace to s
  void add_white(char c) { white += c; }           // add c to whitespace set
  bool is_whitespace(char c);
  void case_sensitive(bool b) { sensitive = b; }
  bool is_case_sensitive() { return sensitive; }
  Punct_stream& operator>>(string& s);
  operator bool();

private:
  istream& source;       // character source
  istringstream buffer;  // buffer handles our formatting
  string white;          // characters considered "whitespace"
  bool sensitive;        // is the stream case-sensitive?
};

Punct_stream& Punct_stream::operator>>(string& s) {
  while (!(buffer >> s)) {  // try to read from buffer
    if (buffer.bad() || !source.good()) return *this;
    buffer.clear();

    string line;
    getline(source, line);  // get a line from source

    // perform character replacement as needed
    for (char& ch : line) {
      if (is_whitespace(ch)) {
        ch = ' ';  // tranform to space
      } else if (!sensitive) {
        ch = tolower(ch);
      }
    }

    buffer.str(line);  // put string into stream
  }

  return *this;
}

bool Punct_stream::is_whitespace(char c) {
  for (char w : white)        // compare each char of the string
    if (c == w) return true;  // against our whitespace set
  return false;
}

Punct_stream::operator bool() { return !(source.fail() || source.bad()) && source.good(); }