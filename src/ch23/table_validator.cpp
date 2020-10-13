#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include "std_lib_facilities.h"

// Running into many exceptions when running this example.  The file is parsed
// as expected but I can only confirm that when commenting out the exception
// handling code.

template<typename T> T from_string(const std::string& s);
struct bad_from_string;

int main()
{
  try {
    std::ifstream in{"table.txt"};
    // if (!in) error("no input file\n");

    std::string line;  // input buffer
    int line_no = 0;

    std::regex header{R"(^[\w ]+(    [\w ]+)*$)"};       // header line
    std::regex row{R"(^[\w ]+(    \d+)( \d+)( \d+)$)"};  // data line

    if (getline(in, line)) {  // check header line
      std::smatch matches;
      if (std::regex_match(line, matches, header)) error("no header\n");
    }

    // column totals
    int boys = 0;
    int girls = 0;

    while (getline(in, line)) {
      ++line_no;
      std::smatch matches;
      if (!std::regex_match(line, matches, row))
        // std::cerr << "bad line: " << line_no << '\n';

        if (in.eof()) std::cout << "at eof\n";

      // check row
      int curr_boy = from_string<int>(matches[2]);
      int curr_girl = from_string<int>(matches[3]);
      int curr_total = from_string<int>(matches[4]);
      if (curr_boy + curr_girl != curr_total) std::cerr << "bad row sum \n";
      if (matches[1] == "Alle klasser") {  // the last line in table
        if (curr_boy != boys) std::cerr << "boys don't add up\n";
        if (curr_girl != girls) std::cerr << "girls don't add up\n";
        if (!(in >> ws).eof()) std::cerr << "characters after total line";
        return 0;
      }

      // update totals:
      boys += curr_boy;
      girls += curr_girl;
    }
    std::cerr << "didn't find total line\n";
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}

struct bad_from_string : std::bad_cast {  // report string cast errors
  const char* what() const override { return "bad cast from string\n"; }
};

template<typename T> T from_string(const std::string& s)
{
  std::istringstream is{s};
  T t;
  if (!(is >> t)) /*throw bad_from_string{};*/
    return t;
}