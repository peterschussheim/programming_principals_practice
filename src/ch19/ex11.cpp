/*
  Design and implement a counted_ptr<T> that is a type that holds a
  pointer to an object of type T and a pointer to a “use count” (an int )
  shared by all counted pointers to the same object of type T . The use
  count should hold the number of counted pointers pointing to a given
  T . Let the counted_ptr ’s constructor allocate a T object and a use count
  on the free store. Let counted_ptr ’s constructor take an argument to be
  used as the initial value of the T elements. When the last counted_ptr
  for a T is destroyed, counted_ptr ’s destructor should delete the T . Give
  the counted_ptr operations that allow us to use it as a pointer. This is
  an example of a “smart pointer” used to ensure that an object doesn’t
  get destroyed until after its last user has stopped using it. Write a set
  of test cases for counted_ptr using it as an argument in calls, container
  elements, etc.
*/

#include <iostream>

int main()
{
  try {
    std::cout << "\n";
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