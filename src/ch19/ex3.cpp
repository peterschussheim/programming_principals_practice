/*
  Write a template class Pair that can hold a pair of values of any type.
  Use this to implement a simple symbol table like the one we used in the
  calculator (§7.8).
*/
#include <iostream>
#include <exception>
#include <vector>
#include <string>

using namespace std;

template<class T, class U> class Pair {
public:
  T key;
  U value;
  Pair(T k, U val) : key{k}, value{val} {}
};

int main()
{
  try {
    Pair<string, double> p_1{"rate", 0.9};
    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "Unhandled exception\n";
    return 2;
  }
}