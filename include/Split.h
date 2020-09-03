#pragma once
#include "std_lib_facilities.h"

/*
  Peter Schussheim
  02/05/20

  PPP Chapter 11 Exercises 10 and 11
*/

/*
  Exercise 10:
    Write a function vector<string> split(const string& s)
    that returns a vector of whitespace-separated strings
    from the argument s.
*/

/*
  Basic split function.  Only supports "splitting" on plain space.

  Note that this implementation is naive and relies on string copying.
*/
vector<string> split(const string& s)
{
  vector<string> result;
  istringstream is{s};  // create a stringstream to read from s
  string word;
  if (!is) error("error reading string: ", s);
  while (is >> word) {  // get a word
    result.push_back(word);
  }

  return result;
}

/*
  check if a given char c can be found in
  string w.
*/
bool is_ws(const char& c, const string& w)
{
  for (char ch : w) {  // scan each char in string w
    if (c == ch) return true;
  }

  return false;
}

/*
  A more useful variation of split which accepts a second argument
  string& w which is a user-defined string of additional types
  of "whitespace".

  Example usage:
  string test1 = "a man, a plan a (canal) panama!";
  string ws = ".,!?();:";
  vector<string> split_t = split(test1, ws);
    -> contents of split_t = {"a", "man", "a", "plan", "a", "canal", "panama"}
*/
vector<string> split(const string& s, const string& w)
{
  vector<string> result;
  string word;            // variable to build up a string without whitespace
  for (char c : s) {      // scan each char in s
    if (!is_ws(c, w)) {   // if the current c is not a ws character
      word.push_back(c);  // add current char to word
    }
    else if (word != "") {  // non-empty word signals it has been 'cleaned'
      result.push_back(word);
      word = "";  // reset word's state
    }
  }

  return result;
}