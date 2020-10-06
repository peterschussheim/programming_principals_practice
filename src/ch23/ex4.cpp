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

int main()
{
  try {
    std::cout << "Opening large mail file...";
    Mail_file m_file{"large_mail.txt"};
    std::cout << " Done!\n";

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
