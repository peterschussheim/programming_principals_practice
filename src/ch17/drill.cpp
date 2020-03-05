#include <iostream>
#include <vector>
#include "Utils.h"

/*
  The first exercises/builds your understanding of free-
  store-allocated arrays and contrasts arrays with vectors:

  1. Allocate an array of ten int s on the free store using new .
  2. Print the values of the ten int s to cout .
  3. Deallocate the array (using delete[] ).
  4. Write a function print_array10(ostream& os, int* a) that prints out the
      values of a (assumed to have ten elements) to os.
  5. Allocate an array of ten int s on the free store; initialize it with the
  values 100, 101, 102, etc.; and print out its values.
  6. Allocate an array of 11 int s on the free store; initialize it with the
  values 100, 101, 102, etc.; and print out its values.
  7. Write a function print_array(ostream& os, int* a, int n) that prints out
  the values of a (assumed to have n elements) to os .
  8. Allocate an array of 20 ints on the free store; initialize it with the
  values 100, 101, 102, etc.; and print out its values.
  9. Did you remember to delete the arrays? (If not, do it.)

  10. Do 5, 6, and 8 using a vector instead of an array and a print_vector()
      instead of print_array()
*/

using namespace std;

constexpr int arr_ints_size = 11;

void print_array10(ostream& os, int* a)
{
  for (int i = 0; i < arr_ints_size; ++i) { os << a[i] << '\n'; }
}
void print_vector(ostream& os, vector<int>& v)
{
  for (int i = 0; i < v.size(); ++i) { std::cout << v[i] << '\n'; }
}
void print_array(ostream& os, int* a, int n)
{
  for (int i = 0; i < n; ++i) { os << a[i] << '\n'; }
}

/*
   The second part focuses on pointers and their relation to arrays.
   Using print_array() from the last drill:

   1. Allocate an int, initialize it to 7, and assign its address to a
     variable p1.
   2. Print out the value of p1 and of the int it points to.
   3. Allocate an array of seven int s; initialize it to 1, 2, 4, 8, etc.; and
   ssign its address to a variable p2 .
   4. Print out the value of p2 and of the array it points to.

   5. Declare an int* called p3 and initialize it with p2 .
   6. Assign p1 to p2 .
   7. Assign p3 to p2 .
   8. Print out the values of p1 and p2 and of what they point to.
   9. Deallocate all the memory you allocated from the free store.
*/

int main()
{
  try {
    // create a sequence (array) of 10 integers on the heap
    // int* arr_ints = new int[arr_ints_size];
    // initialize arr_ints with 100,101,102...
    // for (int i = 0; i < arr_ints_size; ++i) { arr_ints[i] = 100 + i; }
    // print_array10(std::cout, arr_ints);
    // int* arr_20 = new int[20];      // allocate memory for 20 ints
    // for (int i = 0; i < 20; ++i) {  // init wth the sequence 100,101,102, etc
    //  arr_20[i] = 100 + i;
    //}
    // print_array(std::cout, arr_20, 20);  // print array elements
    // delete[] arr_20;                     // free allocated memory
    // std::cout <<
    // "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    // declare a vector of pointers to integers of size 10
    // vector<int> v_10(10);
    // std::cout << "v_10 size: " << v_10.size() << '\n';
    // for (int i = 0; i < v_10.size(); ++i) {
    //  // initialize with 100, 101, 102
    //  v_10[i] = 100 + i;
    //}
    // print_vector(std::cout, v_10);
    /*vector<int> v_11(11);
    for (int i = 0; i < v_11.size(); ++i) { v_11[i] = 100 + i; }
    print_vector(cout, v_11);*/
    /*vector<int> v_20(20);
    for (int i = 0; i < v_20.size(); ++i) { v_20[i] = 100 + i; }
    print_vector(cout, v_20);*/
    // part 2, #1,2
    int n = 7;     // init an int to 7
    int* p1 = &n;  // assign n's address to p1
    /*cout << "//-------------------------------------------------\n";
    cout << "part 1-2: \n";
    cout << "int n = 7:  " << n << '\n';
    cout << "p1:  " << &n << '\n';*/

    // allocate an array of 7 ints and assign
    // its address to p2
    int* p2 = new int[7];
    int x = 1;
    for (int i = 0; i < 7; ++i) {
      // set appropriate val in p2
      // On the first iteration, x = 1
      p2[i] = x;
      // mutate x
      x *= 2;
    }

    /*cout << "//-------------------------------------------------\n";
    cout << "part 4: \n";
    cout << "p2: " << p2 << '\n';
    cout << "//-------------------------------------------------\n";
    print_array(std::cout, p2, 7);*/

    // cout << "part 5: \n";
    int* p3 = p2;

    // cout << "part 6: \n";
    p1 = p2;
    p3 = p2;

    cout << "//-------------------------------------------------\n";
    cout << "part 8: \n";
    cout << "p1 points to: " << p1 << '\n';
    cout << "p1 values: \n";
    print_array(std::cout, p1, 7);

    cout << '\n';
    cout << "p2 points to: " << p2 << '\n';
    cout << "p2 values: \n";
    print_array(std::cout, p2, 7);

    cout << "deallocating memory from arrays\n";
    // delete p1;
    delete[] p2;
    p3 = nullptr;
    cout << "deallocating completed successfuly\n";

    keep_window_open("~");
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    std::cerr << "unhandled exception\n";
    keep_window_open("~");
  }
}