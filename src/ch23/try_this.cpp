#include <iostream>
#include <map>
#include <string>
#include "Mail.h"

//------------------------------------------------------------------------------

// find name of the sender in a Messafe;
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

int main()
{
  try {
    Mail_file mfile{"my-mail-file.txt"};  // init mfile from a file

    // gather messages from each sender together in a multimap

    std::multimap<std::string, const Message*> sender;
    for (const auto& m : mfile) {
      std::string s;
      if (find_from_addr(&m, s)) sender.insert(std::make_pair(s, &m));
    }

    // iterate through the multimap and extract the subjects of John Doe's msgs:
    auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
    for (auto p = pp.first; p != pp.second; ++p) {
      std::cout << find_subject(p->second) << '\n';
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