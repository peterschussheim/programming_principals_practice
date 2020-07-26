#include <iostream>
#include <vector>
#include <string>

template<typename T> struct S {
  S(T v) : val{v} {}
  T& get();
  const T& get() const;
  S& operator=(const T& s);

private:
  T val;
};

template<class T> T& S<T>::get() { return val; }
template<class T> const T& S<T>::get() const { return val; }
template<class T> S<T>& S<T>::operator=(const T& s)
{
  if (val == s) return *this;

  val = s;
  return *this;
}

template<class T> std::istream& operator>>(std::istream& is, S<T>& ss)
{
  T v{};
  std::cin >> v;       // read into v
  if (!is) return is;  // handle failure state
  ss = v;              // what is this line doing?
  return is;
}

template<class T> void read_val(T& v)  // read from cin to v
{
  std::cin >> v;
}

template<class T> std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
  os << "{ ";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i < v.size() - 1) os << ',';
    os << ' ';
  }

  os << " }";
  return os;
}

template<class T> std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
  char ch1, ch2;
  T temp;
  std::vector<T> v_temp;
  is >> ch1;
  if (!is) return is;

  if (ch1 != '{') {
    is.clear(std::ios_base::failbit);
    return is;
  }
  while (std::cin >> temp >> ch2 && ch2 == ',') { v_temp.push_back(temp); }
  if (ch2 != '}') {
    is.clear(std::ios_base::failbit);
    return is;
  }

  v_temp.push_back(temp);  // read last line

  // copy temp to prevent v from mutating on is failure
  v = v_temp;
}

int main()
{
  S<int> s_int{3};
  S<char> s_char{'p'};
  S<double> s_double{3.92};
  S<std::string> s_str{"Hello, world!"};
  S<std::vector<int>> s_v{{1, 2, 3, 4, 5}};

  std::cout << "Original values:\n";
  std::cout << s_int.get() << '\n';
  std::cout << s_char.get() << '\n';
  std::cout << s_double.get() << '\n';
  std::cout << s_str.get() << '\n';
  for (auto el : s_v.get()) std::cout << el << ' ';
  std::cout << '\n';
  std::cout << '\n';

  std::cout << '\n';
  /*S<int> s_int2{333};
  s_int = s_int2;
  std::cout << s_int.get() << '\n';
  s_int = 90009;
  s_char = 'l';
  s_double = 99.33;
  s_str = "Bye, world!";
  s_v = {10, 9, 8, 7, 6};*/

  // std::cout << "\nenter a new int: ";
  // read_val(s_int);
  // std::cout << "\nenter a new char: ";
  // read_val(s_char);
  // std::cout << "\nenter a new double: ";
  // read_val(s_double);
  // std::cout << "\nenter a new string: ";
  // read_val(s_str);
  // std::cout << "Modified values:\n";
  // std::cout << s_int.get() << '\n';
  // std::cout << s_char.get() << '\n';
  // std::cout << s_double.get() << '\n';
  // std::cout << s_str.get() << '\n';
  // std::cout << '\n';

  read_val(s_v);
  std::cout << s_v.get() << '\n';

  return 0;
}