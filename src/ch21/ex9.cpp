// - [x] Define an Order class with (customer) name, address, data, and
// vector<Purchase> members.
// - [ ] Purchase is a class with a (product) name, unit_price, and count
//  members.
// - [ ] Define a mechanism for reading and writing Orders to and from a file.
// - [x] Define a mechanism for printing Orders.
// - [ ] Create a file of at least ten Orders, read it into a vector<Order>,
// sort it by name (of customer), and write it back out to a file.
// - [ ] Create another file of at least ten Order s of which about a third are
// the same as in the first file, read it into a list<Order> , sort it by
// address (of customer), and write it back out to a file.
// - [ ] Merge the two files into a third using std::merge().

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Order.h"
#include "Purchase.h"

//------------------------------------------------------------------------------

std::istream& operator>>(std::istream& is, Order& order);
std::ostream& operator<<(std::ostream& os, const Order& order);

//------------------------------------------------------------------------------

std::istream& operator>>(std::istream& is, Purchase& p);
std::ostream& operator<<(std::ostream& os, const Purchase& p);

//------------------------------------------------------------------------------

template<class InputIt> void print_cont(InputIt start, InputIt end, int width);

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

int main()
{
  try {
    std::string orders_1{"orders_1.txt"};
    std::ifstream is{orders_1};
    std::vector<Order> vo;
    Order ord;

    while (is >> ord) { vo.push_back(ord); }
    for (auto& o : vo) std::cout << o << ",\n";
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
// Wilhelm Keese // order.name
// 54009 Del Mar Avenue, Oakland, California, 94616 // order.address
// 08/27/2016  // order.date
// Swiss Chard - Red|3.99|1  // purchase
// A&W Root Beer 2 Litre|1.99|2
// Veal - Provimi Inside|8.01|2
// #  // end of order
std::istream& operator>>(std::istream& is, Order& order)
{
  std::string name;
  std::string address;
  std::string date;

  std::getline(is, name);
  std::getline(is, address);
  std::getline(is, date);

  std::vector<Purchase> vp;
  std::string line;

  while (std::getline(is, line) && line != "#") {
    Purchase p;
    std::istringstream iss{line};  // create stringstream for line of purchases
    iss >> p;                      // read into a Purchase
    vp.push_back(p);
  }

  order = Order{name, address, date, vp};

  return is;
}

//------------------------------------------------------------------------------
// A&W Root Beer 2 Litre|1.99|2
// Veal - Provimi Inside|8.01|2
// #  // end of order

std::istream& operator>>(std::istream& is, Purchase& p)
{
  // read line and construct ONE purchase from input
  std::string name;
  double unit_price;
  int quantity;

  std::getline(is, name, '|');
  if (!is || name.size() == 0) return is;

  // name.pop_back();
  char cc;  // used as a dummy placeholder for "|"
  is >> unit_price >> cc >> quantity;
  if (!is) return is;

  if (cc != '|') {
    is.clear(std::ios_base::failbit);
    return is;
  }
  p = Purchase{name, unit_price, quantity};
  return is;
}

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Order& order)
{
  auto& p = order.purchases();
  os << "{ Name: " << order.name() << ",\n"
     << "  Address: " << order.address() << ",\n"
     << "  Date: " << order.date() << ",\n"
     << "  Purchases: \n";
  print_cont(p.begin(), p.end(), 16);
  std::cout << "}";
  return os;
}

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Purchase& p)
{
  return os << "{ " << p.name() << ", " << p.unit_price() << ", " << p.count()
            << " }";
}

//------------------------------------------------------------------------------

template<class InputIt> void print_cont(InputIt start, InputIt end, int width)
{
  for (auto& p = start; start != end; ++p) {
    std::cout << std::setw(width) << *p << ",\n";
  }
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
