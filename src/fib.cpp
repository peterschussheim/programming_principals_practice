/**
   01/28/2020
   Peter Schussheim

   Chapter 8, Exercise #3
    - create a vector of fibonacci numbers and print them
      using a function print(string label, vector<int> v);
  */

#include <iostream>
#include <vector>

using namespace std;

void print(string label, vector<int> v);

/**
 * prints a vector of ints to cout.
 * accepts a string to label output and a vector
 */
void print(string label, vector<int> v) {
  for (int val : v) {
    cout << label << " " << val << '\n';
  }
}

vector<int> fibonacci(int x, int y, vector<int> v, int n);

/**
 * returns a vector<ints> containing n fibonacci
 * numbers.
 *
 * The sequence should start using its x and y arguments.
 *
 * ex: vector<int> result = fibonacci(1, 2, v, 10);
 * -> 1, 2, 3, 5, 8, 13, 21, etc...
 */
vector<int> fibonacci(int x, int y, vector<int> v, int n) {
  // f(0) = 0
  // f(1) == 1
  v[0] = x;
  v[1] = y;

  for (int i = y + 1; i < n; ++i) {
    v[i] = v[i - 2] + v[i - 1];
  }
}
