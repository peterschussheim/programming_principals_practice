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
    // 9.4.3 DONE
    // 9.7.1
    // 9.7.4
*/

#include "std_lib_facilities.h"

class Date {
public:
  class Invalid {};           // exception handling
  Date(int y, int m, int d);  // check for valid dates and initialize

  // non-modifying operations
  int month() const { return m; }
  int day() const { return d; }
  int year() const { return y; }

  // modifying operations
  void add_day(int n);  // increase Date by n days

private:
  int y, m, d;
  bool is_valid();  // return true if date is valid
};

Date::Date(int yy, int mm, int dd)  // constructor
    : y{yy}, m{mm}, d{dd}           // initialize members
{
  if (!is_valid()) throw Invalid{};  // valid initialized values
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

bool Date::is_valid() {  // validates day and month. Year validation not implemented
  if (d < 1 || d > 31) return false;
  if (m < 1 || m > 12) return false;

  return true;
}

ostream& operator<<(ostream& os, const Date& d) {
  return os << '(' << d.month() << '/' << d.day() << '/' << d.year() << ')';
}

int main() {
  try {
    Date today{2000, 12, 31};
    Date tomorrow{today};  // construct new Date object based on today
    tomorrow.add_day(1);   // increment by 1
    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    Date test1{2004, 13, -5};
    cout << "test1: " << test1 << '\n';  // fails due to invalid month and day args

    // Date test2{2004, 0, 5};
    // cout << "test2: " << test2 << '\n';

    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open("~");
    return 1;
  } catch (Date::Invalid) {
    error("invalid date");
    keep_window_open("~");
    return 1;
  } catch (...) {
    cerr << "Unknown exception\n";
    keep_window_open("~");
    return 2;
  }
}