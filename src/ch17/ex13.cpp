#include "Utils.h"
#include "Link.h"
#include <iostream>
#include <vector>

/*
  Modify the Link class from §17.10.1 to hold a value of a struct God.
  struct God should have members of type string : name, mythology, vehicle, and
  weapon. For example, God{"Zeus", "Greek", "", "lightning"} and God{"Odin",
  "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}.

  - [x] Write a print_all() function that lists gods with their attributes one
        per line.

  - [ ] Add a member function add_ordered() that places its new element in its
        correct lexicographical position.

  - [ ] Using the Links with the values of type God, make a list of gods from
        three mythologies; then move the elements (gods) from that list to
        three lexicographi-cally ordered lists — one for each mythology.
*/

ostream& operator<<(ostream& os, const God& g)
{
  os << g.name << ", " << g.mythology << ", " << g.weapon << ", " << g.vehicle;

  return os;
}

void print_all(Link* p)
{
  cout << "{\n";
  while (p) {
    cout << "  " << p->value << '\n';

    if (p = p->next()) cout;
  }

  cout << "}\n";
}

Link* extract(Link* l, string s)
{
  Link* p = l->find(s);
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

int main()
{
  try {
    /*
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
*/
    // build a linked list of gods (norse and greek)
    Link* gods = new Link{"Odin", "Norse", "Sleipner", "Gungnir"};
    gods = gods->insert(new Link{"Zeus", "Greek", "", "lightning"});
    gods = gods->insert(new Link{"Freia", "Norse", "Chariot", ""});
    gods = gods->insert(new Link{"Hera", "Greek", "Chariot", "Pomegranate"});
    gods =
        gods->insert(new Link{"Tyr", "Norse", "chariot", "spear of justice"});
    gods = gods->insert(new Link{"Athena", "Greek", "", "Spear"});
    gods = gods->insert(
        new Link{"Mars", "Greek", "Chariot", "Spear, sword and shield"});
    gods = gods->insert(new Link{"Poseidon", "Greek", "Chariot", "Trident"});
    gods = gods->insert(new Link{"Ares", "Greek", "chariot", "random spear"});

    print_all(gods);
    cout << '\n';

    // init two new list heads to build lists ordered lexicographically by name
    // and split between mythology

    Link* ordered_norse = nullptr;
    Link* ordered_greek = nullptr;

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