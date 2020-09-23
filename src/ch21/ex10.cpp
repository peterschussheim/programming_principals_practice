// - [x] Compute the total value of the orders in the two files from the previ-
// ous exercise. The value of an individual Purchase is (of course) its
// unit_price*count

// NOTE: since this is a continuation from the ex9, most of the definitions
// and usage in main() are copied.

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
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

template<class InputIt> double total_order(InputIt container);

//------------------------------------------------------------------------------

int main()
{
  try {
    std::string orders_1{"orders_1.txt"};
    std::ifstream is{orders_1};
    std::vector<Order> vo;
    Order ord;

    while (is >> ord) vo.push_back(ord);  // add order to container

    std::string orders_1_out{"orders_1_out.txt"};
    std::ofstream ofs{orders_1_out};  // create stream to write sorted orders to
    for (auto& o : vo) { ofs << o; }

    std::list<Order> lo;  // list containing some of the same from orders_1
    std::string orders_2{"orders_2.txt"};
    std::ifstream is_2{orders_2};

    while (is_2 >> ord) { lo.push_back(ord); }

    std::string orders_2_out{"orders_2_out.txt"};  // output filename
    std::ofstream ofs_2{orders_2_out};             // output stream
    for (auto& o : lo) { ofs_2 << o; }

    // compute total value for orders_1 and orders_2
    double vo_total = total_order(vo);
    double lo_total = total_order(lo);
    std::cout << "Total cost of orders in file \"orders_1.txt\": " << vo_total
              << '\n';
    std::cout << "Total cost of orders in file \"orders_2.txt\": " << lo_total
              << '\n';
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

// Calculate total cost of a container of Orders
template<class InputIt> double total_order(InputIt container)
{
  // We should refactor this function to remove the nested loop.
  // Ideas include adding a member to Purchase type which calculates the total
  // cost of each Purchase.  Then we could change the nested loop to be an
  // accumulation of each order's total value.
  double total = 0.0;
  for (auto& o : container) {
    for (auto& p : o.purchases()) { total += p.unit_price() * p.count(); }
  }
  return total;
}

//------------------------------------------------------------------------------
