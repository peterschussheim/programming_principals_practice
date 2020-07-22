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
//#include <vector>
#include "std_lib_facilities.h"

struct Tracer {
  Tracer() : val(0) { cout << "Def ctor\n"; }
  Tracer(int n) : val(n) { cout << "Arg ctor " << n << "\n"; }
  Tracer(const Tracer& t) : val(t.val) { cout << "Cpy ctor " << val << "\n"; }
  Tracer& operator=(const Tracer& t)
  {
    val = t.val;
    cout << "Copy assgn: " << val << "\n";

    return *this;
  }
  ~Tracer() { cout << "Destroyed: " << val << "\n"; }
  int val;
};

//------------------------------------------------------------------------------

// holds a pointer to an object of type T and a pointer to an int containing a
// shared count of the number pointers to the same object of type T.
template<class T> class counted_ptr {
  T* data;
  int* use_count;  // # of shared_ptr objects pointing to the same managed obj

public:
  // explicit counted_ptr(T* d)
  //    : data{d}, use_count{new (std::nothrow) int{1}}  // prevent exceptions
  //{
  //  if (use_count == nullptr)  // ensure pointer was allocated properly
  //  {
  //    delete data;  // delete pointer on failure
  //    delete use_count;
  //    throw std::bad_alloc();  // manually throw the exception
  //  }
  //}
  // clang-format off
  explicit counted_ptr(T* d)
  try 
    : data {d}
    , use_count{new int(1)}
  {}
  // clang-format on
  catch (...)
  {
    delete data;
    throw;
  }
  ~counted_ptr()
  {
    --(*use_count);
    if (*use_count == 0) {
      delete data;
      // delete use_count;
    }
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

  void swap(counted_ptr& other) noexcept
  {
    std::swap(data, other.data);
    std::swap(count, other.count);
  }

  T* operator->() const { return data; }
  T& operator*() const { return *data; }

  // access to internal state
  T* get() const { return data; }
  explicit operator bool() const { return data; }
};

//------------------------------------------------------------------------------

template<class T> void test_3(const counted_ptr<T>& ptr_2)
{
  counted_ptr<Tracer> test_1_ptr{Tracer{0}};
  test_1_ptr = ptr_2;
  std::cout << "test_1_ptr->data: " << test_1_ptr->val
            << '\n';  // test arrow operator

  std::cout << "test_1_ptr.get(): " << test_1_ptr.get()
            << '\n';  // test get access

  std::cout << "test_1_ptr->use_count: " << test_1_ptr->use_count
            << '\n';  // test arrow operator

  std::cout << "ptr_2->use_count: " << ptr_2->use_count << '\n';
}

//------------------------------------------------------------------------------

template<class T> void test_2(const counted_ptr<T>& ptr_1)
{
  counted_ptr<T> test_2_ptr{ptr_1};
  std::cout << "test_2_ptr->data: " << test_2_ptr->data << '\n';
  std::cout << "test_2_ptr.get(): " << test_2_ptr.get() << '\n';
  std::cout << "test_2_ptr->use_count: " << test_2_ptr->use_count << '\n';
  test_3(test_2_ptr);
  std::cout << "test_2_ptr->use_count: " << test_2_ptr->use_count << '\n';
}

//------------------------------------------------------------------------------

void test()
{
  Tracer t{99};
  counted_ptr<Tracer> p{&t};
  // std::cout << "p->data: " << p->data << '\n';
  // std::cout << "p.get(): " << p.get() << '\n';
  // std::cout << "p->use_count: " << p->use_count << '\n';
  // test_2(p);
  // std::cout << "p->use_count: " << p->use_count << '\n';
}

//------------------------------------------------------------------------------

/*
  todo:

  - [ ] figure out what I am doing to throw
        "Invalid address specified to RtlValidateHeap".

  - [ ] finish this!
*/

int main()
{
  try {
    // test for destruction when fn scope ends
    // counted_ptr specialization with vector
    test();
    std::cout << "\n";
    keep_window_open("");
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