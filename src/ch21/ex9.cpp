// Define an Order class with (customer) name, address, data, and
// vector<Purchase> members. Purchase is a class with a (product) name,
// unit_price , and count members. Define a mechanism for reading and
// writing Order s to and from a file. Define a mechanism for printing Or-
// der s. Create a file of at least ten Order s, read it into a vector<Order>,
// sort it by name (of customer), and write it back out to a file. Create
// another file of at least ten Order s of which about a third are the same as
// in the first file, read it into a list<Order> , sort it by address (of
// customer), and write it back out to a file. Merge the two files into a third
// using std::merge().

#include <iostream>

int main()
{
  try {
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
