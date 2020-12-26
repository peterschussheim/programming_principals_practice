// Make a list of words that can be spelled with hexadecimal notation.
// Read 0 as o, read 1 as l, read 2 as to, etc.; for example, Foo1 and Beef.
// Kindly eliminate vulgarities from the list before submitting it for grading.

//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

//------------------------------------------------------------------------------

// substitution map
// Hex characters: 0123456789ABCDEF
using Sub_map = std::map<std::string, std::string>;

constexpr int min_word_size = 3;

Sub_map sub{
    // clang-format off
  {"o", "0"},
  {"l", "1"},
  {"to", "2"},
  {"for", "4"},
  {"s", "5"},
  {"g", "6"},
  {"t", "7"},
  {"ate", "8"},
  {"g", "9"}
    // clang-format on
};

//------------------------------------------------------------------------------

// Returns the hex substitution for a given sub_string.
// Ex: auto replacement = get_hex_substitution("ate", sub); // "ate"
std::string get_hex_substitution(std::string sub_string, Sub_map table)
{
  // TODO: Need to use a less stringent algorithm to handle partial matches
  auto search = table.find(sub_string);
  if (search != table.end()) { return search->second; }
  else {
    return "";  // if we cannot find a replacement in table, return empty string
  }
}

//------------------------------------------------------------------------------

// create ofstream "hex_speak.txt"
// read dictionary into memory
// attempt to build words from dictionary using only hex characters and
// substitutions above.
// write valid hex words to file

void create_hex_dict(std::string infile, std::string outfile, Sub_map& s)
{
  std::ifstream inf(infile);
  std::ofstream outf(outfile);
  if (!inf || !outf) std::cerr << "bad file name\n";

  while (inf)  // while the list has words to read
  {
    std::string curr, hex;
    inf >> curr;                         // read each line
    if (curr.size() >= min_word_size) {  // ensure word meets min size
      for (auto& search : sub) {
        // look for the first occurence of a potential replaceable string
        std::string::size_type idx = curr.find_first_of(search.first);
        if (idx != std::string::npos) {  // if we found an occurence
          // set hex to the string with the replacement
          hex = search.second + std::string{curr, idx};
          // hex = search.second + std::string{curr, search.first.size() - idx};
        }
      }
    }
    // TODO: Not done, need to add a condition when writing out hex words
    outf << hex << '\n';
  }
}

//------------------------------------------------------------------------------

int main()
{
  create_hex_dict("usa_dict.txt", "hex_speak.txt", sub);

  /* std::string ex_eng = "late";
   std::string subs = get_hex_substitution(ex_eng, sub);*/

  return 0;
}