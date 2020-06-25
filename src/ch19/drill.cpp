#include <iostream>
#include <vector>
#include <string>

template<typename T> struct S {
private:
  T val;

  S(T v) : val{v} {}
  T& get();
};

template<typename T> T& S<T>::get() { return val; }

int main()
{
  S<int> s_int{3};
  S<char> s_char{'p'};
  S<double> s_double{3.92};
  S<std::string> s_str{"Hello, world!"};
  S<std::vector<int>> s_v{{1, 2, 3, 4, 5}};

  std::cout << s_int.val << '\n';
  std::cout << s_char.val << '\n';
  std::cout << s_double.val << '\n';
  std::cout << s_str.val << '\n';
  for (auto i : s_v.val) std::cout << i << ' ';
  std::cout << '\n';

  std::cout << s_int.get();
  return 0;
}