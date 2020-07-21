/*
  Implement a simple unique_ptr supporting only a constructor, destructor,
  –> , * , and release() . In particular, don’t try to implement an assignment
  or a copy constructor.
*/

#include <iostream>
#include "std_lib_facilities.h"

/*
  This exercise highlights the Three Guarantees:

  1) The basic guarantee: when using `try...catch` to prevent resources leaking,
     we want the function in question to either succeed or throw an exception.

  2) The strong guarantee: in addition to providing the basic guarantee, a fn
    also ensures all non local values of the function are the SAME after failure
    as when we initially called the function, this function is said to provide
    the string guarantee.  If the function does its intended job, we expect
    nothing else to happen, otherwise, throw an exception indication failure.

  3) The no throw guarantee: As the name suggests, this implies that a function
    simply does not throw exceptions.
*/

namespace red_wings {
  template<class T> class unique_ptr {
    T* data;

  public:
    unique_ptr() : data{nullptr} {}
    explicit unique_ptr(T* d) : data{d} {}
    ~unique_ptr() { delete data; }
    unique_ptr(std::nullptr_t) : data{d} {}  // binds to nullptr

    // unique_ptr& operator=(std::nullptr_t)
    //{
    //  reset();
    //  return *this;
    //}
    // unique_ptr(unique_ptr&& moving) noexcept  // ctor providing move
    //{
    //  moving.swap(*this);
    //}
    // unique_ptr& operator=(unique_ptr&& moving) noexcept  // move via
    // assignment
    //{
    //  moving.swap(*this);
    //  return *this;
    //}

    // remove compiler generated copy operations
    // unique_ptr(unique_ptr const&) = delete;
    // unique_ptr& operator=(unique_ptr const&) = delete;

    // const access to the owned object
    T* operator->() const { return data; }
    T& operator*() const { return *data; }

    // get pointer state
    T* get() const { return data; }
    explicit operator bool() const { return data; }

    // modify object state
    T* release() noexcept
    {
      T* result = nullptr;
      std::swap(result, data);
      return result;
    }
    void swap(unique_ptr& src) noexcept { std::swap(data, src.data); }
    void reset()
    {
      T* tmp = release();
      delete temp;
    }
  };
  template<typename T> void swap(unique_ptr<T>& lhs, unique_ptr<T>& rhs)
  {
    lhs.swap(rhs);
  }
}

red_wings::unique_ptr<vector<int>> make_vec()
{
  red_wings::unique_ptr<vector<int>> p{new vector<int>};  // alloc on free store
  // fill vector, may throw exception
  for (int i = 0; i < 25; ++i) { p->push_back(i * 2); }
  return p;  // now the user doesn't have to worry about deleting the pointer
}

int main()
{
  try {
    red_wings::unique_ptr<vector<int>> t_1 = make_vec();
    red_wings::unique_ptr<vector<int>> t_2 = make_vec();

    // t_1 = std::move(t_2);
    // red_wings::unique_ptr<vector<int>> t_3{std::move(t_2)};

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

// naive version returning a raw pointer to the vector<int>
// vector<int>* make_vec()
//{
//  vector<int>* p = new vector<int>;
//  try {
//    // fill vector; may throw exception
//    return p;
//  }
//  catch (const std::exception&) {
//    delete p;
//    throw;
//  }
//}