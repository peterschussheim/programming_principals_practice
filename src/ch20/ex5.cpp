/*
  Define an input and an output operator ( >> and << ) for vector.
*/

#include "std_lib_facilities.h"

template<class T> istream& operator>>(istream& is, vector<T>& v)
{
  // read { T, T, T, T } vector of element type T
  char ch;  // use a char to read different serialized types
  is >> ch;
  if (ch != '{') error("vector must start with '{'");
  T el;
  while (true) {
    is >> ch;
    // check is state and for a closing bracket (end of input)
    if (is && ch == '}')
      return is;
    else  // make the most recently extracted char available again
      is.unget();
    is >> el;  // read element into local variable el
    if (is)
      v.push_back(el);
    else
      error("bad element\n");
  }

  return is;
}

template<class T> ostream& operator<<(ostream& os, vector<T>& v)
{
  os << "{";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i + 1 < v.size()) os << ",";
    os << " ";
  }
  os << "}";
  return os;
}

int main()
{
  try {
    vector<double> vd;
    vector<int> vi;
    vector<string> vs;
    std::cout << "Enter vector of doubles: ";
    std::cin >> vd;
    std::cout << "Enter vector of integers: ";
    std::cin >> vi;
    std::cout << "Enter vector of strings: ";
    std::cin >> vs;

    std::cout << vd << "\n" << vi << "\n" << vs << "\n";
    keep_window_open("");
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