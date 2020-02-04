/*
  Peter Schussheim
  02/04/20

  Chapter 11 Drill
*/

#include "std_lib_facilities.h"

int main() {
  int birth_year = 1985;
  int age = 34;

  cout << showbase << birth_year << "\t(decimal)\n"
       << hex << birth_year << "\t(hexidecimal)\n"
       << oct << birth_year << "\t(octal)\n"
       << dec << age << "\t(age in decimal)\n";
  keep_window_open("~");
  return 1;
}