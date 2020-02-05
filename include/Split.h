#pragma once
#include "../src/std_lib_facilities.h"

/*
  Peter Schussheim
  02/05/20

  PPP Chapter 11 Exercise 10
*/

/*
  Write a function vector<string> split(const string& s)
  that returns a vector of whitespace-separated strings
  from the argument s.
*/

/*
  -
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