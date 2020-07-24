
// clang-format off
/*
  1. Define an array of int s with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.

  2. Define a vector<int> with those ten elements.
  
  3. Define a list<int> with those ten elements.
  
  4. Define a second array, vector, and list, each initialized as a copy of the first
  array, vector, and list, respectively.
  
  5. Increase the value of each element in the array by 2; increase the value of
  each element in the vector by 3; increase the value of each element in the
  list by 5.
  
  6. Write a simple copy() operation,
  template<typename Iter1, typename Iter2>
  // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
  Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);
  that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the
  standard library copy function. Note that if f1==e1 the sequence is empty,
  so that there is nothing to copy.
  
  7. Use your copy() to copy the array into the vector and to copy the list into
  the array.
  
  8. Use the standard library find() to see if the vector contains the value 3
  and print out its position if it does; use find() to see if the list contains the
  value 27 and print out its position if it does. The “position” of the first
  element is 0, the position of the second element is 1, etc. Note that if find()
  returns the end of the sequence, the value wasn’t found.

  Remember to test after each step.
*/
// clang-format on

#include <iostream>
#include <vector>
#include <list>

void print_array(std::ostream& os, int* a)
{
  for (int i = 0; i < 10; ++i) { os << a[i] << " "; }
  os << "\n";
}

//------------------------------------------------------------------------------

template<class T> void print(const T& c)
{
  for (auto const& el : c) { std::cout << el << " "; }
  std::cout << '\n';
}

//------------------------------------------------------------------------------

template<typename Iterator> void print_iter(Iterator first, Iterator last)
{
  for (auto p = first; p != last; ++p) { std::cout << *p << " "; }
  std::cout << '\n';
}

//------------------------------------------------------------------------------

template<class Iterator> void increase(Iterator first, Iterator last, int n)
{
  for (auto p = first; p != last; ++p) { *p += n; }
}

//------------------------------------------------------------------------------

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
}

int main()
{
  int a_ints[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> v_int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> int_list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << "a_ints[]:\t";
  print_array(std::cout, &a_ints[0]);
  std::cout << "v_int[]:\t";
  // print(v_int);
  print_iter(v_int.begin(), v_int.end());
  std::cout << "int_list[]:\t";
  // print(int_list);
  print_iter(int_list.begin(), int_list.end());

  std::cout << "\n";
  int a_ints_cpy[10]{};
  std::copy(std::begin(a_ints), std::end(a_ints), std::begin(a_ints_cpy));
  std::vector<int> v_int_cpy = v_int;
  std::list<int> int_list_cpy = int_list;
  std::cout << "a_ints_cpy[]:\t";
  print_array(std::cout, &a_ints_cpy[0]);
  std::cout << "v_int_cpy[]:\t";
  print_iter(v_int_cpy.begin(), v_int_cpy.end());
  std::cout << "int_list[]:\t";
  print_iter(int_list_cpy.begin(), int_list_cpy.end());

  std::cout << "\n";

  for (int i = 0; i < 10; ++i) a_ints_cpy[i] += 2;  // increase array by 2
  increase(v_int_cpy.begin(), v_int_cpy.end(), 3);
  increase(int_list_cpy.begin(), int_list_cpy.end(), 5);
  std::cout << "a_ints_cpy[]:\t";
  print_array(std::cout, &a_ints_cpy[0]);
  std::cout << "v_int_cpy += 3:"
            << "\t";
  print_iter(v_int_cpy.begin(), v_int_cpy.end());
  std::cout << "list_cpy += 5:"
            << "\t";
  print_iter(int_list_cpy.begin(), int_list_cpy.end());

  std::cout << "\n";

  // write copy()
  // use copy() to copy array into vector and list into array
  // use std::find()...

  return 0;
}