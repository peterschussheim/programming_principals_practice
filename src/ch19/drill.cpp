#include <iostream>
#include <vector>
#include <string>

template<typename T> struct S {
  S(T v) : val{v} {}
  T& get();
  void set(T v);

private:
  T val;
};

template<typename T> T& S<T>::get() { return val; }

template<typename T> void S<T>::set(T v) { val = v; }

int main()
{
  S<int> s_int{3};
  S<char> s_char{'p'};
  S<double> s_double{3.92};
  S<std::string> s_str{"Hello, world!"};
  S<std::vector<int>> s_v{{1, 2, 3, 4, 5}};

  /*std::cout << s_int.val << '\n';
  std::cout << s_char.val << '\n';
  std::cout << s_double.val << '\n';
  std::cout << s_str.val << '\n';
  for (auto i : s_v.val) std::cout << i << ' ';
  std::cout << '\n';*/
  std::cout << "Original values:\n";
  std::cout << s_int.get() << '\n';
  std::cout << s_char.get() << '\n';
  std::cout << s_double.get() << '\n';
  std::cout << s_str.get() << '\n';
  for (auto el : s_v.get()) std::cout << el << ' ';
  std::cout << '\n';
  std::cout << '\n';

  // use S::set
  s_int.set(99);
  s_char.set('l');
  s_double.set(99.33);
  s_str.set("Bye, world!");
  s_v.set({10, 9, 8, 7, 6});

  std::cout << "Modified values:\n";
  std::cout << s_int.get() << '\n';
  std::cout << s_char.get() << '\n';
  std::cout << s_double.get() << '\n';
  std::cout << s_str.get() << '\n';
  for (auto el : s_v.get()) std::cout << el << ' ';
  std::cout << '\n';

  // TODO: resume drill, part 10
  return 0;
}