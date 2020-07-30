/*
  Look at the palindrome examples (§18.7); redo the Jack-and-Jill example
  from §20.1.2 using that variety of techniques.
*/

#include "std_lib_facilities.h"

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
// return a pointer to the element in vector with highest val
double* high_vec(vector<double>& v) { double h = -1; }

//------------------------------------------------------------------------------
// return a pointer to highest val element in array of doubles with n elements
double* high_arr(double arr[], int n)
{
  double h = -1;
  int first = 0;
  int last = n - 1;
  double* highest;

  while (first < last) {
    if (h < arr[first]) {
      highest = arr[first];
      h =
    }
  }

  return highest;
}

//------------------------------------------------------------------------------

double* high_pointer(double* first, double* last)
// return a pointer to the element in [first,last) that has the highest value
{
  double h = -1;
  double* high;
  for (double* p = first; p != last; ++p)
    if (h < *p) {
      high = p;
      h = *p;
    }
  return high;
}

int main()
{
  try {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    // use vectors: turn jack_data into vector
    vector<double> jack_vec;
    for (int i = 0; i < jack_count; ++i) jack_vec.push_back(jack_data[i]);
    double* jack_high_vec = high_vec(jack_vec);
    double* jill_high_vec = high_vec(*jill_data);
    cout << "Vector: Jill's max: " << *jill_high_vec
         << "; Jack's max: " << *jack_high_vec << "\n";

    // use arrays: turn jill_data into array
    double* jill_arr = new double[(*jill_data).size()];
    for (int i = 0; i < (*jill_data).size(); ++i) jill_arr[i] = (*jill_data)[i];
    double* jack_high_arr = high_arr(jack_data, jack_count);
    double* jill_high_arr = high_arr(jill_arr, (*jill_data).size());
    cout << "Array: Jill's max: " << *jill_high_arr
         << "; Jack's max: " << *jack_high_arr << "\n";
    delete[] jill_arr;

    // use pointers
    double* jack_high_ptr = high_pointer(jack_data, jack_data + jack_count);
    vector<double>& v = *jill_data;
    double* jill_high_ptr = high_pointer(&v[0], &v[0] + v.size());

    cout << "Pointer: Jill's max: " << *jill_high_ptr
         << "; Jack's max: " << *jack_high_ptr << "\n";

    delete[] jack_data;
    delete jill_data;
  }
  catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
  }
  catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
  }
  catch (...) {
    cerr << "exception\n";
  }
}