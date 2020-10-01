// Modify the email example from §23.4 to use regular expressions to find
// the subject and sender.

#include <iostream>
#include <map>
#include <string>
#include <regex>
#include "Mail.h"

//------------------------------------------------------------------------------

int main()
{
  try {
    std::cout << "Please enter a subject to search for: ";
    std::string query;
    getline(std::cin, query);
    std::cout << '\n';
    std::cout << "Messages matching query \"" << query << "\":\n" << '\n';

    Mail_file m_file{"my-mail-file.txt"};

    // init multimap to store Messages matching query
    std::multimap<std::string, const Message*> subject;

    std::regex subj{R"(Subject: )"};
    std::smatch matches;  // matched strings go here
    for (const auto& msg : m_file) {
      std::string s;
      if (/* regex_search(msg_line,matches,pattern)*/) {  // build map keyed by
                                                          // message subject

        subject.insert(std::make_pair(s, &msg));
      }
    }

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
