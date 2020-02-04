/*
  Peter Schussheim
  02/04/20

  Chapter 11 Drill
*/

#include "std_lib_facilities.h"

// Given a floating-point number and a string
// representing the output format (defaultfloat || fixed || scientific),
// outputs val in number_format.
void print_float(double val, string number_format) {
  cout << number_format << val << "\t\t(" << number_format << ")\n";
}

int main() {
  // print 1234567.89 three times, first using defaultfloat,
  // then fixed, then scientific forms.
  double float_val = 1234567.89;
  cout << defaultfloat << float_val << "\n";
  cout << fixed << float_val << "\n";  // fixed format is the most user-friendly
  cout << scientific << float_val << "\n";

  keep_window_open("~");
  return 1;
  // int birth_year = 1985;
  // int age = 34;

  // cout << showbase << birth_year << "\t(decimal)\n"
  //     << hex << birth_year << "\t(hexidecimal)\n"
  //     << oct << birth_year << "\t(octal)\n"
  //     << dec << age << "\t(age in decimal)\n";

  // int a, b, c, d;
  // cout << "enter 4 numbers of 4 digits each, seperated by spaces\n";
  // while (cin >> a >> b >> c >> d) {
  //  // output the values and show the corresponding base notation
  //  cout << showbase << a << oct << ' ' << b << hex << ' ' << c << dec << ' ' << d;
  //}
}