#ifndef ORDER
#define ORDER

#include <string>
#include <vector>
#include "Purchase.h"

class Order {
private:
  std::string name;                 // customer name
  std::string address;              // customer address
  std::string date;                 // order date (MM/DD/YYY)
  std::vector<Purchase> purchases;  // items in this order

public:
};

#endif  // !ORDER