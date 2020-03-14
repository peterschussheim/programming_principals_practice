#include "Utils.h"
#include "Link.h"
#include <iostream>

/*
  Modify the Link class from §17.10.1 to hold a value of a struct God.
  struct God should have members of type string : name, mythology, vehicle, and
  weapon. For example, God{"Zeus", "Greek", "", "lightning"} and God{"Odin",
  "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}.

  - Write a print_all() function that lists gods with their attributes one per
    line.

  - Add a member function add_ordered() that places its new element in its
    correct lexicographical position.

  - Using the Links with the values of type God, make a list of gods from three
    mythologies; then move the elements (gods) from that list to three
    lexicographi-cally ordered lists — one for each mythology.
*/

/*
  TODO: complete print_all with better formatting
*/
void print_all(Link* p)
{
  cout << "{ ";
  while (p) {
    cout << p->value.name << '\n';
    cout << '\t' << p->value.mythology << '\n';
    cout << '\t' << p->value.vehicle << '\n';
    cout << '\t' << p->value.weapon;
    if (p = p->next()) cout << ", ";
  }

  cout << " }";
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
    Link* norse_gods = new Link{God{"Odin", "Norse",
                                    "Eight-legged flying horse called Sleipner",
                                    "Spear called Gungnir"}};
    norse_gods =
        norse_gods->insert(new Link{God{"Zeus", "Greek", "", "lightning"}});
    norse_gods = norse_gods->insert(
        new Link{God{"Freia", "Norse", "Chariot pulled by two cats", ""}});

    //--------------------------------------------------------------------------

    Link* greek_gods = new Link{
        God{"Hera", "Greek", "Chariot pulled by peacocks", "Pomegranate"}};
    greek_gods =
        greek_gods->insert(new Link{God{"Athena", "Greek", "", "Spear"}});
    greek_gods = greek_gods->insert(
        new Link{God{"Mars", "Greek", "Chariot", "Spear, sword and shield"}});
    greek_gods = greek_gods->insert(
        new Link{God{"Poseidon", "Greek",
                     "chariot that was pulled by a hippocampus", "Trident"}});

    print_all(norse_gods);
    cout << '\n';
    print_all(greek_gods);
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