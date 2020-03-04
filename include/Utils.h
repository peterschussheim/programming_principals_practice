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