/*
  Get the Jack-and-Jill example from §20.1.2 to work. Use input from a
  couple of small files to test it.
*/

#include "std_lib_facilities.h"
#include <vector>

//------------------------------------------------------------------------------

double* high(double* first, double* last)
// return a pointer to the element in [first,last) that has the highest value
{
  double h = -1;
  double* high;
  for (double* p = first; p != last; ++p)
    if (h < *p) high = p;
  return high;
}

//------------------------------------------------------------------------------

// jack puts doubles into an array and returns the number of elements in *count
double* get_from_jack(int* count)
{
  string ifname = "ch_20_ex2.txt";
  ifstream ifs(ifname.c_str());  // get a handle to in ifstream
  if (!ifs) error("cannot open input file ", ifname);

  vector<double> v;  // read into a vector rather than a single double at a time
  double d;
  while (ifs >> d) v.push_back(d);
  *count = v.size();  // assign v.size() to count
  double* arr = new double[*count];

  for (int i = 0; i < v.size(); ++i) { arr[i] = v[i]; }

  return arr;

  /*const int n = 10;
  double* arr = new double[n];

  if (arr) {
    *count = n;

    for (int i = 0; i < n; ++i) arr[i] = i;
  }

  return arr;*/
}

//------------------------------------------------------------------------------

vector<double>* get_from_jill()  // jill fills vector and returns a pointer
{
  string ifname = "ch_20_ex2_1.txt";
  ifstream ifs(ifname.c_str());
  if (!ifs) error("cannot open input file ", ifname);

  vector<double>* v = new vector<double>;

  double d;
  while (ifs >> d) (*v).push_back(d);

  return v;
}

//------------------------------------------------------------------------------

int main()
{
  try {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();
    vector<double>& v = *jill_data;

    double* middle = &v[0] + v.size() / 2;
    double* high1 = high(&v[0], middle);             // max of first half
    double* high2 = high(middle, &v[0] + v.size());  // max of second half

    cout << "max of first half: " << *high1
         << "; max of second half: " << *high2;

    delete[] jack_data;
    delete jill_data;
    keep_window_open("");
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    return 2;
  }
}

//------------------------------------------------------------------------------
