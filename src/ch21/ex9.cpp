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
#include <fstream>
#include "Order.h"

int main()
{
  try {
    // create file with Orders and read into vo
    std::vector<Order> vo;
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
