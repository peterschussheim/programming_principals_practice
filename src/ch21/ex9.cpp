// - [x] Define an Order class with (customer) name, address, data, and
// vector<Purchase> members.
// - [x] Purchase is a class with a (product) name, unit_price, and count
//  members.
// - [x] Define a mechanism for reading and writing Orders to and from a file.
// - [x] Define a mechanism for printing Orders.
// - [x] Create a file of at least ten Orders, read it into a vector<Order>,
// sort it by name (of customer), and write it back out to a file.
// - [x] Create another file of at least ten Orders of which about a third are
// the same as in the first file, read it into a list<Order>, sort it by
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
std::ofstream& operator<<(std::ofstream& os, const Order& order);

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

    while (is >> ord)  // read until error state or eof
    {
      vo.push_back(ord);  // add order to container
    }
    // for (auto& o : vo) std::cout << o << ",\n";

    std::sort(vo.begin(), vo.end(), [](Order& l, Order& r) {
      return l.name() < r.name();
    });  // sort by name

    std::string orders_1_out{"orders_1_out.txt"};
    std::ofstream ofs{orders_1_out};  // create stream to write sorted orders to
    for (auto& o : vo) { ofs << o; }

    std::list<Order> lo;  // list containing some of the same from orders_1
    std::string orders_2{"orders_2.txt"};
    std::ifstream is_2{orders_2};

    while (is_2 >> ord) { lo.push_back(ord); }

    lo.sort([](Order& l, Order& r) {
      return l.address() < r.address();
    });  // sort by address

    std::string orders_2_out{"orders_2_out.txt"};  // output filename
    std::ofstream ofs_2{orders_2_out};             // output stream
    for (auto& o : lo) { ofs_2 << o; }

    // std::merge requires both input sources to be sorted
    // lo is already sorted by address, so we just need to do the same
    // to vo to make the ordering identicle.
    std::sort(vo.begin(), vo.end(),
              [](Order& l, Order& r) { return l.address() < r.address(); });
    std::vector<Order> merged;  // destination
    std::merge(vo.begin(), vo.end(), lo.begin(), lo.end(),
               std::back_inserter(merged),
               [](Order& l, Order& r) { return l.address() < r.address(); });

    std::string orders_merged{"merged.txt"};
    std::ofstream ofs_merged{orders_merged};
    for (auto& o : merged) ofs_merged << o;

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

std::istream& operator>>(std::istream& is, Purchase& p)
{
  // read line and construct ONE purchase from input
  std::string name;
  double unit_price{};
  int quantity{};

  std::getline(is, name, '|');
  if (!is || name.size() == 0) return is;

  // name.pop_back();
  char cc{};  // used as a dummy placeholder for "|"
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

// Formatted output intended for printing all Order members to a terminal.
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

// Formatted output for writing Orders to a file in the SAME format as the
// source file.
std::ofstream& operator<<(std::ofstream& os, const Order& order)
{
  os << order.name() << "\n" << order.address() << "\n" << order.date() << "\n";
  for (auto& purch : order.purchases()) {
    os << purch.name() << "|" << purch.unit_price() << "|" << purch.count()
       << "\n";
  }
  os << "#\n";
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
