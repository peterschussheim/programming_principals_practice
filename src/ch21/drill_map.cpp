// 1. Define a map<string,int> called msi.
// 2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21.
// 3. Output the (name,value) pairs to cout in some format of your choice.
// 4. Erase the (name,value) pairs from msi.
// 5. Write a function that reads value pairs from cin and places them in msi.
// 6. Read ten pairs from input and enter them into msi.
// 7. Write the elements of msi to cout.
// 8. Output the sum of the (integer) values in msi.
// 9. Define a map<int,string> called mis.
// 10. Enter the values from msi into mis ; that is, if msi has an element
//    (" lecture",21 ), mis should have an element ( 21,"lecture" ).
// 11. Output the elements of mis to cout.

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <utility>

template<typename T, typename Q> struct Key_val_pair {
  T key;
  Q val;

  Key_val_pair() : key{}, val{} {}
  Key_val_pair(T k, Q v) : key{k}, val{v} {}
};

// template<typename T, typename Q>
// std::istream& operator>>(std::istream& is, Key_val_pair<T, Q>& kv)
//{
//  // file format: T Q (separated by whitespace)
//  T key{};
//  Q val{};
//  is >> key >> val;
//  if (!is) return is;
//
//  kv = {key, val};
//  return is;
//}

int main()
{
  try {
    std::map<std::string, int> msi;
    std::string file_name{"classes.txt"};
    std::ifstream is{file_name};
    // for (Key_val_pair<std::string, int> pair; is >> pair;) {
    //  // auto [p, success] = msi.insert({pair.key, pair.val});
    //  std::cout << pair.key << ", " << pair.val << '\n';
    //}
    std::string key{};
    int val = 0;

    while (is >> key >> val) msi[key] = val;
    for (auto& p : msi) { std::cout << p.first << ", " << p.second << '\n'; }
    return 0;
  }
  catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cerr << "exception\n";
    return 2;
  }
}