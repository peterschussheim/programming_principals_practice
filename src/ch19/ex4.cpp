/*
  Modify class Link from §17.9.3 to be a template with the type of value
  as the template argument. Then redo exercise 13 from Chapter 17 with
  Link<God>
*/
#include <iostream>
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

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

std::ostream& operator<<(std::ostream& os, const God& g)
{
  os << g.name << ", " << g.mythology << ", " << g.weapon << ", " << g.vehicle;

  return os;
}

//------------------------------------------------------------------------------

template<class T> class Link {  // doubly-linked list
public:
  Link(const T& v, Link* p = 0, Link* s = 0) : value{v}, prev{p}, succ{s} {}
  Link* insert(Link<T>* n);  // insert n before this object and return n

  T val() const { return value; }
  Link* next() const { return succ; }
  Link* previous() const { return prev; }

private:
  T value;
  Link* prev;
  Link* succ;
};

//------------------------------------------------------------------------------

template<class T> void print_all(Link<T>* p)  // print all nodes in list
{
  cout << "{\n";
  while (p) {
    cout << "  " << p->val() << '\n';
    if (p = p->next()) cout;
  }

  cout << "}\n";
}

//------------------------------------------------------------------------------

template<class T> Link<T>* Link<T>::insert(Link<T>* n)
{
  // check n and p for null
  if (n == nullptr) return this;
  if (this == nullptr) return n;

  n->succ = this;  // this object comes after n
  if (prev) { prev->succ = n; }

  n->prev = prev;  // p's predec is now n's predec
  prev = n;        // n becomes p's predec
  return n;
}

//------------------------------------------------------------------------------

int main()
{
  try {
    Link<God>* gods = new Link<God>{{"Odin", "Norse", "Sleipner", "Gungnir"}};
    gods = gods->insert(new Link<God>{{"Zeus", "Greek", "", "lightning"}});
    gods = gods->insert(new Link<God>{{"Freia", "Norse", "Chariot", ""}});
    gods = gods->insert(
        new Link<God>{{"Hera", "Greek", "Chariot", "Pomegranate"}});
    gods = gods->insert(
        new Link<God>{{"Tyr", "Norse", "chariot", "spear of justice"}});
    gods = gods->insert(new Link<God>{{"Athena", "Greek", "", "Spear"}});
    gods = gods->insert(
        new Link<God>{{"Mars", "Greek", "Chariot", "Spear, sword and shield"}});
    gods = gods->insert(
        new Link<God>{{"Poseidon", "Greek", "Chariot", "Trident"}});
    gods = gods->insert(
        new Link<God>{{"Ares", "Greek", "chariot", "random spear"}});

    print_all(gods);
    cout << '\n';
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << 'n';
    keep_window_open();
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    keep_window_open();
    return 2;
  }
}