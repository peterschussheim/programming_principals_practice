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
  std::string name;                 // customer name
  std::string address;              // customer address
  std::string date;                 // order date (MM/DD/YYY)
  std::vector<Purchase> purchases;  // items in this order

public:
  Order(std::string nn, std::string addr, std::string dd)
      : name{nn}, address{addr}, date{dd}
  {
  }

  Order(std::string nn, std::string addr, std::string dd,
        std::vector<Purchase> pp)
      : name{nn}, address{addr}, date{dd}
  {
    for (auto& el : pp) purchases.push_back(el);
  }

  const std::string get_name() const { return name; }
  const std::string get_address() const { return address; }
  const std::string get_date() const { return date; }
  const std::vector<Purchase>& get_purchases() const { return purchases; }
};

#endif  // ORDER_H