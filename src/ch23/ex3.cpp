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
    std::multimap<std::string, const Message*> subject;

    std::regex pattern{R"(Subject: (FW:|RE:)?(.*))"};
    int message_num = 0;  // counter for messages in this file

    for (const auto& msg : m_file) {
      ++message_num;
      std::smatch m;  // matched strings go here
      std::cout << "Message " << message_num << ":\n";

      for (const auto& line : msg) {  // look at each line in this message
        bool matched = std::regex_search(line, m, pattern);
        if (matched) {
          for (int i = 0; i < m.size(); ++i) {
            std::cout << "m[" << i << "] = " << m[i] << '\n';
          }
          subject.insert(std::make_pair(m[1], &msg));
        }
      }

      std::cout << '\n';
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
