#include "std_lib_facilities.h"

void print_value(double distance, string unit)
{
  cout << "You entered: " << distance << " and a unit of: " << unit << "\n";
}

int main()
{
  double dist;
  string unit;       // "cm" || "m" || "in" || "ft"
  double sum = 0.0;  // running sum of values in meters
  int count = 0;     // Tracks how many values have been entered
  double smallest = std::numeric_limits<double>::max();
  double largest = std::numeric_limits<double>::min();
  vector<double> values;

  constexpr double cm_to_meter = 0.01;
  constexpr double in_to_meter = 0.0254;
  constexpr double ft_to_meter = 0.03048;

  cout << "Enter a value including a valid unit. "
       << "EX: 12cm || 2.33 m || 9.032in || 44.03 ft\n";
  cout << "When you are finished, enter '|' to exit the program\n";

  while (cin >> dist >> unit) {
    if (unit == "cm") {
      double converted = dist * cm_to_meter;
      if (converted < smallest) { smallest = converted; }

      if (converted > largest) { largest = converted; }
      values.push_back(converted);
      sum += converted;
      ++count;
      print_value(dist, unit);
    }
    else if (unit == "m") {
      if (dist < smallest) { smallest = dist; }

      if (dist > largest) { largest = dist; }
      values.push_back(dist);
      sum += dist;
      ++count;
      print_value(dist, unit);
    }
    else if (unit == "in") {
      double converted = dist * in_to_meter;
      if (converted < smallest) { smallest = converted; }

      if (converted > largest) { largest = converted; }
      values.push_back(converted);
      sum += converted;
      ++count;
      print_value(dist, unit);
    }
    else if (unit == "ft") {
      double converted = dist * ft_to_meter;
      if (converted < smallest) { smallest = converted; }

      if (converted > largest) { largest = converted; }
      values.push_back(converted);
      sum += converted;
      ++count;
      print_value(dist, unit);
    }
    else {
      // Reject any unit not explicitly checked above
      cout << "You entered an illegal unit format: " << unit << "\n";
    }
  }

  cout << "smallest value: " << smallest << "m\n";
  cout << "largest value: " << largest << "m\n";
  cout << "number of values entered: " << count << "\n";
  cout << "sum: " << sum << "m\n";

  sort(values.begin(), values.end());
  for (double x : values) { cout << x << "\n"; }

  keep_window_open("|");
  return 0;
}