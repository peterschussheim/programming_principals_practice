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
#include <vector>

// holds a pointer to an object of type T and a pointer to an int containing a
// shared count of the number pointers to the same object of type T.
template<class T> class counted_ptr {
  T* data;
  int* use_count;  // # of shared_ptr objects pointing to the same managed obj

public:
  explicit counted_ptr(T* d)
      : data{d}, use_count{new (std::nothrow) int{1}}  // prevent exceptions
  {
    if (use_count == nullptr)  // ensure pointer was allocated properly
    {
      delete data;             // delete pointer on failure
      throw std::bad_alloc();  // manually throw the exception
    }
  }

  ~counted_ptr()
  {
    --(*use_count);
    if (*use_count == 0) { delete data; }
  }

  counted_ptr(counted_ptr const& copy)  // copy constructor
      : data{copy.data}, count{copy.count}
  {
    ++(*count);
  }

  counted_ptr& operator=(counted_ptr const& rhs)  // assignment operator
  {
    // copy and swap idiom used here
    // note: this can be simplified further by passing rhs by value instead
    // of by reference and then calling swap on *this object.
    counted_ptr temp{rhs};
    std::swap(data, temp.data);
    std::swap(count, temp.count);

    return *this;  // after this method completes, temp's destructor is called
  }

  T* operator->() const { return data; }
  T& operator*() const { return *data; }

  // access to internal state
  T* get() const { return data; }
  explicit operator bool() const { return data; }
};

struct Base {
  Base() { std::cout << "Base::Base()\n"; }
  ~Base() { std::cout << "Base::~Base()\n"; }
};

// TODO:
// - [ ] write reasonably comprehensive tests
// - [ ] read related article about common problems implementing shared-ptr
//       constructors

int main()
{
  try {
    Base b_1;
    // Base* ptr_to_base = &b_1;

    counted_ptr<Base> ptr{&b_1};

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