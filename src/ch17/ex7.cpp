#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

/*
  Write a program that reads characters from cin into an array that you
  allocate on the free store. Read individual characters until an exclamation
  mark ( ! ) is entered. Do not use a std::string . Do not worry about mem-
  ory exhaustion.
*/

/*
  Accepts as the first argument a const char pointer to the base 'array' we are
  expanding as we get chars from cin and the second argument is a const char
  pointer of the char we want to 'add' to arr.

  Usage:
  int main()
  {
    char* a = new char; // base array which will we add to
    char ch;            // read into from cin
    while(cin.get(ch) && ch != '!') {
      a = add_and_expand_arr(a, ch);
    }
  }

  */
char* resize_arr(char* arr)
{
  if (arr == 0) return 0;
  int n = string_length(arr);  // get the length of arr

  // allocate n + 2 memory since we are adding a char and must
  // terminate the string with 0
  char* p_arr = new char[n + 2];

  // copy original string into p_arr
  for (int i = 0; arr[i]; ++i) { p_arr[i] = arr[i]; }

  p_arr[n] = 0;  // terminate with a zero

  delete[] arr;  // free memory since we copied into p_arr
  return p_arr;
}

int main()
{
  try {
    char* my_array = new char[1];  // allocate our array on the heap
    *my_array = 0;  // to make a c-style string, terminate with a 0
    char ch = 0;
    while (cin.get(ch) && ch != '!') {
      my_array = resize_arr(my_array);
      int n = string_length(my_array);
      my_array[n] = ch;
      my_array[n + 1] = 0;
    }

    cout << my_array << '\n';

    delete[] my_array;

    keep_window_open("~");
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