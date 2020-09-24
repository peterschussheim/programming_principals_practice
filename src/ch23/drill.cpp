// 2. Get the little program from §23.7 to work; that may involve figuring out
// how to set the project and/or command-line options to link to the regex
// library and use the regex headers.
//
// 3. Use the program from drill 2 to test the patterns from §23.7.

//------------------------------------------------------------------------------

#include <iostream>
#include <regex>
#include <string>
#include <fstream>

//------------------------------------------------------------------------------

void parse_zip_codes();
void verify_and_parse_lines();  // §23.8

//------------------------------------------------------------------------------

int main()
{
  try {
    // parse_zip_codes();  // program from §23.7

    // demonstrates error handling with regular expressions
    verify_and_parse_lines();

    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}

//------------------------------------------------------------------------------

void verify_and_parse_lines()
{
  std::regex pattern;
  std::string pat;

  std::cout << "enter pattern: ";
  getline(std::cin, pat);  // read the pattern

  try {
    pattern = pat;  // check pat is valid expression
    std::cout << "pattern: " << pat << '\n';
  }
  catch (const std::regex_error& e) {
    std::cout << "regex error caught: " << e.what() << '\n';
    std::cout << pat << " is not a valid regular expression\n";
    exit(1);
  }

  std::cout << "now enter lines:\n";
  int line_no = 0;

  for (std::string line; getline(std::cin, line);) {
    ++line_no;
    std::smatch matches;
    if (std::regex_search(line, matches, pattern)) {
      std::cout << "line " << line_no << ": " << line << '\n';
      for (int i = 0; i < matches.size(); ++i) {
        std::cout << "\tmatches[" << i << "]: " << matches[i] << '\n';
      }
    }
    else {
      std::cout << "didn't match\n";
    }
  }
}

//------------------------------------------------------------------------------

void parse_zip_codes()
{
  std::ifstream in{"file.txt"};
  if (!in) std::cerr << "no file\n";

  std::regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};  // postal code pattern

  int line_no = 0;

  // read input line into input buffer
  for (std::string line; getline(in, line);) {
    ++line_no;
    std::smatch matches;  // matched strings go here
    if (std::regex_search(line, matches, pat)) {
      std::cout << line_no << ": " << matches[0] << '\n';
    }
  }
}
