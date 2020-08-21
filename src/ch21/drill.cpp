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

template<typename T> void print_container(const T& t);
//------------------------------------------------------------------------------

struct Item {
  std::string name;
  int iid;
  double value;

  // Item() : name{""}, iid{0}, value{0.0} {}

  // Item(std::string n, int ident, double v) : name{n}, iid{ident}, value{v} {}
};

std::istream& operator>>(std::istream& is, Item& i)
{
  // Item format from file: string, int, double
  std::string n;
  int id;
  double v;

  char ch1, ch2;  // the two commas of an Item

  is >> n >> ch1 >> id >> ch2 >> v;

  if (!is) return is;
  if (ch1 != ',' || ch2 != ',') {  // format error
    is.clear(std::ios_base::failbit);
    return is;
  }

  i = Item{n, id, v};  // update Item i
  return is;
}

// So, I have spent the entire day on this drill trying to parse
// a comma separated file, "Product Name", 99131098, 44.02
// but I am not sure how to proceed without making a substantially more complex
// solution to this "drill".
int main()

{
  std::string from{"items.txt"};

  std::ifstream is{from};  // open input stream

  std::istream_iterator<Item> ii{is};
  std::istream_iterator<Item> eos;  // input sentinel

  // std::vector<Item> buffer(ii, eos);  // init from input
  std::vector<Item> inventory;
  for (Item ii; is >> ii;) std::cout print_container(inventory);

  return 0;
}

template<typename T> void print_container(const T& t)
{
  std::cout << "{ ";
  for (auto p = t.begin(); p != t.end(); ++p) std::cout << (*p).name << " ";
  // for (auto& el : t) std::cout << el.name << " ";
  std::cout << " }" << '\n';
}
