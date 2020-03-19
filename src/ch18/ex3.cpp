#include <iostream>
#include "Utils.h"

using namespace std;

/*
  Write a function, int strcmp(const char* s1, const char* s2) , that compares
  C-style strings. Let it return a negative number if s1 is lexicographically
  before s2 , zero if s1 equals s2 , and a positive number if s1 is lexicograph-
  ically after s2 . Do not use any standard library functions. Do not use
  subscripting; use the dereference operator * instead.
*/

/*
  compares two C-style strings at a time using lexicographic ordering.

  Returns:
    -1 if s1 < s2
    0 if s1 == s2
    1 if s1 > s2
*/
int strcmp(const char* s1, const char* s2)
{
  while (*s1) {
    if (!*s2) return 1;
    if (*s1 < *s2) return -1;
    if (*s1 > *s2) return 1;
    ++s1;
    ++s2;
  }
  if (*s2) return -1;  // true when s2 is longer than s1
  return 0;
}

// TODO: FINISH THIS AND UNDERSTAND ALL THE EDGE CASES
void tests()
{
  char s_11[] = "in";
  char s_12[] = "into";
  int test_00 = strcmp(s_11, s_12);  // s1 > s2 -> 1

  char ss3[] = "fall";
  char sss3[] = "fell";
  int test_3 = strcmp(ss3, sss3);  // s1 < s2 -> -1

  char s11[] = "into";
  char s12[] = "in";
  int test_0 = strcmp(s11, s12);  // s1 > s2 -> 1

  char s1[] = "win";
  char s2[] = "win";
  int test_1 = strcmp(s1, s2);  // s1 == s2 -> 0

  char ss[] = "woz";
  char sss[] = "wox";
  int test_2 = strcmp(ss, sss);  // s1 > s2 -> 1
}

int main()
{
  try {
    char str1[] = "catfish";
    char str2[] = "fish";
    int result_1 = strcmp(str1, str2);
    cout << "result: " << result_1;

    keep_window_open();
    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}