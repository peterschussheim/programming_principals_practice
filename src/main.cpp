#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

using namespace std;

int main() {  // NOLINT
  vector<string> words;
  words.push_back("Broccoli");
  words.push_back("Tasty");
  words.push_back("Many");

  for (string temp; cin >> temp;) {           // write into temp from cin
    for (int i = 0; i < words.size(); ++i) {  // if the current word (temp) is in our blacklist
      if (temp == words[i]) {                 // output "BLEEP" if temp is in blacklist
        cout << "BLEEP"
             << "\n";

        continue;
      } else {
        cout << "You entered: " << temp << "\n";
      }
    }
  }
  const int pos_x = 44;
  keep_window_open();
}
