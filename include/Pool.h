#ifndef POOL_H
#define POOL_H

//------------------------------------------------------------------------------

template<typename T, int N>
class Pool  // Pool of N objects of type T
{
public:
  Pool();                 // Make a pool of N Ts
  T* get();               // get a T from the pool; return 0 is no free Ts avail
  void free(T* obj);      // return a T given out by get() to the pool
  int available() const;  // number of free Ts

private:
  T objects[N];       // block of objects for this Pool
  bool free_list[N];  // Maintains list of free objects that can be used.
                      // free_list[N] = true indicates an available object.
  int unused;         // Count of free objects (which are currently unused)
};

//------------------------------------------------------------------------------

template<typename T, int N>
inline Pool<T, N>::Pool()
    : objects(),
      free_list(),
      // as expected, initializing a new Pool with space for N objects
      // of type T results in free_list being initialized to N:
      unused(N)
{
}

//------------------------------------------------------------------------------

// Get an available object from the Pool.
template<typename T, int N> inline T* Pool<T, N>::get()
{
  for (int i = 0; i < N; ++i)  // look in free_list for an available object
  {
    if (free_list[i])  // found an available object
    {
      free_list[i] = false;  // set list elem to indicate in use
      --unused;              // reduce unused count
      return &objects[i];    // return pool object to the programmer
    }
  }
  return 0;  // nothing available, could be improved to handle exceptions.
}

//------------------------------------------------------------------------------

// Free object obj to the Pool for later use.
template<typename T, int N> inline void Pool<T, N>::free(T* obj)
{
  // reset object T to default state
  *obj = T();
  ++unused;

  // update free_list
  free_list[obj - objects] = true;
}

//------------------------------------------------------------------------------

// How many unused objects are available?
template<typename T, int N> inline int Pool<T, N>::available() const
{
  return unused;
}

//------------------------------------------------------------------------------

#endif  // POOL_H