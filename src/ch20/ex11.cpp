// Given a list<int> as a (by-reference) parameter, make a vector<double>
// and copy the elements of the list into it. Verify that the copy was complete
// and correct. Then print the elements sorted in order of increasing value.

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>

template<class T, class Q> void copy_to_vec(std::list<T>& l, std::vector<Q>& v);
template<class T> void print(T c);

int main()
{
  std::list<int> lst{3, 22, 1, 9, 7, 8, 2, 11, 32};  // source list
  std::vector<double> vec;
  copy_to_vec(lst, vec);

  std::cout << "lst: ";
  print(lst);
  std::cout << '\n';

  std::cout << "vec: ";
  print(vec);
  std::cout << '\n';

  std::cout << "vec sorted in ascending order: ";
  std::sort(vec.begin(), vec.end());
  print(vec);
  std::cout << '\n';
  return 0;
}

template<class T, class Q> void copy_to_vec(std::list<T>& l, std::vector<Q>& v)
{
  for (auto& el : l) { v.push_back(el); }
}

template<class T> void print(T c)
{
  for (auto it = c.cbegin(); it != c.cend(); ++it) { std::cout << *it << ' '; }
}
