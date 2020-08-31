// Exercise 3: Implement count() yourself. Test it.
// Exercise 4: Implement count_if() yourself. Test it.

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>

namespace Z {
  // Counts the number of elements in the range [first, last) satisfying
  // specific criteria.
  // clang-format off
  template<class InputIt, class T>
  typename std::iterator_traits<InputIt>::difference_type
  count(InputIt first, InputIt last, const T& value);
  // clang-format on

  // Count the number of elements in the range [first, last) for which predicate
  // p returns true;
  // clang-format off
  template<class InputIt, class UnaryPredicate>
  typename std::iterator_traits<InputIt>::difference_type
  count_if(InputIt first, InputIt last, UnaryPredicate p);
  // clang-format on
}

int main()
{
  try {
    std::vector<int> v{4, 8, 6, 9, 7, 1, 0, 0, 2, 3, 99, 1, 8, 87};
    std::list<int> li{4, 8, 6, 9, 7, 1, 0, 0, 2, 3, 99, 1, 8, 87};

    // count() tests
    int target_1{5};
    int target_2{8};

    int num_items_v_1 = Z::count(v.begin(), v.end(), target_1);
    int num_items_v_2 = Z::count(v.begin(), v.end(), target_2);

    std::cout << "number: " << target_1 << " count: " << num_items_v_1 << '\n';
    std::cout << "number: " << target_2 << " count: " << num_items_v_2 << '\n';

    auto num_items_li_1 = Z::count(li.begin(), li.end(), target_1);
    auto num_items_li_2 = Z::count(li.begin(), li.end(), target_2);

    std::cout << "number: " << target_1 << " count: " << num_items_li_1 << '\n';
    std::cout << "number: " << target_2 << " count: " << num_items_li_2 << '\n';

    // count_if() tests

    auto num_odds_v =
        Z::count_if(v.begin(), v.end(), [](int n) { return n % 2 != 0; });
    auto num_evens_greater_li =
        Z::count_if(li.begin(), li.end(), [](int n) { return n % 2 && n > 9; });

    std::cout << "predicate: odds "
              << " count: " << num_odds_v << '\n';
    std::cout << "predicate: evens > 9 "
              << " count: " << num_evens_greater_li << '\n';

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

// clang-format off
template<class InputIt, class T>
typename std::iterator_traits<InputIt>::difference_type
Z::count(InputIt first,InputIt last, const T& value)
{
  typename std::iterator_traits<InputIt>::difference_type ret = 0;

  for (; first != last; ++first) {
    if (*first == value) { ++ret; }
  }
  return ret;
}
// clang-format on

// clang-format off
template<class InputIt, class UnaryPredicate>
typename std::iterator_traits<InputIt>::difference_type
Z::count_if(InputIt first, InputIt last, UnaryPredicate p)
{
  typename std::iterator_traits<InputIt>::difference_type ret = 0;
  for (; first != last; ++first) {
    if (p(*first)) ++ret;
  }

  return ret;
}
// clang-format on