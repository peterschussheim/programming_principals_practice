// 4. Find a real email message file (containing real email messages) and mod-
// ify the email example to extract subject lines from sender names taken as
// input from the user.
//
// 5. Find a large email message file (thousands of messages) and then time it
// as written with a multimap and with that multimap replaced by an unor-
// dered_multimap . Note that our application does not take advantage of
// the ordering of the multimap

#include <iostream>
#include <map>
#include <string>
#include <regex>
#include "Mail.h"

// modifying enron file to terminate messages with  "----".

//------------------------------------------------------------------------------

// Return a substring of the matched text in Message* m begininng with s,
// or an empty string if not found.
std::string find_prefix(const Message* m, const std::string& s);

// Return the subject of a Message* m or an empty string if none found.
// Note, this returns only the actual subject, without the prefix string
// "Subject: "
std::string find_subject(const Message* m);

// Return a string of the message sender or an empty string if none found.
std::string find_sender(const Message* m);

//------------------------------------------------------------------------------

int main()
{
  try {
    std::cout << "Opening large mail file...";
    Mail_file m_file{"large_mail.txt"};
    std::cout << " Done!\n";

    std::multimap<std::string, const Message*> sender;

    // build multimap of messages keyed by sender name
    for (const auto& msg : m_file) {
      std::string from = find_sender(&msg);  // extract the sender in this msg
      if (from != "") sender.insert(std::make_pair(from, &msg));
    }

    std::cout << "Processed " << sender.size() << " messages.\n";
    std::cout << "Enter a sender email address to search for: ";
    std::string query;  // sender user wants to find
    getline(std::cin, query);

    // print results
    std::cout << "\n";
    std::cout << "Found the following messages from " << query << ":\n";
    std::cout << "-------------------------------------------------------------"
                 "-----------------\n";
    auto pp = sender.equal_range(query);
    int count = 1;  // print a count next to each result for readibility
    for (auto p = pp.first; p != pp.second; ++p) {
      std::cout << count << ": " << find_subject(p->second) << '\n';
      ++count;
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

// Return a substring of the matched text in Message* m begininng with s,
// or an empty string if not found.
std::string find_prefix(const Message* m, const std::string& s)
{
  // start in the beginning ^,
  // concactenate with string s and additional regex (.*)$:
  // match any single character except line feed/carriage return
  // and unlimited number of times, until the end of the line.
  std::regex pattern{"^" + s + "(.*)$"};
  std::smatch matches;
  for (auto p = m->begin(); p != m->end(); ++p) {
    bool matched = std::regex_match(*p, matches, pattern);
    if (matched) return matches[1];
  }

  return "";
}

//------------------------------------------------------------------------------

// Return the subject of a Message* m or an empty string if none found.
// Note, this returns only the actual subject, without the prefix string
// "Subject: "
std::string find_subject(const Message* m)
{
  return find_prefix(m, "Subject: ");
}

std::string find_sender(const Message* m) { return find_prefix(m, "From: "); }

//------------------------------------------------------------------------------