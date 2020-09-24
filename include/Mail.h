#ifndef MAIL_H
#define MAIL_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

//------------------------------------------------------------------------------

using Line_iter = std::vector<std::string>::const_iterator;

// a Message points to the first and last lines of a Message
class Message {
  Line_iter first;
  Line_iter last;

public:
  Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} {}
  Line_iter begin() const { return first; }
  Line_iter end() const { return last; }
};

//------------------------------------------------------------------------------

// A Mail_file is a structure holding lines of text and messages:
using Mess_iter = std::vector<Message>::const_iterator;

struct Mail_file {   // a Mail_file holds all the lines from a file and
                     // simplifies access to messages
  std::string name;  // file name
  std::vector<std::string> lines;  // the lines in order
  std::vector<Message> m;          // Messages in order

  Mail_file(const std::string& n);  // read file n into lines

  Mess_iter begin() const { return m.begin(); }
  Mess_iter end() const { return m.end(); }
};

//------------------------------------------------------------------------------

// To better handle errors related to line endings, we could remove the
// hardcoded string "----" and overload Mail_file constructor to take a
// line_ending argument.  We could also assume a few additional patterns are
// valid message terminators, such as 3 or 5 dashes (assuming the user manually
// typed a Mail_file which is doubtful).

Mail_file::Mail_file(const std::string& n)
{
  // open file named n
  // read lines from n into lines
  // find the messages in the lines and compose them in m
  // for simplicity, assume each message is terminated by a ---- line

  std::ifstream in{n};  // open the file
  if (!in) {
    std::cerr << "no " << n << '\n';
    exit(1);  // terminate program
  }

  for (std::string s; getline(in, s);)  // build vector of lines
  {
    lines.push_back(s);
  }

  auto first = lines.begin();  // build vector of Messages
  for (auto p = lines.begin(); p != lines.end(); ++p) {
    if (*p == "----") {  // if we reached end of message
      m.push_back(Message(first, p));
      first = p + 1;  // ---- is not part of the message
    }
  }
}

//------------------------------------------------------------------------------

#endif  // MAIL_H