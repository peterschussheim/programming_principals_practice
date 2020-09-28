// Get the email file example to run; test it using a larger file of your own
// creation. Be sure to include messages that are likely to trigger errors, such
// as messages with two address lines, several messages with the same ad-
// dress and/or same subject, and empty messages.
// Also test the program with something that simply isn’t a message according to
// that program’s specification, such as a large file containing no –––– lines.

#include <iostream>
#include <map>
#include <string>
#include "Mail.h"

//------------------------------------------------------------------------------

// find name of the sender in a Message;
// return true if found
// if found, place sender's name in s:
bool find_from_addr(const Message* m, std::string& s);

//------------------------------------------------------------------------------

// return the subject of the Message, if any, otherwise "":
std::string find_subject(const Message* m);

//------------------------------------------------------------------------------

// is p the first part of s?
int is_prefix(const std::string& s, const std::string& p);

//------------------------------------------------------------------------------

void f(const std::string& file_name, const std::string& query);

//------------------------------------------------------------------------------

int main()
{
  try {
    // f("my-mail-file.txt", "John Doe <jdoe@machine.example>");  // no errors
    std::cout << '\n';
    f("mail_file_with_errors.txt", "Garven <garven@machine.example>");
    std::cout << '\n';
    f("mail_file_with_errors_2.txt", "John Doe <jdoe@machine.example>");
    f("table.txt", "John Doe <jdoe@machine.example>");

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

int is_prefix(const std::string& s, const std::string& p)
{
  int n = p.size();
  if (std::string(s, 0, n) == p) return n;
  return 0;
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

std::string find_subject(const Message* m)
{
  for (const auto& x : *m) {
    if (int n = is_prefix(x, "Subject: ")) {
      // construct new substring of the tail of s from (s[n]...s[s.size()-1])
      return std::string(x, n);
    }
  }

  return "";
}

//------------------------------------------------------------------------------

// Accepts a mail file's name and a string to search each message's subject
// field.  Prints to stdout the subjects that were found.
void f(const std::string& file_name, const std::string& query)
{
  Mail_file m_file{file_name};
  std::multimap<std::string, const Message*> sender;
  for (const auto& m : m_file) {
    std::string s;
    if (find_from_addr(&m, s)) sender.insert(std::make_pair(s, &m));
  }

  auto pp = sender.equal_range(query);
  for (auto p = pp.first; p != pp.second; ++p) {
    std::cout << find_subject(p->second) << '\n';
  }
}

//------------------------------------------------------------------------------
