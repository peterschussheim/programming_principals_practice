/*
  Write a template class Pair that can hold a pair of values of any type.
  Use this to implement a simple symbol table like the one we used in the
  calculator (§7.8).
*/
#include <iostream>
#include <exception>
#include <vector>
#include <string>

using namespace std;

template<class T, class U> class Pair {
public:
  T key;
  U value;
  Pair(T k, U val) : key{k}, value{val} {}
};

//------------------------------------------------------------------------------

class Symbol_table {
public:
  double get_value(const string& s);       // get a value in sym_table
  void set_value(string key, double val);  // modify value of an existing key
  bool is_declared(string key);            // does this key already exist?
  double define_name(string key, double value);  // create new entry in table
  void print();                                  // print each row of table
private:
  vector<Pair<string, double>> table;
};

//------------------------------------------------------------------------------

double Symbol_table::get_value(const string& s)
{
  for (auto& element : table) {
    if (element.key == s) { return element.value; }
  }
  std::cerr << "get: undefined variable " << s;
}

//------------------------------------------------------------------------------

void Symbol_table::set_value(string key, double value)
{
  for (int i = 0; i < table.size(); ++i) {
    if (table[i].key == key) {
      table[i].value = value;
      return;
    }
  }
  std::cerr << "set: undefined variable " << key;
}

//------------------------------------------------------------------------------

bool Symbol_table::is_declared(string key)  // check if key is already defined
{
  for (auto& element : table) {
    if (element.key == key) { return true; }
  }
  return false;
}

//------------------------------------------------------------------------------
double Symbol_table::define_name(string key, double value)  // add new Pair
{
  if (is_declared(key)) std::cerr << key << " declared twice\n";
  table.push_back(Pair<string, double>{key, value});
  return value;
}

//------------------------------------------------------------------------------

void Symbol_table::print()
{
  cout << "Key\tValue\t\n";
  for (int i = 0; i < table.size(); ++i) {
    cout << table[i].key << '\t' << table[i].value << '\n';
  }
}

int main()
{
  try {
    Symbol_table s_table;
    double pi = s_table.define_name("pi", 3.1415926535);
    double my_e = s_table.define_name("e", 2.7182818284);
    s_table.print();
    cout << "\n\n";
    cout << "is 'pi' defined?\t"
         << (s_table.is_declared("pi") == 1 ? "true" : "false") << '\n';
    cout << "is 'golden' defined?\t"
         << (s_table.is_declared("golden") == 1 ? "true" : "false") << '\n';

    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "Unhandled exception\n";
    return 2;
  }
}