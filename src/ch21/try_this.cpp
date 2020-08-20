// Define a vector<Record>, initialize it with four records of your choice, and
// compute their total price using the functions above.

#include <vector>
#include <iostream>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>

std::map<std::string, double> dow_price = {
    // (symbol,price)
    {"MMM", 162.87},
    {"AAPL", 469.28},
    {"HD", 280.39},
    {"MSFT", 211.29},
    {"GS", 201.81}};

std::map<std::string, double> dow_weight = {
    // (symbol, weight)
    {"MMM", 4.06},
    {"AAPL", 11.46},
    {"HD", 7.01},
    {"MSFT", 5.19},
    {"GS", 5.03}};

std::map<std::string, std::string> dow_name = {
    // (symbol, name)
    {"MMM", "3M Co."},
    {"AAPL", "Apple Computer Inc."},
    {"HD", "Home Depot"},
    {"MSFT", "Microsoft Corporation"},
    {"GS", "Goldman Sachs Group, Inc."}};

//------------------------------------------------------------------------------

std::unordered_map<std::string, double> dow_price_un = {
    // (symbol,price)
    {"MMM", 162.87},
    {"AAPL", 469.28},
    {"HD", 280.39},
    {"MSFT", 211.29},
    {"GS", 201.81}};

std::unordered_map<std::string, double> dow_weight_un = {
    // (symbol, weight)
    {"MMM", 4.06},
    {"AAPL", 11.46},
    {"HD", 7.01},
    {"MSFT", 5.19},
    {"GS", 5.03}};

std::unordered_map<std::string, std::string> dow_name_un = {
    // (symbol, name)
    {"MMM", "3M Co."},
    {"AAPL", "Apple Computer Inc."},
    {"HD", "Home Depot"},
    {"MSFT", "Microsoft Corporation"},
    {"GS", "Goldman Sachs Group, Inc."}};

//------------------------------------------------------------------------------

struct Record {
  double unit_price;
  int units;  // number of units sold
};

// Tried to create a "price" function object which calculates a total price
// of records but wasn't sure how to do it properly.
// class Price {
//  Record r;
//  double v;
//
// public:
//  // Price() : v{0.0}, r{} {}
//  Price(double vv, Record& rr) : v{vv}, r{rr} {}
//  double operator()(double vv, Record& rr) const
//  {
//    return vv + rr.units * rr.unit_price;
//  }
//};

template<typename In, typename T, typename BinOp>
// requires Input_iterator<T>() && Number<T>()
//          && BinaryOperator<BinOp, Value_type<in>, T>()
T my_accumulate(In first, In last, T init, BinOp op);

double price(double v, const Record& r);
void usage(const std::vector<Record>& vr);
void dictionary();
void bad_dictionary(int sz);
void dictionary_set();

//------------------------------------------------------------------------------

double weighted_value(const std::pair<std::string, double>& a,
                      const std::pair<std::string, double>& b)
{
  // extract values and multiply
  return a.second * b.second;
}

//------------------------------------------------------------------------------

template<typename T, typename Q> void print_stocks(const T& prices, Q& names)
{
  for (const auto& p : prices) {
    const std::string& symbol = p.first;
    std::cout << symbol << '\t' << p.second << '\t' << names[symbol] << '\n';
  }
}

//------------------------------------------------------------------------------

int main()
{
  try {
    std::vector<Record> vr{{10.73, 3}, {66.36, 15}, {0.99, 1255}, {99.75, 771}};
    usage(vr);

    double dji_index = std::inner_product(
        dow_price.begin(), dow_price.end(),  // all companies
        dow_weight.begin(),                  // their weights
        0.0,                                 // initial value
        std::plus<double>(),                 // add
        weighted_value);  // extract vals, weights and multiply

    std::cout << "Dow Jones index: " << dji_index << '\n';
    std::cout << "\n";
    std::cout << "Selected companies from Dow index:\n";
    print_stocks(dow_price, dow_name);

    std::cout << "\n";
    std::cout << "Selected companies from Dow index (unordered):\n";
    print_stocks(dow_price_un, dow_name_un);

    std::cout << "\n";
    // std::cout << "Quick 'n dirty dictionary:\n";
    // bad_dictionary(19999);
    // dictionary();
    std::cout << "\n";

    std::cout << "\n";
    std::cout << "Dictionary using std::set :\n";
    dictionary_set();
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

  double total_1 = std::accumulate(
      vr.begin(), vr.end(), 0.0,
      [&](double v, const Record& r) { return v + r.unit_price * r.units; });
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

//------------------------------------------------------------------------------

void dictionary()
{
  using namespace std;

  string from, to;
  cout << "Enter the source filename and target(output) filename, seperated by "
          "space\n";
  cin >> from >> to;  // get source and target file names

  ifstream is{from};  // open input stream
  ofstream os{to};    // open output stream

  istream_iterator<string> ii{is};        // make input iterator for stream
  istream_iterator<string> eos;           // input sentinel
  ostream_iterator<string> oo{os, "\n"};  // make output iterator for stream

  vector<string> b{ii, eos};     // b is initialized from input
  sort(b.begin(), b.end());      // sort buffer
  copy(b.begin(), b.end(), oo);  // copy buffer to output

  // for (auto& word : b) cout << word << '\n';
}

void dictionary_set()
{
  using namespace std;

  string from, to;
  cout << "Enter the source filename and target(output) filename, seperated by "
          "space\n";
  cin >> from >> to;  // get source and target file names

  ifstream is{from};  // open input stream
  ofstream os{to};    // open output stream

  set<string> b{istream_iterator<string>{is}, istream_iterator<string>{}};
  copy(b.begin(), b.end(),
       ostream_iterator<string>{
           os, " "});  // copy buffer to output and separate with spaces
}

void bad_dictionary(
    int sz)  // does not work as expected, target file not written to
{
  using namespace std;

  string from, to;
  cout << "Enter the source filename and target(output) filename, seperated by "
          "space\n";
  cin >> from >> to;  // get source and target file names

  ifstream is{from};  // open input stream
  ofstream os{to};    // open output stream

  istream_iterator<string> ii{is};        // make input iterator for stream
  istream_iterator<string> eos;           // input sentinel
  ostream_iterator<string> oo{os, "\n"};  // make output iterator for stream

  vector<string> b(sz);      // make a guess on the size, BAD IDEA!!
  sort(b.begin(), b.end());  // sort buffer
  // copy(ii, eos, b.begin());  // copy buffer to output

  // for (auto& word : b) cout << word << '\n';
}