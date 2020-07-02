/*
  Modify class Link from §17.9.3 to be a template with the type of value
  as the template argument. Then redo exercise 13 from Chapter 17 with
  Link<God>

  - [x] Write a print_all() function that lists gods with their attributes one
      per line.

  - [x] Add a member function add_ordered() that places its new element in its
        correct lexicographical position.

  - [x] Using the Links with the values of type God, make a list of gods from
        three mythologies; then move the elements (gods) from that list to
        three lexicographi-cally ordered lists; one for each mythology.
        (only made lists for two civilizations, Greek and Norse)
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
// this is a rewrite of the file Link.h using templates

template<class T>
class Link {  // doubly-linked list
public:
  Link(const T& v, Link* p = 0, Link* s = 0) : value{v}, prev{p}, succ{s} {}
  Link* insert(Link<T>* n);       // insert n before this object and return n
  Link* add(Link<T>* n);          // insert n after this object
  Link* add_ordered(Link<T>* n);  // place n in its correct lexicographical pos
  Link* find(const string& s);    // find node s in list
  Link* erase();                  // remove this object from list

  // immutable getters for member data
  T val() const { return value; }
  Link* next() const { return succ; }
  Link* previous() const { return prev; }

private:
  T value;  // node value
  Link* prev;
  Link* succ;
};

//------------------------------------------------------------------------------

template<class T>
void print_all(Link<T>* p)  // print all nodes in list
{
  cout << "{\n";
  while (p) {
    cout << "  " << p->val() << '\n';
    if (p = p->next()) cout;
  }

  cout << "}\n";
}

//------------------------------------------------------------------------------

template<class T>
Link<T>* Link<T>::insert(Link<T>* n)
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

template<class T>
Link<T>* Link<T>::add(Link<T>* n)  // insert n AFTER this object
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

template<class T>
Link<T>* Link<T>::add_ordered(Link<T>* n)
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

template<class T>
Link<T>* extract(Link<T>* l, string s)
{
  Link<T>* p = l->find(s);
  if (p) {
    if (p == l && p->next())
      l = p->next();
    else {
      l = nullptr;
    }
    p->erase();
    return p;
  }
  return nullptr;  // s not found
}

//------------------------------------------------------------------------------

template<class T>
Link<T>* Link<T>::erase()
{
  if (this == nullptr) return nullptr;
  if (succ) succ->prev = prev;
  if (prev) prev->succ = succ;
  prev = nullptr;
  succ = nullptr;
  return this;
}

//------------------------------------------------------------------------------

template<class T>
Link<T>* Link<T>::find(const string& s)  // find s in list
{
  Link* p = this;
  while (p) {
    if (p->value.name == s) return p;
    p = p->succ;
  }

  return nullptr;  // return nullptr if not found
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

    // init two new list heads to build lists ordered lexicographically by name
    // and split between mythology

    Link<God>* ordered_norse = nullptr;
    Link<God>* ordered_greek = nullptr;

    ordered_norse = ordered_norse->add_ordered(extract(gods, "Odin"));
    ordered_norse = ordered_norse->add_ordered(extract(gods, "Thor"));
    ordered_norse = ordered_norse->add_ordered(extract(gods, "Freia"));

    ordered_greek = ordered_greek->add_ordered(extract(gods, "Hera"));
    ordered_greek = ordered_greek->add_ordered(extract(gods, "Athena"));
    ordered_greek = ordered_greek->add_ordered(extract(gods, "Poseidon"));
    ordered_greek = ordered_greek->add_ordered(extract(gods, "Zeus"));
    ordered_greek = ordered_greek->add_ordered(extract(gods, "Ares"));

    print_all(ordered_norse);
    cout << '\n';
    print_all(ordered_greek);
    cout << '\n';
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