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

int main()
{
  try {
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