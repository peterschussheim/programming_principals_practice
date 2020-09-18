#include <iostream>

namespace Chrono {
  enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

  class Date {
  public:
    class Invalid {};             // to throw as exception
    Date(int y, Month m, int d);  // check for valid Date and init
    Date();                       // default copy operations are fine

    // accessors
    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }

    // modifying operations
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

  private:
    int y;
    Month m;
    int d;
  };

  bool is_date(int y, Month m, int d);  // true if date is valid
  bool operator==(const Date& a, const Date& b);
  bool operator!=(const Date& a, const Date& d);
  std::ostream& operator<<(std::ostream& os, const Date& d);
  std::istream& operator>>(std::istream& is, Date& dd);

}