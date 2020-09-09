#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>

// Purchase is a class with a (product) name, unit_price, and count members.

class Purchase {
private:
  std::string n;  // product name
  double unit_p;  // price per unit
  int c;          // quantity of product in this purchase
public:
  Purchase(std::string nn, double unit_p, int cc = 1)
      : n{nn}, unit_p{unit_p}, c{cc}
  {
  }

  const std::string name() const { return n; }
  const double unit_price() const { return unit_p; }
  const int count() const { return c; }
};

#endif  // PURCHASE_H