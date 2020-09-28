// Add a multimap and have it hold subjects. Let the program take an input
// string from the keyboard and print out every message with that string as
// its subject.

#include <iostream>
#include <map>
#include <string>
#include "Mail.h"

//------------------------------------------------------------------------------

// Given a pointer to a Message, return the subject or an empty string if
// there is no subject.
std::string find_from_subject(const Message* m);

//------------------------------------------------------------------------------

int is_prefix(const std::string& s, const std::string& p);

//------------------------------------------------------------------------------

bool find_from_addr(const Message* m, std::string& s);

//------------------------------------------------------------------------------

// TODO: Re-read carefully the instructions for this exercise (above) and redo
// the exercise rather than starting from ex1 as an example. Don't rush it!
int main()
{
  try {
    std::cout << "Please enter a subject to search for: ";
    std::string subject;
    std::cin >> subject;
    std::cout << '\n';
    std::cout << "Messages matching query \"" << subject << "\":\n";

    Mail_file m_file{"my-mail-file.txt"};  // init mail file

    // init multimap to store subjects matching subject
    std::multimap<std::string, const Message*> sender;
    for (const auto& m : m_file) {
      std::string s;
      if (find_from_addr(&m, s)) sender.insert(std::make_pair(s, &m));
    }

    // print each message with subject as its subject
    auto pp = sender.equal_range(subject);
    for (auto p = pp.first; p != pp.second; ++p) {
      std::cout << find_from_subject(p->second) << '\n';
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

std::string find_from_subject(const Message* m)
{
  for (const auto& x : *m) {
    if (int n = is_prefix(x, "Subject: ")) { return std::string(x, n); }
  }
  return "";
}

//------------------------------------------------------------------------------

int is_prefix(const std::string& s, const std::string& p)
{
  int n = p.size();
  if (std::string(s, 0, n) == p) return n;
  return 0;
}

//------------------------------------------------------------------------------