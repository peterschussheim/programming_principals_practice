// Take the word-frequency example from §21.6.1 and modify it to output
// its lines in order of frequency (rather than in lexicographical order).
// An example line would be 3: C++ rather than C++: 3

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

typedef std::pair<std::string, int> pair;  // save us from excessive typing

//------------------------------------------------------------------------------

struct Freq_asc {  // is x.second < y.second?

  bool operator()(const pair& x, const pair& y) const
  {
    return x.second < y.second;
  }
};

//------------------------------------------------------------------------------

int main()
{
  try {
    std::map<std::string, int> words;
    for (std::string s; std::cin >> s && s != "|";) ++words[s];

    // since we cannot sort a map by value (only key), we need some additional
    // data structure to copy each pair from the map which we can then sort
    // using some custom comparator.
    std::vector<pair> out;  // init vector of pairs
    std::copy(words.begin(), words.end(),
              std::back_inserter<std::vector<pair>>(out));

    std::sort(out.begin(), out.end(), Freq_asc());
    for (const auto& p : out) {
      std::cout << p.second << ": " << p.first << '\n';
    }

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
