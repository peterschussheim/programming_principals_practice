#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <utility>
#include "Purchase.h"

// Define an Order class with (customer) name, address, data, and
// vector<Purchase> members.
// NOTE: As the question asks for a "data" member but doesn't indicate what
// kind of data, I am using a string to hold a simple order date.

class Order {
private:
  std::string n;                // customer name
  std::string add;              // customer address
  std::string d;                // order date (MM/DD/YYY)
  std::vector<Purchase> purch;  // items in this order

public:
  Order() = default;
  Order(std::string nn, std::string addr, std::string dd,
        std::vector<Purchase> pp)
      : n{nn}, add{addr}, d{dd}
  {
    for (auto& p : pp) purch.push_back(p);
  }

  const std::string name() const { return n; }
  const std::string address() const { return add; }
  const std::string date() const { return d; }
  const std::vector<Purchase>& purchases() const { return purch; }
};

#endif  // ORDER_H