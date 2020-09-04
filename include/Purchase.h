#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>

// Purchase is a class with a (product) name, unit_price, and count members.

class Purchase {
private:
  std::string name;   // product name
  double unit_price;  // price per unit
  int count;          // quantity of product in this purchase
public:
  Purchase(std::string nn, double unit_p, int cc = 1)
      : name{nn}, unit_price{unit_p}, count{cc}
  {
    // handle Purchase without name and/or unit_price
  }

  const std::string get_name() const { return name; }
  const double get_unit_price() const { return unit_price; }
  const int get_count() const { return count; }
};

#endif  // PURCHASE_H