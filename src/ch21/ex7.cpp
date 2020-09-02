// Write a binary search function for a vector<int> (without using the stan-
// dard one). You can choose any interface you like. Test it.

// How confident are you that your binary search function is correct?
// Now write a binary search function for a list<string>. Test it.

// How much do the two binary search functions resemble each other?
// How much do you think they would have resembled each other if you had not
// known about the STL?

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>

//------------------------------------------------------------------------------

// Searches for target in vector<int> v, returning true if found, otherwise
// false.
template<typename T>
bool my_binary_search(const std::vector<T>& v, const T& target);

template<typename ForwardIt, typename T>
bool my_binary_search(ForwardIt first, ForwardIt last, const T& target);

//------------------------------------------------------------------------------

template<typename ForwardIt, typename T>
ForwardIt my_lower_bound(ForwardIt first, ForwardIt last, const T& target);

//------------------------------------------------------------------------------

// Prints to stdout the result of a binary search on a sorted container
template<typename T> void print_search_result(T target, bool found);

//------------------------------------------------------------------------------

int main()
{
  try {
    std::vector<int> vi{79, 88, 0, 84, 44, 77765, 6, 99, 3, 100, 1, 2, 391};
    std::sort(vi.begin(), vi.end());
    const int target_1 = 100;
    const int target_2 = 1000;
    auto res_target_1 = my_binary_search(vi, target_1);
    auto res_target_2 = my_binary_search(vi, target_2);

    print_search_result(target_1, res_target_1);
    // std::cout << '\n';
    print_search_result(target_2, res_target_2);

    std::vector<std::string> vs{
        "Rust",      "Java",      "JavaScript", "Objective-C", "C++",   "C",
        "SmallTalk", "Brainfuck", "Algol 68",   "Cobol",       "Simula"};
    std::sort(vs.begin(), vs.end());
    const std::string target_s_1 = "Cobol";
    const std::string target_s_2 = "Lisp";
    auto res_target_s_1 = my_binary_search(vs, target_s_1);
    auto res_target_s_2 = my_binary_search(vs, target_s_2);
    print_search_result(target_s_1, res_target_s_1);
    print_search_result(target_s_2, res_target_s_2);

    std::list<std::string> ls{"Rust",     "Java",  "JavaScript", "Objective-C",
                              "C++",      "C",     "SmallTalk",  "Brainfuck",
                              "Algol 68", "Cobol", "Simula"};
    ls.sort();
    // TODO: Figure out why the tests below do not work correctly
    const std::string target_s_3 = "Java";
    const std::string target_s_4 = "C#";

    auto res_target_s3 = my_binary_search(ls.begin(), ls.end(), target_s_3);
    auto res_target_s4 = my_binary_search(ls.begin(), ls.end(), target_s_4);
    std::cout << "\n";
    std::cout << "list<string>:\n";
    print_search_result(target_s_3, res_target_s3);
    print_search_result(target_s_4, res_target_s4);

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

//------------------------------------------------------------------------------

// select a mid point in the vector. If vector[midpoint] == target, return
// true. otherwise, compare vector[midpoint] to target; if target is less, run
// search on left half. if target is greater, run search on righ half.
template<typename T>
bool my_binary_search(const std::vector<T>& v, const T& target)
{
  auto left = 0;
  auto right = v.size() - 1;
  while (left <= right) {
    auto mid = std::floor((left + right) / 2);
    if (v[mid] == target) { return true; }
    else if (v[mid] < target) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return false;
}

//------------------------------------------------------------------------------

template<typename ForwardIt, typename T>
bool my_binary_search(ForwardIt first, ForwardIt last, const T& target)
{
  // first = std::lower_bound(first, last, target);
  first = my_lower_bound(first, last, target);
  return (!(first == last) && (target < *first));
}

//------------------------------------------------------------------------------

template<typename ForwardIt, typename T>
ForwardIt my_lower_bound(ForwardIt first, ForwardIt last, const T& target)
{
  ForwardIt it;
  typename std::iterator_traits<ForwardIt>::difference_type count, step;
  count = std::distance(first, last);

  while (count > 0) {
    it = first;
    step = count / 2;
    std::advance(it, step);
    if (*it < target) {
      first = ++it;
      count = count - step + 1;
    }
    else {
      count = step;
    }
  }

  return first;
}

//------------------------------------------------------------------------------

template<typename T> void print_search_result(T target, bool found)
{
  std::cout << "Target " << target << " ";
  if (found) { std::cout << "was found\n"; }
  else {
    std::cout << "was not found\n";
  }
}
