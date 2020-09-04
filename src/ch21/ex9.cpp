// Define an Order class with (customer) name, address, data, and
// vector<Purchase> members.

// Purchase is a class with a (product) name, unit_price, and count members.

// Define a mechanism for reading and writing Orders to and from a file.
// Define a mechanism for printing Orders.

// Create a file of at least ten Orders, read it into a vector<Order>, sort it
// by name (of customer), and write it back out to a file. Create another file
// of at least ten Order s of which about a third are the same as in the first
// file, read it into a list<Order> , sort it by address (of customer), and
// write it back out to a file. Merge the two files into a third using
// std::merge().

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "Order.h"
#include "Purchase.h"

//------------------------------------------------------------------------------

std::istream& operator>>(std::istream& is, const Order& order);
std::ostream& operator<<(std::ostream& os, const Order& order);

//------------------------------------------------------------------------------

std::istream& operator>>(std::istream& is, const Purchase& p);
std::ostream& operator<<(std::ostream& os, const Purchase& p);

//------------------------------------------------------------------------------

template<class InputIt> void print_cont(InputIt start, InputIt end);

//------------------------------------------------------------------------------

int main()
{
  try {
    Purchase my_purch{"Catsup", 2.99, 3};
    Purchase my_purch_1{"Milk", 1.99};
    Purchase my_purch_2{"Beer", 1.59, 6};
    std::vector<Purchase> purchases{my_purch, my_purch_1, my_purch_2};
    for (auto& p : purchases) std::cout << p << '\n';

    Order my_order{"Peter Schussheim", "123 Main St.", "01/01/2009", my_purch};
    // std::cout << "Reading orders from local file\n";
    // create file with Orders and read into vo
    // std::string orders_1{"orders_1.txt"};
    // std::ifstream is{orders_1};
    // std::istream_iterator<std::string> ii{
    //    is};                                 // make  input iterator for
    //    stream
    // std::istream_iterator<std::string> eos;  // input sentinel
    // std::vector<Order> vo{ii, eos};          // init vo from input

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

std::ostream& operator<<(std::ostream& os, const Order& order)
{
  auto& p = order.get_purchases();
  return os << "{ Name: " << order.get_name() << ",\n"
            << "  Address: " << order.get_address() << ",\n"
            << "  Date: " << order.get_date() << ",\n"
            << "  Purchases: ";

  print_cont(p.begin(), p.end());
  std::cout << " }";
}

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Purchase& p)
{
  return os << "(" << p.get_name() << ", " << p.get_unit_price() << ", "
            << p.get_count() << ")";
}

//------------------------------------------------------------------------------

template<class InputIt> void print_cont(InputIt start, InputIt end)
{
  for (auto p = start; start != end; ++p) { std::cout << *p << '\n'; }
}
