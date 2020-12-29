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

// This was a very fun, very challenging exercise which reminded me of my
// childhood using calculators in school to write vulgarities.  The solution
// implemented below could be expanded, if for instance, a requirement was to
// use a different set of substitutions or to use uppercase words as input and
// output.
//
// std::map was used because I thought this problem was well-suited to key-value
// pairs, however, another program could easily be written using std::vector or
// std:string.

//------------------------------------------------------------------------------

// Hex characters: 0123456789ABCDEF
using Sub_map = std::map<std::string, std::string>;
constexpr int min_word_size = 3;

//------------------------------------------------------------------------------

// substitution map
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

std::string get_hex_substitution(char sub_string, Sub_map& table);
std::string process_word(std::string& w, Sub_map& s);
void create_hex_dict(const std::string& ifile, const std::string& ofile,
                     Sub_map& s);

//------------------------------------------------------------------------------

int main()
{
  create_hex_dict("usa_dict.txt", "hex_speak.txt", sub);

  return 0;
}

//------------------------------------------------------------------------------

// Returns the hex substitution for a given sub_string.
// Ex: auto replacement = get_hex_substitution("t", sub); // "7"
// Ex: auto replacement = get_hex_substitution("f", sub); // "f"
std::string get_hex_substitution(char sub_string, Sub_map& table)
{
  Sub_map::iterator it = table.find(std::string{sub_string});
  if (it != table.end()) { return (*it).second; }
  else {
    return "";  // if we cannot find a replacement, return an empty string
  }
}

//------------------------------------------------------------------------------

// Process an individual word to try and substitute with hexadecimal characters.
// returns the "hex string" or an empty string.
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

// read dictionary into memory and build words from dictionary using
// only hex characters and substitutions above. write valid hex words to file.
void create_hex_dict(const std::string& ifile, const std::string& ofile,
                     Sub_map& s)
{
  std::ifstream inf(ifile);
  std::ofstream outf(ofile);
  if (!inf || !outf) std::cerr << "bad file name\n";

  while (inf)  // while the list has words to read
  {
    std::string curr, hex;
    inf >> curr;                         // read each line
    if (curr.size() >= min_word_size) {  // ensure word meets min size
      hex = process_word(curr, sub);
    }
    // if we couldn't created a hex version of the word, hex will be empty
    // so we should ignore and only write to the file valid hex words.
    if (hex.size() > 0) { outf << hex << '\n'; }
  }
}

//------------------------------------------------------------------------------
