/*
  Peter Schussheim
  01/30/20

  Get each version of Date working.

  General requirements:
    - use very simple function to check if date is valid
    - ignore leap years
    - reject month outside of [1,12] range
    - reject day of month outside of [1,31] range
    - test each version with an invalid date (ex: 2004, 13, -5)
    // 9.4.1 DONE
    // 9.4.2 DONE
    // 9.4.3
    // 9.7.1
    // 9.7.4
*/

#include "std_lib_facilities.h"

struct Date {
  int y, m, d;
  Date(int yy, int mm, int dd);  // check for valid dates and initialize
  void add_day(int n);           // increase Date by n days
};

Date::Date(int yy, int mm, int dd) {
  // check that (y,m,d) is valid date
  // if true, use it to intialize dd
  if (dd < 1 || dd > 31) error("init_day: Invalid day");
  if (mm < 1 || mm > 12) error("init_day: Invalid month");

  y = yy;  // year (not checked yet)
  m = mm;  // month in year
  d = dd;  // day of month
}

void Date::add_day(int n) {  // add or subtract days from a Date
  d += n;                    // increase d by n days

  if (d > 31) {  // day overflow
    ++m;
    d -= 31;
  }
  if (d < 1) {  // day underflow
    --m;
    d += 31;
  }
  if (m > 12) {  // month overflow
    ++y;
    m -= 12;
  }
  if (m < 1) {  // month underflow
    --y;
    m += 12;
  }
}

ostream& operator<<(ostream& os, const Date& d) {
  return os << '(' << d.m << '/' << d.d << '/' << d.y << ')';
}

int main() {
  try {
    Date today{2000, 12, 31};
    Date tomorrow{today};  // construct new Date object based on today
    tomorrow.add_day(1);   // increment by 1
    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    // Date test1{2004, 13, -5};
    // cout << "test1: " << test1 << '\n';  // fails due to invalid month and day args

    Date test2{2004, 0, 5};
    cout << "test2: " << test2 << '\n';

    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "Unknown exception\n";
    keep_window_open("~");
    return 2;
  }
}