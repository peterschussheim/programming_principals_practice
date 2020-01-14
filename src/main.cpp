#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <algorithm>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }


int main() {
  // Detects if two words entered into stdin are repeated
  // and if true, output the repeated word.

  string previous = " ";
  string current;

  while (cin >> current) {
    if (previous == current) {
      cout << "repeated word: " << current << "\n";
    }

    previous = current;
  }
}

//int main() {
//  cout << "Please enter a integer value: ";
//  int n;
//
//  cin >> n;
//  cout << "n == " << n
//    << "\nn+1 == " << n + 1
//    << "\nthree modulo n == " << 3 % n
//    << "\ntwice n == " << n + n
//    << "\nn squared " << n * n
//    << "\nhalf of n == " << n / 2
//    << "\nn square root of n == " << sqrt(n)
//    << '\n'; // end of line in output
//}

// Console program which asks the user to enter their first name
// and their age in years (including a decimal).

// The program outputs to standard out the first name and the age
// converted into the number of months.
//int main()
//{
//  cout << "Please enter your first name and age\n";
//  string first;
//  double age;
//
//  cin >> first >> age;
//  cout << "Hello, " << first << " " << age * 12 << "\n";
//}
