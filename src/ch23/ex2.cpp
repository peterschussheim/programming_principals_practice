// Add a multimap and have it hold subjects. Let the program take an input
// string from the keyboard and print out every message with that string as
// its subject.

#include <iostream>
#include <map>
#include <string>
#include "Mail.h"

//------------------------------------------------------------------------------

int is_prefix(const std::string& s, const std::string& p);

//------------------------------------------------------------------------------

// Return a string containing a copy of the Message body text.
// How to extract a Message body? We need to consider that a body text can be
// an empty, a single line or multiple lines.
std::string find_body(const Message* m);

//------------------------------------------------------------------------------

// return the subject of the Message, if any, otherwise "":
std::string find_subject(const Message* m);

//------------------------------------------------------------------------------

bool find_from_subject(const Message* m, std::string& s);

//------------------------------------------------------------------------------

bool find_from_addr(const Message* m, std::string& s);

//------------------------------------------------------------------------------

// TODO: Re-read carefully the instructions for this exercise (above) and redo
// the exercise rather than starting from ex1 as an example. Don't rush it!
int main()
{
  try {
    std::cout << "Please enter a subject to search for: ";
    std::string query;
    getline(std::cin, query);
    std::cout << '\n';
    std::cout << "Messages matching query \"" << query << "\":\n" << '\n';

    Mail_file m_file{"my-mail-file.txt"};  // init mail file

    // init multimap to store Messages matching query
    std::multimap<std::string, const Message*> subject;

    for (const auto& msg : m_file) {
      std::string s;
      if (find_from_subject(&msg, s)) {  // build map keyed by message subject

        subject.insert(std::make_pair(s, &msg));
      }
    }

    auto pp = subject.equal_range(query);           // beginning of a Message
    for (auto p = pp.first; p != pp.second; ++p) {  // print each Message's body
      std::cout << find_body(p->second) << '\n';
    }

    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    return 2;
  }
}

//------------------------------------------------------------------------------

std::string find_body(const Message* m)
{
  for (const auto& field : *m) {
    // Assume message body begins AFTER a blank Message header field and
    // terminates when given "----" (four dashes). For example:
    // EMPTY Line
    // This is a message just to say hello.
    // So, "Hello".
    // ----
    if (int n = is_prefix(field, "Subject: ")) {
      return std::string(field, n);
      // std::cout << field << '\n';
    }
  }

  return "";
}

std::string find_subject(const Message* m)
{
  for (const auto& x : *m) {
    if (int n = is_prefix(x, "Subject: ")) { return std::string(x, n); }
  }
}

//------------------------------------------------------------------------------

bool find_from_addr(const Message* m, std::string& s)
{
  for (const auto& x : *m) {
    if (int n = is_prefix(x, "From: ")) {
      s = std::string(x, n);
      return true;
    }
  }

  return false;
}

//------------------------------------------------------------------------------

bool find_from_subject(const Message* m, std::string& s)
{
  for (const auto& x : *m) {
    if (int n = is_prefix(x, "Subject: ")) {
      s = std::string(x, n);
      return true;
    }
  }
  return false;
}

//------------------------------------------------------------------------------

int is_prefix(const std::string& s, const std::string& p)
{
  int n = p.size();
  if (std::string(s, 0, n) == p) return n;
  return 0;
}

//------------------------------------------------------------------------------