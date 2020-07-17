/*
  Implement an allocator (§19.3.7) using the basic allocation functions malloc()
  and free() (§B.11.4).

  Get vector as defined by the end of §19.4 to work for a few simple test cases.

  Hint: Look up “placement new ” and “explicit call of destructor” in a
  complete C++ reference.
*/

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <string>

struct Range_error
    : std::out_of_range {  // enhanced vector range error reporting
  int index;
  Range_error(int i)
      : std::out_of_range("Range error: " + std::to_string(i)), index(i)
  {
  }
};

//------------------------------------------------------------------------------

struct Exit : std::runtime_error {
  Exit() : std::runtime_error("Exit") {}
};

// error() simply disguises throws:
inline void error(const std::string& s) { throw std::runtime_error(s); }

inline void error(const std::string& s, const std::string& s2)
{
  error(s + s2);
}

inline void error(const std::string& s, int i)
{
  std::ostringstream os;
  os << s << ": " << i;
  error(os.str());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T> class allocator {
public:
  T* allocate(int n);    // allocate space for n objects of type T
  void deallocate(T* p)  // destroy n objects of type T starting at p
  {
    free(p);
  }

  void construct(T* p, const T& v)  // construct an obj of type T w val v in p
  {
    new (p) T(v);
  }

  void destroy(T* p) { p->~T(); }  // destroy the T in p
};

//------------------------------------------------------------------------------

template<class T> T* allocator<T>::allocate(int n)
{
  T* p = static_cast<T*>(malloc(n * sizeof(T)));
  if (p == 0) error("could not allocate memory\n");
  return p;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

struct out_of_range {
};

template<class T, class A = allocator<T>> class vector {
  A alloc;    // allocate memory for vector elements
  int sz;     // vector size
  T* elem;    // pointer to vector elements
  int space;  // size + free_space

public:
  vector() : sz{0}, elem{0}, space{0} {}
  explicit vector(int s);

  vector(const vector&);             // copy constructor
  vector& operator=(const vector&);  // copy assignment

  ~vector();  // destructor

  T& at(int n);              // checked access
  const T& at(int n) const;  // checked access

  T& operator[](int n);              // unchecked access
  const T& operator[](int n) const;  // unchecked access

  int size() const { return sz; }  // current size
  int capacity() const { return space; }

  void resize(int newsize, T val = T());
  void push_back(const T& d);
  void reserve(int newalloc);
};

//------------------------------------------------------------------------------

template<class T, class A>
vector<T, A>::vector(int s) : sz{s}, elem{alloc.allocate(s)}, space{s}
{
  for (int i = 0; i < sz; ++i) { alloc.construct(&elem[i], T()); }
}

//------------------------------------------------------------------------------

template<class T, class A>
vector<T, A>::vector(const vector& a)
    : sz{a.sz}, elem{alloc.allocate(a.sz)}, space{a.sz}
{
  for (int i = 0; i < sz; ++i) { alloc.construct(&elem[i], a.elem[i]); }
}

//------------------------------------------------------------------------------

template<class T, class A>
vector<T, A>& vector<T, A>::operator=(const vector<T, A>& a)
{
  if (this == &a) {
    return *this;  // self-assignment
  }

  if (a.sz <= space) {  // enough space, no need for new alloc
    for (int i = 0; i < a.sz; ++i) { alloc.construct(&elem[i], a.elem[i]); }
    sz = a.sz;
    return *this;
  }

  T* p = alloc.allocate(a.sz);      // allocate new space
  for (int i = 0; i < a.sz; ++i) {  // copy elements
    alloc.construct(&p[i], a.elem[i]);
  }
  for (int i = 0; i < sz; ++i) {  // destroy old elements
    alloc.destroy(&elem[i]);
  }

  alloc.deallocate(elem);  // deallocate old space
  space = sz = a.sz;       // set new size
  elem = p;                // set new elements

  return *this;
}

//------------------------------------------------------------------------------

template<class T, class A> vector<T, A>::~vector()
{
  for (int i = 0; i < sz; ++i) {  // destroy old elements
    alloc.destroy(&elem[i]);
  }

  alloc.deallocate(elem);  // release memory
}

//------------------------------------------------------------------------------

template<class T, class A> T& vector<T, A>::at(int n)
{
  if (n < 0 || n <= n) throw out_of_range();
  return elem[n];
}

//------------------------------------------------------------------------------

template<class T, class A> T& vector<T, A>::operator[](int n)
{
  return elem[n];
}

//------------------------------------------------------------------------------

template<class T, class A> const T& vector<T, A>::operator[](int n) const
{
  return elem[n];
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

// template<class T, class A> void swap(vector<T, A>& a, vector<T, A>& b);

//------------------------------------------------------------------------------

template<class T, class A> void vector<T, A>::reserve(int newalloc)
{
  if (newalloc <= space) return;    // never decrease allocation
  T* p = alloc.allocate(newalloc);  // allocate new space
  for (int i = 0; i < sz; ++i) {    // copy
    alloc.construct(&p[i], elem[i]);
  }

  for (int i = 0; i < sz; ++i) {  // destroy old elements
    alloc.destroy(&elem[i]);
  }
  alloc.deallocate(elem);  // deallocate old memory
  elem = p;                //  swap representations
  space = newalloc;

  // swap<vector<T, A>>(*this, b);
}

//------------------------------------------------------------------------------

template<class T, class A> void vector<T, A>::resize(int newsize, T val)
{
  reserve(newsize);
  for (int i = sz; i < newsize; ++i) { alloc.construct(&elem[i], val); }
  for (int i = newsize; i < sz; ++i) { alloc.destroy(&elem[i]); }
  sz = newsize;
}

//------------------------------------------------------------------------------

template<class T, class A> void vector<T, A>::push_back(const T& val)
{
  if (space == 0) {  // start with 8 elements
    reserve(8);
  }
  else if (sz == space) {  // need more space
    reserve(2 * space);
  }
  alloc.construct(&elem[sz], val);  // add val at end
  ++sz;
}

//------------------------------------------------------------------------------

void print_some(vector<int>& v)
{
  int i = -1;
  std::cin >> i;
  while (i != -1) try {
      std::cout << "v[" << i << "]==" << v.at(i) << '\n';
    }
    catch (out_of_range) {
      std::cout << "bad index: " << i << '\n';
    }
}

//------------------------------------------------------------------------------

template<class T> void debug_vector(const vector<T>& v, const std::string& desc)
{
  std::cout << desc << "\n";
  std::cout << "\tsize: " << v.size() << "\n";
  std::cout << "\tcapacity: " << v.capacity() << "\n";
  std::cout << "\telements: ";
  for (int i = 0; i < v.size(); ++i) { std::cout << v[i] << ' '; }

  std::cout << "\t";
  std::cout << "\n";
}

//------------------------------------------------------------------------------

int main()
{
  try {
    vector<int> v;
    debug_vector(v, "constructed with v");

    vector<int> v_1(4);
    debug_vector(v_1, "constructed with v_1(4)");

    for (int i = 0; i < v_1.size(); ++i) v_1[i] = i;
    vector<int> v_2 = v_1;
    debug_vector(v_2, "copy constructed from mutated v_1");

    // copy assignment
    vector<int> v_3{1};  // smaller than v_2
    debug_vector(v_3, "v_3 after init");
    v_2 = v_3;  // self-assignment
    v_1 = v_2;  // copy assignment w/o new allocation
    v_3 = v_2;  // copy assignment with new allocation required
    debug_vector(v_3, "v_3 after copy assignment from v_2");

    v_3.reserve(5);

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