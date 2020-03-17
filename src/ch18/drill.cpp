#include <iostream>
#include "Utils.h"

using namespace std;

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const int a[], int n)  // why do we have to pass arrays as const?
{
  int la[10];
  cout << "copying elements from int a[] to int la[]\n";

  /*
    3 different ways we can copy the elements in an array to another.
  */
  for (int i = 0; i < 10; ++i) la[i] = a[i];  // copy 100 ints
  // memcpy(la, a, n * sizeof(int)); // copy n * sizeof(int) bytes
  // copy(a, a + 10, la);  // copy 100 ints

  for (int i = 0; i < n; ++i) { cout << "la[" << i << "]: " << la[i] << '\n'; }

  int* p = new int[n];
  cout << "\ncopying elements from int a[] to int* p\n";
  for (int i = 0; i < n; ++i) { p[i] = a[i]; }
  for (int i = 0; i < n; ++i) { cout << "p[" << i << "]: " << p[i] << '\n'; }
  cout << "\ndeallocating int* p on the free store\n";
  delete[] p;
}

/*
  calculate the nth factorial.
  usage:
    int fac_10 = factorial(10);  // 362880
*/
int factorial(int n)
{
  if (n == 0 || n == 1) return 1;
  return n * factorial(n - 1);
}

int main()
{
  try {
    f(&ga[0], 10);  // explictly call f() with the pointer to the first el of ga
    // f(ga, 10); // less explicit but works. this is array name pointer decay

    int aa[10];
    for (int i = 0; i < 10; ++i) { aa[i] = factorial(i); }
    f(aa, 10);
    keep_window_open();
    return 0;
  }
  catch (const std::exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}