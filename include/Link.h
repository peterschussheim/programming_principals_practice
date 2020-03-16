#include <string>

using namespace std;

struct God {
  string name;
  string mythology;
  string vehicle;
  string weapon;
  God(const string& n, const string& m, const string& v, const string& w)
      : name{n}, mythology{m}, vehicle{v}, weapon{w}
  {
  }
};

class Link {
public:
  God value;
  Link(const string& n, const string& m, const string& v, const string& w,
       Link* p = nullptr, Link* s = nullptr)
      : value{n, m, v, w}, prev{p}, succ{s}
  {
  }

  Link* insert(Link* n);        // insert n before this object
  Link* add(Link* n);           // insert n after this object
  Link* add_ordered(Link* n);   // insert n in its correct lexicographical pos
  Link* erase();                // remove this object from list
  Link* find(const string& s);  // find s in list
  const Link* find(const string& s) const;  // find s in const list (18.5.1)

  Link* advance(int n) const;  // move n positions in list

  // immutable getters enable users to iterate over lists
  // since direct access to prev and succ is not allowed
  Link* next() const { return succ; }
  Link* previous() const { return prev; }

private:
  Link* prev;
  Link* succ;
};

//------------------------------------------------------------------------------

Link* Link::insert(Link* n)  // insert n before this object and return n
{
  if (n == nullptr) return this;
  if (this == nullptr) return n;
  n->succ = this;  // this object comes AFTER n
  if (prev) { prev->succ = n; }

  n->prev = prev;  // this object's predecessor becomes n's predecessor
  prev = n;        // n becomes this object's predecessor
  return n;
}

//------------------------------------------------------------------------------

Link* Link::add(Link* n)  // insert n AFTER this object
{
  if (n == nullptr) return this;
  if (this == nullptr) return n;
  n->prev = this;
  if (succ) { succ->prev = n; }

  n->succ = succ;
  succ = n;
  return n;
}

//------------------------------------------------------------------------------

/*
  Expected to be called with the head of a list (first element).

  We have two obvious cases to handle:
    1) insert in lexicographic order AFTER head.  No need to update head.
    2) Insert requires updating current head element
*/
Link* Link::add_ordered(Link* n)
{
  if (n == nullptr) return this;
  if (this == nullptr) {  // new list
    n->succ = nullptr;
    n->prev = nullptr;
    return n;
  }

  if (n->value.name < value.name) {
    Link* p = insert(n);  // need to set a new head
    return p;
  }

  Link* p = this;
  while (n->value.name >= p->value.name) {
    if (p->succ == nullptr) {  // reached list tail
      p->add(n);               // add n as new tail element
      return this;             // head has not changed
    }
    p = p->succ;
  }
  p->insert(n);
  return this;
}

//------------------------------------------------------------------------------

Link* Link::erase()  // remove *p from list; return p's successor
{
  if (this == nullptr) return nullptr;
  if (succ) succ->prev = prev;
  if (prev) prev->succ = succ;
  prev = nullptr;
  succ = nullptr;
  return this;
}

//------------------------------------------------------------------------------

Link* Link::find(const string& s)  // find s in list
{
  Link* p = this;
  while (p) {
    if (p->value.name == s) return p;
    p = p->succ;
  }
  // return nullptr if not found
  return nullptr;
}

//------------------------------------------------------------------------------

const Link* Link::find(const string& s) const
{
  if (value.name == s)
    return this;
  else if (succ)
    return succ->find(s);

  return nullptr;
}