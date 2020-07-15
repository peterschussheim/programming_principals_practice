/*
  Implement an allocator (§19.3.7) using the basic allocation functions malloc()
  and free() (§B.11.4).

  Get vector as defined by the end of §19.4 to work for a few simple test cases.

  Hint: Look up “placement new ” and “explicit call of destructor” in a
  complete C++ reference.
*/

#include <iostream>
#include <stdexcept>
#include <memory>

//------------------------------------------------------------------------------

template<class T>
class allocator {
public:
  T* allocate(int n);            // allocate space for n objects of type T
  void deallocate(T* p, int n);  // destroy n objects of type T starting at p
  void construct(T* p, const T& v);  // construct a T with the value v in p
  void destroy(T* p);                // destroy the T in p
};

//------------------------------------------------------------------------------

template<class T, class A = allocator<T>>
class vector {
  A alloc;    // allocate memory for vector elements
  int sz;     // vector size
  T* elem;    // pointer to vector elements
  int space;  // size + free_space

public:
  vector() : sz{0}, elem{0}, space{0} {}
  vector(int s);

  vector(const vector&);  // copy constructor
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int main()
{
  try {
    std::cout << "hello world!\n";
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