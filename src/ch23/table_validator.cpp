#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include "std_lib_facilities.h"

int main()
{
  try {
    std::ifstream in{"table.txt"};
    // if (!in) error("no input file\n");

    std::string line;  // input buffer
    int line_no = 0;

    std::regex header{R"(^[\w ]+(    [\w ]+)*$)"};       // header line
    std::regex row{R"(^[\w ]+(    \d+)( \d+)( \d+)$)"};  // data line
    // std::regex row{R"(^[\w ]+(    \d+)( \d+)( \d+)$)"};
    if (getline(in, line)) {  // check header line
      std::smatch matches;
      if (std::regex_match(line, matches, header)) error("no header\n");
    }

    while (getline(in, line)) {
      // check line data
      ++line_no;
      std::smatch matches;
      if (!std::regex_match(line, matches, row))
        error("bad line", to_string(line_no));
    }
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}