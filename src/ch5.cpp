#include <iostream>

using namespace std;

void temp_stats();

void temp_stats() {
  constexpr double record_high_temp = -128.6;  // lowest temp recorded in Vostok Station
  constexpr double record_low_temp = 134.1;    // hottest temp recorded in Furnace Creek, CA
  double sum = 0;
  double high_temp = record_high_temp;
  double low_temp = record_low_temp;
  int num_of_temps = 0;

  cout << "Enter a few temperatures, separated by a space\n";

  for (double temp; cin >> temp;) {
    ++num_of_temps;
    sum += temp;
    if (temp > high_temp) high_temp = temp;
    if (temp < low_temp) low_temp = temp;
  }

  cout << "High temperature: " << high_temp << '\n';
  cout << "Low temperature: " << low_temp << '\n';
  cout << "Average temperature: " << sum / num_of_temps << '\n';
}