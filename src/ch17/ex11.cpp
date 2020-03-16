#include "Utils.h"
#include <iostream>
#include "Link.h"

/*
  Complete the “list of gods” example from §17.10.1 and run it.

  Which do I prefer, having list operations as freestanding helper functions
  or as member functions?  At this point in learning c++ and proper OO design,
  I don't have a preference that screams out at me.  The helpers, implemented
  as freestanding functions, is reasonably clear to me and is closer to the
  style of JavaScript that I am accustomed to.  More specifically, this pattern
  (signature) of the freestanding version of a pointer and data argument is
  familiar.  However, from my limited experience of dealing with ownership in
  C++ and the notion that we should be writing 'modern' code, we should prefer
  the version with member functions. Why?

  Simply put, it is preferred to encapsulate pointer usage in a minimal
  container.  The member functions enable this coding style and enforce the
  semantics of hiding pointers and reducing the amount of pointer 'fiddling'
  users must do.
*/

/*
  12. Why did we define two versions of find()?

  To understand and illustrate design decisions and coding style related to
  ownership and contrast the styles to show how to avoid common sources of bugs.
*/

void print_all(Link* p)
{
  cout << "{ ";
  while (p) {
    cout << p->value;
    if (p = p->next()) cout << ", ";
  }

  cout << " }";
}

int main()
{
  try {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    // correct incorrect god of war name
    Link* p = greek_gods->find("Mars");  // find node to update
    if (p) p->value = "Ares";            // correct name

    // move zeus to correct pantheon
    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
      if (p2 == norse_gods) norse_gods->next();

      p2->erase();
      greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    cout << '\n';
    print_all(greek_gods);
    cout << '\n';
    keep_window_open();
    return 0;
  }
  catch (std::exception e) {
    std::cerr << e.what() << '\n';
    keep_window_open();
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    keep_window_open();
    return 2;
  }
}