// Complete the definition of list from §20.4.1–2 and get the high() example
// to run. Allocate a Link to represent one past the end.

#include <iostream>

template<typename C> using Iterator = typename C::iterator;  // template alias

template<typename Elem> struct Link {
  Link* prev;  // previous link
  Link* succ;  // successor or next link
  Elem val;
  Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0)
      : val(v), prev(p), succ(s)
  {
  }
};
//------------------------------------------------------------------------------

template<typename Elem> class list {
  Link<Elem>* first;
  Link<Elem>* last;  // one beyond the last element (link)

public:
  class iterator;  // member type

  list() : first(new Link<Elem>()), last(first) {}

  iterator begin();  // iterator to the first element
  iterator end();    // iterator to one beyond the last element

  iterator insert(iterator p, const Elem& v);  // insert v into list AFTER p
  iterator erase(iterator p);                  // remove p from list

  void push_back(const Elem& v);   // insert v at end
  void push_front(const Elem& v);  // insert v at front
  void pop_back();                 // remove last elem
  void pop_front();                // remove first elem
  Elem& front();                   // get the first elem
  Elem& back();                    // get the last elem
};

//------------------------------------------------------------------------------

template<typename Elem> class list<Elem>::iterator {
  Link<Elem>* curr;  // current link

public:
  iterator(Link<Elem>* p) : curr{p} {}

  iterator& operator++()
  {
    curr = curr->succ;
    return *this;
  }
  iterator& operator--()
  {
    curr = curr->prev;
    return *this;
  }
  Elem& operator*() { return curr->val; }

  bool operator==(const iterator& b) const { return curr == b.curr; }
  bool operator!=(const iterator& b) const { return curr != b.curr; }
};

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
template<typename Elem> typename list<Elem>::iterator list<Elem>::begin()
{
  return iterator(first);
}

//------------------------------------------------------------------------------

template<typename Elem> typename list<Elem>::iterator list<Elem>::end()
{
  return iterator(last);
}

//------------------------------------------------------------------------------

template<typename Elem> void list<Elem>::push_front(const Elem& v)
{
  first = new Link<Elem>(v, 0, first);
}

//------------------------------------------------------------------------------

template<typename Iter>  // requires Input_iterator<Iter>()
Iter high(Iter first, Iter last)
{
  // return iterator to the element in [first,last) with highest val

  Iter h = first;  // create a local iterator using first
  for (Iter p = first; p != last; ++p) {
    // compare high to low and set high to p if p is greater than current high
    if (*h < *p) h = p;
  }

  return h;
}

//------------------------------------------------------------------------------

void f()
{
  using namespace std;

  list<int> lst;
  int x;
  while (cin >> x) lst.push_front(x);

  list<int>::iterator q = high(lst.begin(), lst.end());
  cout << "the highest value was " << *q << '\n';

  list<int>::iterator p = high(lst.begin(), lst.end());
  if (p == lst.end())  // did we reach the end?
    cout << "The list is empty";
  else
    cout << "the highest value is " << *p << '\n';
}

//------------------------------------------------------------------------------

int main()
{
  f();
  return 0;
}
