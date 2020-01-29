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

/**
 * prints a vector of ints to cout.
 * accepts a string to label output and a vector
 * as well as a boolean if user wants the indices printed.
 */
void print(string label, vector<int> v, bool print_idx) {
  for (int i = 0; i < v.size() - 1; ++i) {
    cout << label << ((print_idx == true) ? i : ' ') << ": " << v[i] << '\n';
  }
}

/**
 * Accepts a reference to an empty vector<ints>, a "seed"
 * in the form of the first two numbers in the sequence, x, y,
 * and an int n specifying how many fibonacci numbers to generate.
 *
 * The sequence should start using its x and y arguments.
 *
 * This definition operates directly on its argument v using a plain reference.
 *
 * vector<int> v;
 * ex: fibonacci(1, 2, v, 10);
 * -> 1, 2, 3, 5, 8, 13, 21, etc...
 */
void fibonacci(int x, int y, vector<int>& v, int n) {
  // set x and y to v[0] and v[1], respectively
  v.push_back(x);
  v.push_back(y);

  for (int i = 2; i < n; ++i) {        // loop is initialized at index 2
    v.push_back(v[i - 2] + v[i - 1]);  // ith element equals the sum of the previous two elements
  }
}
