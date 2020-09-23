// In the Fruit example in §21.6.5, we copy Fruits into the set. What if
// we didn’t want to copy the Fruits? We could have a set<Fruit*> instead.
// However, to do that, we’d have to define a comparison operation for that
// set. Implement the Fruit example using a set<Fruit*, Fruit_comparison>.
// Discuss the differences between the two implementations.

// This was another good exercise which highlights a few of the drawbacks
// of operating on raw pointers rather than an alternative such as returning
// a copy.  Aside from having to explicitly delete each Fruit we created on the
// free store, the difference from simply copying Fruits comes down to less
// code to maintain in the future and a reduced surface for bugs related to
// raw pointer use, namely, resource leaks.

#include <iostream>
#include <set>
#include <string>

struct Date {
  int y;  // year
  int m;  // month
  int d;  // day
};

//------------------------------------------------------------------------------

struct Fruit {
  std::string name;
  int count;
  double unit_price;
  Date last_sale_date;
  Fruit(std::string nn, int cc = 1, double u_price = 0.0)
      : name{nn}, count{cc}, unit_price{u_price}
  {
  }
};

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream&, const Fruit& f);
std::ostream& operator<<(std::ostream&, Fruit* f);

//------------------------------------------------------------------------------

struct Fruit_comparison {
  bool operator()(const Fruit& a, const Fruit& b) const
  {
    return a.name < b.name;
  }
  bool operator()(const Fruit* a, const Fruit* b) const
  {
    return (*a).name < (*b).name;
  }
};

//------------------------------------------------------------------------------

int main()
{
  try {
    std::set<Fruit*, Fruit_comparison> inventory;
    inventory.insert(new Fruit{"quince", 5});  // allocate on heap
    inventory.insert(new Fruit{"orange", 50, 0.99});
    inventory.insert(new Fruit{"plum", 3, 0.75});
    inventory.insert(new Fruit{"pineapple", 10, 3.99});
    inventory.insert(new Fruit{"grape", 8, 3.59});
    for (auto item : inventory) { std::cout << item << '\n'; }
    for (auto item : inventory) delete item;  // clean up resources

    std::cout << "\n";
    // repeat using std::set<Fruit, Fruit_comparison>;
    std::set<Fruit, Fruit_comparison> inv_fruit;

    inv_fruit.insert(Fruit{"quince", 5});
    inv_fruit.insert(Fruit{"orange", 50, 0.99});
    inv_fruit.insert(Fruit{"plum", 3, 0.75});
    inv_fruit.insert(Fruit{"pineapple", 10, 3.99});
    inv_fruit.insert(Fruit{"grape", 8, 3.59});
    for (auto& item : inv_fruit) { std::cout << item << "\n"; }

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

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Fruit& f)
{
  return os << "(" << f.name << ", " << f.count << ", " << f.unit_price << ")";
}

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, Fruit* f)
{
  return os << "(" << (*f).name << ", " << (*f).count << ", " << (*f).unit_price
            << ")";
}
