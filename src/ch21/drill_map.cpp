// 1. Define a map<string,int> called msi.
// 2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21.
// 3. Output the (name,value) pairs to cout in some format of your choice.
// 4. Erase the (name,value) pairs from msi.
// 5. Write a function that reads value pairs from cin and places them in msi.
// 6. Read ten pairs from input and enter them into msi.
// 7. Write the elements of msi to cout.
// 8. Output the sum of the (integer) values in msi.

// 9. Define a map<int,string> called mis.
// 10. Enter the values from msi into mis; that is, if msi has an element
//    (" lecture",21 ), mis should have an element ( 21,"lecture" ).
// 11. Output the elements of mis to cout.

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <numeric>
#include <utility>

template<typename T1, typename T2> std::pair<T1, T2> read_pair(T1& x, T2& y);
template<typename T1, typename T2> void read_pairs(std::map<T1, T2>& msi);
template<typename T1, typename T2> void print_pair(T1& x, T2& y);
template<typename T1, typename T2> void print_map(std::map<T1, T2>& msi);
template<typename T1, typename T2> int sum_vals(std::map<T1, T2>& msi);

//------------------------------------------------------------------------------

int main()
{
  try {
    std::map<std::string, int> msi;
    std::string file_name{"classes.txt"};
    std::ifstream is{file_name};

    std::string key;
    int val = 0;
    while (is >> key >> val) msi[key] = val;

    print_map(msi);
    std::cout << "Clearing msi\n";
    msi.clear();
    std::cout << "\n";
    std::cout << "\n";

    // read_pairs(msi);
    std::cout << "\n";

    // print_map(msi);
    std::cout << "\n";

    // std::cout << "Sum of integers in msi: " << sum_vals(msi) << "\n";

    // 9. Define a map<int,string> called mis.
    std::map<int, std::string> mis;

    // 10. Enter the values from msi into mis; that is, if msi has an element
    //    (" lecture",21 ), mis should have an element ( 21,"lecture" ).
    std::ifstream is_1{file_name};
    while (is_1 >> key >> val) mis[val] = key;

    // 11. Output the elements of mis to cout.
    print_map(mis);
    std::cout << "\n";

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

// Helper function to print a single { key, value } pair
template<typename T1, typename T2> void print_pair(T1& x, T2& y)
{
  // Print pair of values of T1 and T2 respectively, using surrounding
  // braces and separated with a comma.
  std::cout << "{ " << x << ", " << y << " }";
}

//------------------------------------------------------------------------------

// Print each node in std::map using { key, value }\n format
template<typename T1, typename T2> void print_map(std::map<T1, T2>& msi)
{
  for (auto& p : msi)  // get a pair in the map
  {
    print_pair(p.first, p.second);  // print to cout
    std::cout << '\n';
  }
}

//------------------------------------------------------------------------------

// Return the sum of the integer values of each pair in msi
template<typename T1, typename T2> int sum_vals(std::map<T1, T2>& msi)
{
  return std::accumulate(msi.begin(), msi.end(), 0,
                         [](const int prev, const auto& element) {
                           return prev + element.second;
                         });
}

//------------------------------------------------------------------------------

// Read line-by-line two values from cin, separated by whitespace
template<typename T1, typename T2> std::pair<T1, T2> read_pair(T1& x, T2& y)
{
  std::cin >> x >> y;
  return std::make_pair(x, y);
}

//------------------------------------------------------------------------------

// TODO: if I have time, refactor to accept a parameter to signal
// when to terminate read loop.
template<typename T1, typename T2> void read_pairs(std::map<T1, T2>& msi)
{
  std::cout << "Enter 10 key value pairs, ex: vertical 992\n";
  for (int i = 0; i != 10; ++i) {
    T1 k{};
    T2 v{};
    auto [first, second] = read_pair(k, v);
    msi[first] = second;
  }
}