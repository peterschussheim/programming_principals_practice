#include "std_lib_facilities.h"

int main() {
  // output birthyear in decimal, hex, and octal
  // label each value and align in columns
  // using tab character
  int birth_year = 1985; /*
   cout << birth_year << "\t(decimal)\n"
        << hex << birth_year << "\t(hexadecimal)\n"
        << oct << birth_year << "\t(octal)\n";*/

  cout << '\n';
  // header
  cout << '|' << setw(8) << "Last Name"
       << "\t|" << setw(8) << "First Name"
       << "\t|" << setw(8) << "Telephone"
       << "\t|" << setw(8) << "\tEmail"
       << "\t|\n";

  cout << '|' << setw(8) << "Schussheim"
       << "\t|"
       << "Peter"
       << "\t|" << setw(8) << "917-595-0033"
       << "\t|" << setw(8) << "peter@schussheim.com"
       << "|\n";

  cout << '|' << setw(8) << "Pyle"
       << "\t|"
       << "Gomer"
       << "\t|" << setw(8) << "555-555-5555"
       << "\t|" << setw(8) << "gpyle@usmc.mil"
       << "|\n";

  cout << '|' << setw(8) << "Carter"
       << "\t|"
       << "Sergent"
       << "\t|" << setw(8) << "555-555-5555"
       << "\t|" << setw(8) << "sgt_carter@usmc.mil"
       << "|\n";
  keep_window_open("~");
  return 0;
}