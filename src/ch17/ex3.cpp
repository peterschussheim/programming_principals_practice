#include <iostream>
#include "Utils.h"

/*
  Write a function, void to_lower(char* s), that replaces all uppercase char-
  acters in the C-style string s with their lowercase equivalents. For ex-
  ample, Hello, World! becomes hello, world!. Do not use any standard
  library functions. A C-style string is a zero-terminated array of characters,
  so if you find a char with the value 0 you are at the end.
*/

/*
  the idea here is to loop from the first char, until the expression s[i] is
  false, which will occur when the we reach the null terminating character at
  the end of the sequence.  Recall that c-style strings are terminated with a
  zero.

  We check each char in the sequence to see if it is an uppercase char and if
  so, we mutate that element into its lowercase equivalent via addition of the
  difference between lowercase an uppercase a.  We will see in an alternative
  implementation that ASCII chars, specifically the letters, can be converted
  from upper to lower case via addition of 32.
*/
void to_lower(char* s)
{
  for (int i = 0; s[i]; ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z') { s[i] += 'a' - 'A'; }
  }
}

/*
  We present the same algorithm below as the previous function
  however, in this implementation, we use a few extra variables to
  better express and show the reader our intention.

  As we mentioned above, when working with ASCII chars, there is a 'special'
  property we can exploit: the difference between ANY lowercase letter and its
  uppercase sibling is exactly 32.  The rest of the algorithm is a matter of
  comparing each char in the sequence against a few constants which represent
  the range of uppercase letters to compare against.
*/
void to_lower_alternative(char* s)
{
  // constants mapping ascii codes for better readibility
  constexpr int A = 65;
  constexpr int Z = 90;
  constexpr int difference = 32;

  for (int i = 0; s[i]; ++i) {
    int char_code = int(s[i]);

    if (char_code >= A && char_code <= Z) { s[i] += difference; }
  }
}

void print_array(char* s)
{
  int i = 0;
  while (s[i]) {
    std::cout << s[i];
    ++i;
  }
  std::cout << '\n';
}

void test(std::string s)
{
  to_lower(&s[0]);
  print_array(&s[0]);
}

int main()
{
  try {
    char* ptr_to_s = "Peter_POINTER";
    std::cout << "original: ";
    print_array(ptr_to_s);
    std::cout << "after to_lower: ";
    test(ptr_to_s);

    char c_str2[] = "JeFFREY";
    std::cout << "original: ";
    print_array(c_str2);
    std::cout << "after to_lower: ";
    test(c_str2);

    keep_window_open("~");
    return 0;
  }
  catch (const std::exception& e) {
    std::cout << e.what() << '\n';
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled error\n";
    return 2;
  }
}