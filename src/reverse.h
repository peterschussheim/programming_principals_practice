/**
    Write two functions that reverse the order of elements in a vector<int> .
    For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function
    should produce a new vector with the reversed sequence, leaving its orig-
    inal vector unchanged.

    The other reverse function should reverse the elements of its vector without
    using any other vector s (hint: swap )
  */

#include "std_lib_facilities.h"
/**
  Accepts a vector of integers and returns a copy
  in reverse order.
  */
vector<int> reverse(vector<int> v) {
  int i = 0;
  int j = v.size();
  while (i != j) {
    // swap(v, i, j);
    ++i;
    --j;
  }
  return v;
}

/*
  Accepts a reference to a vector and the indices of
  two elements to swap.

  Swaps two elements at a time, in-place.
*/
void swap(vector<int>& v, int idx_i, int idx_j) {
  int temp = v[idx_i];
  v[idx_i] = v[idx_j];
  v[idx_j] = temp;
}

/*
  Accepts a reference to a vector<int> v and performs an
  in-place reverse using a swap function.
*/
void reverse_inplace(vector<int>& v) {
  int i = 0;
  int j = v.size() - 1;
  while (i != j) {
    swap(v, i, j);
    ++i;
    --j;
  }
}