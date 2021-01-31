// Implement a simple vector that can hold at most N elements allocated
// from a pool. Test it for N==1000 and integer elements.

#include <exception>
#include <iostream>
#include "Pool_vector.h"

//------------------------------------------------------------------------------

template<class T, size_t N>
Pool_vector<T, N>::Pool_vector() : pool(), data(), sz(0)
{
}

//------------------------------------------------------------------------------

template<class T, size_t N>
Pool_vector<T, N>::Pool_vector(size_t size) : pool(), data(), sz(size)
{
  // if size > N, reduce size to N and set sz to N
  if (size > N) {
    std::cout << "Argument size is too large, reducing size from " << size
              << " to " << N << "size\n";
    sz = N;
  }
  // allocate objects up to sz using pool.get()
  for (int i = 0; i < sz; ++i) { data[i] = pool.get(); }
}

//------------------------------------------------------------------------------

template<class T, size_t N> T& Pool_vector<T, N>::operator[](size_t index)
{
  return *data[index];
}

//------------------------------------------------------------------------------

template<class T, size_t N> void Pool_vector<T, N>::push_back(T elem)
{
  // TODO:
}

//------------------------------------------------------------------------------

struct Point {
  int x, y;
  Point();
  Point(int xx, int yy);
};

//------------------------------------------------------------------------------

int main()
{
  try {
    Pool_vector<Point, 1000> pv;
    return 0;
  }
  catch (const std::exception& e) {
    std::cout << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cout << "Unhandled exception\n";
    return 2;
  }
}