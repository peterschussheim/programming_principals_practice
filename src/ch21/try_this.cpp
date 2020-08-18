// Define a vector<Record>, initialize it with four records of your choice, and
// compute their total price using the functions above.

#include <vector>
#include <iostream>

struct Record {
  double unit_price;
  int units;  // number of units sold
};

class Price {
  Record r;
  double v;

public:
  // Price() : v{0.0}, r{} {}
  Price(double vv, Record& rr) : v{vv}, r{rr} {}
  double operator()(double vv, Record& rr) const
  {
    return vv + rr.units * rr.unit_price;
  }
};

template<typename In, typename T, typename BinOp>
// requires Input_iterator<T>() && Number<T>()
//          && BinaryOperator<BinOp, Value_type<in>, T>()
T my_accumulate(In first, In last, T init, BinOp op);

double price(double v, const Record& r);
void usage(const std::vector<Record>& vr);

//------------------------------------------------------------------------------

int main()
{
  try {
    std::vector<Record> vr{{10.73, 3}, {66.36, 15}, {0.99, 1255}, {99.75, 771}};
    usage(vr);
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

void usage(const std::vector<Record>& vr)
{
  double total = my_accumulate(vr.begin(), vr.end(), 0.0, price);
  std::cout << "The total is: " << total << '\n';

  double total_1 = my_accumulate(
      vr.begin(), vr.end(), 0.0,
      [](double v, Record& r) { return v + r.unit_price * r.units; });
  std::cout << "The total_1 is: " << total_1 << '\n';

  // Price p;
  // double total_2 = my_accumulate(vr.begin(), vr.end(), 0.0, p());
  // std::cout << "The total_2 is: " << total_2 << '\n';
}

//------------------------------------------------------------------------------

double price(double v, const Record& r)  // calculate price and accumulate
{
  return v + r.unit_price * r.units;
}

//------------------------------------------------------------------------------

template<typename In, typename T, typename BinOp>
T my_accumulate(In first, In last, T init, BinOp op)
{
  while (first != last) {
    init = op(init, *first);
    ++first;
  }
  return init;
}
