// Modify the email example from §23.4 to use regular expressions to find
// the subject and sender.

#include <iostream>
#include <map>
#include <string>
#include <regex>
#include "Mail.h"

//------------------------------------------------------------------------------

std::string find_prefix(const Message* m, const std::string& s);
std::string find_subject(const Message* m);
//------------------------------------------------------------------------------

int main()
{
  try {
    std::cout << "Please enter a subject to search for: ";
    std::string query;
    getline(std::cin, query);
    std::cout << '\n';

    Mail_file m_file{"my-mail-file.txt"};
    std::multimap<std::string, const Message*> subject;

    for (const auto& msg : m_file) {
      std::string subj = find_subject(&msg);
      if (subj != "") { subject.insert(std::make_pair(subj, &msg)); }
    }

    std::cout << "Messages with subject matching query \"" << query << "\":\n"
              << '\n';
    auto pp = subject.equal_range(query);           // beginning of a Message
    for (auto p = pp.first; p != pp.second; ++p) {  // print each Message

      std::cout << *p->second << '\n';
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

std::string find_prefix(const Message* m, const std::string& s)
{
  // return the string after the matched text in m that begins with s
  // or an empty string if not found.
  std::regex pattern{"^" + s + "(.*)$"};
  std::smatch matches;
  for (auto p = m->begin(); p != m->end(); ++p) {
    bool matched = std::regex_match(*p, matches, pattern);
    if (matched) return matches[1];
  }

  return "";
}

//------------------------------------------------------------------------------

// return the subject of the Message, if any, otherwise ""
std::string find_subject(const Message* m)
{
  return find_prefix(m, "Subject: ");
}

//------------------------------------------------------------------------------