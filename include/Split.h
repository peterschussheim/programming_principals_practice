#pragma once
#include "../src/std_lib_facilities.h"

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
*/
vector<string> split(const string& s) {
  vector<string> result;
  istringstream is{s};  // create a stream to read from s
  string word;
  if (!is) error("error reading string: ", s);
  while (is >> word) {  // get a word
    result.push_back(word);
  }

  return result;
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

vector<string> split(const string& s, const string& w) { vector<string> result; }