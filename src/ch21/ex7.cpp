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
#include <list>

//------------------------------------------------------------------------------

// Searches for target in vector<int> v, returning true if found, otherwise
// false.
bool binary_search(const std::vector<int>& v, const int target);

//------------------------------------------------------------------------------

// Prints to stdout the result of a binary search on a sorted container
template<typename T> void print_search_result(T target, bool found);

//------------------------------------------------------------------------------

int main()
{
  try {
    std::vector<int> vi{0, 1, 2, 4, 44, 65, 69, 79, 88, 99, 100, 391};
    const int target_1 = 100;
    const int target_2 = 1000;
    auto res_target_1 = binary_search(vi, target_1);
    auto res_target_2 = binary_search(vi, target_2);

    print_search_result(target_1, res_target_1);
    std::cout << '\n';
    print_search_result(target_2, res_target_2);

    // std::list<std::string> li{};
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

// TODO: Rewrite using binary search algorithm:
// select a mid point in the vector. If vector[midpoint] == target, return true.
// otherwise, compare vector[midpoint] to target; if target is less, run search
// on left half. if target is greater, run search on righ half.
bool binary_search(const std::vector<int>& v, const int target)
{
  for (auto p = v.begin(); p != v.end(); ++p) {
    if ((*p) == target) return true;
  }
  return false;
}

template<typename T> void print_search_result(T target, bool found)
{
  std::cout << "Target " << target << " ";
  if (found) { std::cout << "was found\n"; }
  else {
    std::cout << "was not found\n";
  }
}
