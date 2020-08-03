/*
  Write a find-and-replace operation for Document s based on §20.6.2.
*/

//#include "std_lib_facilities.h"
#include "Document.h"
#include <iostream>
#include <fstream>
#include <string>

// TODO: Write replace function
// TODO: combine find and replace to make a find and replace method
// TODO: write tests for find and replace functionality
// TODO: replace std::find with my own simple implementation

bool match(Text_iterator first, Text_iterator last, const std::string& s)
{
  std::string::const_iterator p;
  for (p = s.begin(); p != s.end() && first != last && *p == *first;
       ++p, ++first) {}
  // if we reached the end of s, we matched everything
  return p == s.end();
}

Text_iterator find_txt(Text_iterator first, Text_iterator last,
                       const std::string& s)
{
  if (s.size() == 0) return last;  // cannot find an empty string
  char first_char = s[0];
  while (true) {
    auto p = std::find(first, last, first_char);
    if (p == last || match(p, last, s)) return p;
    first = ++p;  // look at the next character
  }
}

// Text_iterator replace_txt(Text_iterator first, Text_iterator last,
//                          const std::string& str)
//{
//}

std::istream& operator>>(std::istream& is, Document& d)
{
  for (char ch; is.get(ch);) {
    d.line.back().push_back(ch);  // add char to the end of the line
    if (ch == '\n') d.line.push_back(Line{});  // add a new Line
  }
  if (d.line.back().size()) d.line.push_back(Line{});  // add empty line ending
  return is;
}

void print(Document& d)
{
  for (auto p : d) std::cout << p;
}

int main()
{
  try {
    std::string target("The quick brown fox jumps over the lazy dog.");
    std::ifstream f_stream{"sample.txt"};
    Document sample_doc;
    f_stream >> sample_doc;
    // print(sample_doc);
    // std::cout << '\n';
    // Text_iterator p = find_txt(sample_doc.begin(), sample_doc.end(),
    //                           "The quick brown fox jumps over the lazy
    //                           dog.");
    // if (p == sample_doc.end()) {
    //  std::cout << "Target text not found in document.\n";
    //}
    // else {
    //  std::cout << "found target\n";
    //}

    Text_iterator p_2 =
        find_txt(sample_doc.begin(), sample_doc.end(), "secret\nhomestead");
    if (p_2 == sample_doc.end()) {
      std::cout << "Target text not found in document.\n";
    }
    else {
      std::cout << "found target: " << *p_2 << '\n';
    }
    // replace_txt(10, 5, "red");
    // std::cout << str << '\n';
    // replace_txt(str.begin(), str.begin() + 3, 1, "A");
    // std::cout << str << '\n';

    // std::string filename1 = "constitution.txt";
    // std::ifstream stream{filename1};
    // Document text1;
    // stream >> text1;
    // print(text1);

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