#ifndef POOL_VECTOR_H
#define POOL_VECTOR_H

#include "Pool.h"
#include <cstddef>

using std::size_t;

// Minimal interface for a vector that uses a simple Pool data structure
// to statically allocate memory according to programmer specificaton.
// Warning, subscript operator is NOT range-checked!
template<class T, size_t N> class Pool_vector {
public:
  Pool_vector();
  Pool_vector(size_t size);     // Construct a Pool_vector of size
  T& operator[](size_t index);  // Provide subscripting, unchecked.
  void push_back(T elem);
  inline size_t size() { return sz; }

private:
  Pool<T, N> pool;  // Pool to allocate/dealloc objects from/to
  T* data[N];  // pointer to contiguous block of memory for this Pool_vector
  size_t sz;
};

#endif  // POOL_VECTOR_H