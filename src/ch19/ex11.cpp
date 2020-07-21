/*
  Design and implement a counted_ptr<T> that is a type that holds a
  pointer to an object of type T and a pointer to a “use count” (an int )
  shared by all counted pointers to the same object of type T.

  - The use count should hold the # of counted pointers pointing to a given T.

  - Let the counted_ptr’s constructor allocate a T object and a use count
    on the free store.

  - Let counted_ptr ’s constructor take an argument to be
    used as the initial value of the T elements.

  - When the last counted_ptr for a T is destroyed, counted_ptr ’s destructor
    should delete the T.

  - Give the counted_ptr operations that allow us to use it as a pointer.

  This is an example of a “smart pointer” used to ensure that an object doesn’t
  get destroyed until after its last user has stopped using it.

  Write a set of test cases for counted_ptr using it as an argument in calls,
  container elements, etc.
*/

#include <iostream>

// holds a pointer to an object of type T and a pointer to an int containing a
// shared count of the number pointers to the same object of type T.
template<class T> class counted_ptr {
  T* data;
  int* use_count;  // # of shared_ptr objects pointing to the same managed obj

public:
  // marking as explicit prevents the compiler from creating unneeded objects
  explicit counted_ptr(T* d) : data{d}, use_count{new int{1}} {}
  ~counted_ptr()
  {
    --(*use_count);
    if (*count == 0) { delete data; }
  }

  counted_ptr(counted_ptr const& copy)  // copy constructor
      : data{copy.data}, count{copy.count}
  {
    ++(*count);
  }
  counted_ptr& operator=(counted_ptr const& rhs)  // assignment operator
  {
    // retrain copy of old data
    T* old_data = data;
    int* old_use_count = use_count;

    // exception safe transfer
    data = rhs.data;
    use_count = rhs.use_count;

    // update both counters
    ++(*use_count);
    ++(*old_use_count);

    if (*old_use_count == 0)  // delete old ptr when appropriate
    {
      delete old_data;
    }
  }

  T* operator->() const { return data; }
  T& operator*() const { return *data; }

  // access to internal state
  T* get() const { return data; }
  explicit operator bool() const { return data; }
};

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