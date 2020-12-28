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
  {"a", "a"},
  {"b", "b"},
  {"c", "c"},
  {"d", "d"},
  {"e", "e"},
  {"f", "f"},
  {"o", "0"},
  {"l", "1"},
  //{"i", "1"},
  {"s", "5"},
  {"t", "7"},
  //{"for", "4"},
  //{"g", "6"},
  //{"ate", "8"},
  //{"g", "9"}
    // clang-format on
};

//------------------------------------------------------------------------------

std::string get_hex_substitution(char sub_string, Sub_map table);
std::string process_word(std::string& w, Sub_map& s);
void create_hex_dict(std::string infile, std::string outfile, Sub_map& s);

//------------------------------------------------------------------------------

int main()
{
  create_hex_dict("usa_dict.txt", "hex_speak.txt", sub);

  // std::string original = "forty";
  //// std::string original = "late";
  // std::string result = process_word(original, sub);
  // std::cout << original << " --> " << result << '\n';
  return 0;
}

//------------------------------------------------------------------------------

// Returns the hex substitution for a given sub_string.
// Ex: auto replacement = get_hex_substitution("t", sub); // "7"
// Ex: auto replacement = get_hex_substitution("f", sub); // "f"
std::string get_hex_substitution(char sub_string, Sub_map table)
{
  auto search = table.find(std::string{sub_string});
  if (search != table.end()) { return (*search).second; }
  else {
    return "";  // if we cannot find a replacement in table, return empty string
  }
}

//------------------------------------------------------------------------------

// Process an individual word to try and substitute with hexadecimal characters.
// returns std::string.
std::string process_word(std::string& w, Sub_map& s)
{
  std::string result;
  for (int i = 0; i < w.size(); ++i) {  // check each char
    std::string repl = get_hex_substitution(w[i], sub);
    if (repl.empty()) {
      // if repl is empty, there was no suitable char to substitute
      // and we should skip the current word completely since our requirements
      // specify only the hex alphabet can be used to construct words
      // result += repl;
      return "";
    }
    else {
      // use the current w char
      result += repl;
    }
  }

  return result;
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
      hex = process_word(curr, sub);
    }
    // TODO: Not done, need to add a condition when writing out hex words
    if (hex.size() > 0) { outf << hex << '\n'; }
  }
}

//------------------------------------------------------------------------------
