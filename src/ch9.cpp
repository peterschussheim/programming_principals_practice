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
    // 9.4.2
    // 9.4.3
    // 9.7.1
    // 9.7.4
*/

#include "std_lib_facilities.h"

struct Date {
  int y;
  int m;
  int d;
};

void init_day(Date& dd, int y, int m, int d) {
  // check that (y,m,d) is valid date
  // if true, use it to intialize dd
  if (d < 1 || d > 31) error("init_day: Invalid day");
  if (m < 1 || m > 12) error("init_day: Invalid month");

  dd.y = y;  // year (not checked yet)
  dd.m = m;  // month in year
  dd.d = d;  // day of month
}

void add_day(Date& dd, int n) {  // add or subtract days from a Date
  // increase dd by n days
  dd.d += n;

  if (dd.d > 31) {  // day overflow
    ++dd.m;
    dd.d -= 31;
  }
  if (dd.d < 1) {  // day underflow
    --dd.m;
    dd.d += 31;
  }
  if (dd.m > 12) {  // month overflow
    ++dd.y;
    dd.m -= 12;
  }
  if (dd.m < 1) {  // month underflow
    --dd.y;
    dd.m += 12;
  }
}

ostream& operator<<(ostream& os, const Date& d) {
  return os << '(' << d.m << '/' << d.d << '/' << d.y << ')';
}

int main() {
  try {
    Date today;
    init_day(today, 1978, 6, 26);

    Date tomorrow{today};  // copy today into tomorrow
    add_day(tomorrow, 1);  // increment by 1 using add_day()

    // output today and tomorrow using << defined in 9.8
    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    Date test1;
    init_day(test1, 2004, 13, -5);
    cout << "test1: " << test1 << '\n';  // fails due to invalid month and day args

    Date test2;
    init_day(test2, 2004, 0, 5);  // fails due to invalid month and day args
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