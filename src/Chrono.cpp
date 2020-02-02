#include "Chrono.h"
#include "std_lib_facilities.h"
using namespace std;

namespace Chrono {

  Date::Date(int yy, Month mm, int dd) /* clang-format off */
  : y{yy}, m{mm}, d{dd} /* clang-format on */
  {
    if (!is_date(yy, mm, dd)) throw Invalid{};
  }

  const Date& default_date() {
    static Date dd{2001, Month::jan, 1};  // beginning of 21st century
    return dd;
  }

  Date::Date()                      // default constructor
      : y{default_date().year()},   // init year member
        m{default_date().month()},  // init month member
        d{default_date().day()}     // init day member
  {}

  void Date::add_month(int n) {}

  void Date::add_year(int n) {
    if (m == Month::feb && d == 29) {  // NOTE: did not check for leap year
      m = Month::mar;
      d = 1;
    }

    y += n;
  }

  bool is_date(int y, Month m, int d) {
    // assume that y is valid
    if (d <= 0) return false;  // d must be positive
    if (m < Month::jan || Month::dec < m) return false;

    int days_in_month = 31;  // most months have 31 days

    switch (m) {
      case Month::feb:       // length of February varies
        days_in_month = 28;  // assume no leap year for now
        break;
      case Month::apr:
      case Month::jun:
      case Month::sep:
      case Month::nov:
        days_in_month = 30;  // rest have 30 days
        break;
    }

    if (days_in_month < d) return false;

    return true;
  }

}

int main() {
  Chrono::Date today{1978, 6, 26};

  add_day(today, 1);  // copy today into tomorrow and increment by 1 using add_day()

  // output today and tomrrow using << defined in 9.8
  keep_window_open("~");
}