// After each operation (as defined by a line of this drill) print the vector.
// 1. Define a struct Item { string name; int iid; double value; /* . . . */ };,
//  make a vector<Item> , vi , and fill it with ten items from a file.
// 2. Sort vi by name.
// 3. Sort vi by iid .
// 4. Sort vi by value; print it in order of decreasing value (i.e., largest
// value first).
// 5. Insert Item("horse shoe",99,12.34) and Item("Canon S400", 9988,499.95) .
// 6. Remove (erase) two Item s identified by name from vi .
// 7. Remove (erase) two Item s identified by iid from vi .
// 8. Repeat the exercise with a list<Item> rather than a vector<Item>

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <string>

template<typename T> void print_container(T& t);
//------------------------------------------------------------------------------

struct Item {
  std::string name;
  int iid;
  double value;
  Item() : name{""}, iid{0}, value{0.0} {}
  Item(std::string n, int id, double v) : name{n}, iid{id}, value{v} {}
};

std::istream& operator>>(std::istream& is, Item& i)
{
  // Item format from file: string, int, double
  std::string n;
  int id;
  double v;

  is >> n >> id >> v;

  if (!is) return is;

  i = Item{n, id, v};  // update Item i
  return is;
}

std::ostream& operator<<(std::ostream& os, Item& i)
{
  return os << i.name << "\t" << i.iid << "\t" << i.value << '\n';
}

struct by_name {
  bool operator()(Item& a, Item& b) const { return a.name < b.name; }
};

class by_iid {
public:
  bool operator()(Item& a, Item& b) const { return a.iid < b.iid; }
};

class Smaller_than {  // used to insert element while retaining order based on
                      // item value
  Item itm;

public:
  Smaller_than(Item i) : itm{i} {}
  bool operator()(Item& i) const { return itm.value < i.value; }
};

int main()

{
  std::string from{"items.txt"};

  std::ifstream is{from};  // open input stream

  std::vector<Item> vi;
  for (Item ii; is >> ii;) vi.push_back(ii);
  print_container(vi);
  std::cout << '\n';

  // sort vi by name
  std::sort(vi.begin(), vi.end(), by_name{});
  print_container(vi);

  std::cout << '\n';
  //  Sort vi by iid
  std::sort(vi.begin(), vi.end(), by_iid{});
  print_container(vi);

  std::cout << '\n';
  // Sort vi by value;
  std::sort(vi.begin(), vi.end(),
            [&](Item& a, Item& b) { return a.value < b.value; });
  print_container(vi);
  std::cout << '\n';

  // print it in order of decreasing value (i.e., largest value first).
  std::cout << "Name"
            << "\t"
            << "ID"
            << "\t"
            << "Value\n\n";
  for (auto p = vi.crbegin(); p != vi.crend(); ++p)
    std::cout << (*p).name << '\t' << (*p).iid << '\t' << (*p).value << '\n';

  std::cout << '\n';
  // 5. Insert Item("horse shoe",99,12.34) and Item("Canon S400", 9988,499.95).
  Item temp{Item("horse shoe", 99, 12.34)};
  vi.insert(std::find_if(vi.begin(), vi.end(), Smaller_than{temp}), temp);
  print_container(vi);
  std::cout << '\n';

  temp = {"Canon S400", 9988, 499.95};
  vi.insert(std::find_if(vi.begin(), vi.end(), Smaller_than{temp}), temp);
  print_container(vi);
  std::cout << '\n';

  // 6. Remove (erase) two Items identified by name from vi.
  // Name_equals remove_by_name{"Canon S400"};
  vi.erase(std::find_if(vi.begin(), vi.end(),
                        [](Item& i) { return i.name == "Canon S400"; }));

  vi.erase(std::find_if(vi.begin(), vi.end(),
                        [](Item& i) { return i.name == "horse shoe"; }));
  print_container(vi);
  std::cout << '\n';

  // 7. Remove (erase) two Items identified by iid from vi.
  vi.erase(std::find_if(vi.begin(), vi.end(),
                        [](Item& i) { return i.iid == 3651548; }));
  vi.erase(std::find_if(vi.begin(), vi.end(),
                        [](Item& i) { return i.iid == 19928; }));
  print_container(vi);
  std::cout << '\n';
  std::cout << '\n';
  std::cout << "Repeating previous exercises with std::list<Item>\n";
  // 8. Repeat the exercise with a list<Item> rather than a vector<Item>
  std::list<Item> li;
  std::ifstream is_2{from};
  for (Item i; is_2 >> i;) li.push_back(i);
  print_container(li);
  std::cout << '\n';

  // TODO: complete using std::list
  return 0;
}

template<typename T> void print_container(T& t)
{
  std::cout << "Name"
            << "\t"
            << "ID"
            << "\t"
            << "Value\n\n";

  for (auto& item : t) std::cout << item;
}
