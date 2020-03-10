#pragma once
#include <iostream>

inline void keep_window_open()
{
  std::cin.clear();
  std::cout << "Please enter a character to exit\n";
  char ch;
  std::cin >> ch;
  return;
}

inline void keep_window_open(std::string s)
{
  if (s == "") return;
  std::cin.clear();
  std::cin.ignore(120, '\n');
  for (;;) {
    std::cout << "Please enter " << s << " to exit\n";
    std::string ss;
    while (std::cin >> ss && ss != s)
      std::cout << "Please enter " << s << " to exit\n";
    return;
  }
}

/*
  Prints size in kilobytes of built in types.
*/
void print_type_sizes()
{
  std::cout << "size of int: " << sizeof(int) << "kb\n";
  std::cout << "size of double: " << sizeof(double) << "kb\n";
  std::cout << "size of float: " << sizeof(float) << "kb\n";
  std::cout << "size of string: " << sizeof(std::string) << "kb\n";
  std::cout << "size of char: " << sizeof(char) << "kb\n";
}