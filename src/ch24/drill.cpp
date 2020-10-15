

//
// 7. Read ten complex<double> s from cin (yes, cin supports >> for complex )
// and put them into a Matrix . Calculate and output the sum of the ten com-
// plex numbers.
//
// 8. Read six int s into a Matrix<int,2> m(2,3) and print them out.

#include <cmath>
#include <cerrno>
#include <cfenv>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Matrix.cpp"
#include "MatrixIO.cpp"

//------------------------------------------------------------------------------

void drill_1();
void drill_2();
void drill_3();
void drill_4();
void drill_5();
void drill_6();

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

int main()
{
  try {
    // drill_1();
    // drill_2();
    // drill_3();
    // drill_4();
    // drill_5();
    drill_6();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}

//------------------------------------------------------------------------------

void drill_1()
{
  // 1. Print the size of a char, a short, an int, a long, a float, a double,
  // an int*, and a double* (use sizeof, not <limits>).

  std::cout << "char:" << '\t' << sizeof(char) << '\n';
  std::cout << "int:" << '\t' << sizeof(int) << '\n';
  std::cout << "long:" << '\t' << sizeof(long) << '\n';
  std::cout << "float:" << '\t' << sizeof(float) << '\n';
  std::cout << "double:" << '\t' << sizeof(double) << '\n';
  std::cout << "int*:" << '\t' << sizeof(int*) << '\n';
  std::cout << "double*:" << '\t' << sizeof(double*) << '\n';
}

//------------------------------------------------------------------------------

void drill_2()
{
  // 2. Print out the size as reported by sizeof of Matrix<int> a(10) ,
  // Matrix<int> b(100) , Matrix<double> c(10) , Matrix<int,2> d(10,10) ,
  // Matrix<int,3> e(10,10,10)
  Numeric_lib::Matrix<int> a(10);
  Numeric_lib::Matrix<int> b(100);
  Numeric_lib::Matrix<double> c(10);
  Numeric_lib::Matrix<int, 2> d(10, 10);
  Numeric_lib::Matrix<int, 3> e(10, 10, 10);

  std::cout << "Matrix<int> a(10): " << '\t' << sizeof(a) << '\n';
  std::cout << "Matrix<int> b(100): " << '\t' << sizeof(b) << '\n';
  std::cout << "Matrix<double> c(10): " << '\t' << sizeof(c) << '\n';
  std::cout << "Matrix<int, 2> d(10, 10): " << '\t' << sizeof(d) << '\n';
  std::cout << "Matrix<int, 3> e(10, 10, 10): " << '\t' << sizeof(e) << '\n';
}

//------------------------------------------------------------------------------

void drill_3()
{
  // 3. Print out the number of elements of each of the Matrixes from 2.
  Numeric_lib::Matrix<int> a(10);
  Numeric_lib::Matrix<int> b(100);
  Numeric_lib::Matrix<double> c(10);
  Numeric_lib::Matrix<int, 2> d(10, 10);
  Numeric_lib::Matrix<int, 3> e(10, 10, 10);
  std::cout << "Number of elements in the following Matrixes:\n";
  std::cout << "//---------------------------------------------\n";
  std::cout << "Matrix<int> a(10): " << '\t' << a.size() << '\n';
  std::cout << "Matrix<int> b(100): " << '\t' << b.size() << '\n';
  std::cout << "Matrix<double> c(10): " << '\t' << c.size() << '\n';
  std::cout << "Matrix<int, 2> d(10, 10): " << '\t' << d.size() << '\n';
  std::cout << "Matrix<int, 3> e(10, 10, 10): " << '\t' << e.size() << '\n';
}

//------------------------------------------------------------------------------

void drill_4()
{
  // 4. Write a program that takes ints from cin and outputs the sqrt() of each
  // int, or “no square root” if sqrt(x) is illegal for some x (i.e., check your
  // sqrt() return values).
  const std::string illegal{"no square root"};
  std::cout << "Enter an integer and press enter to compute the square root.\n";
  std::cout << "To quit the program, type the | character followed by enter.\n";

  int n = 0;

  if (std::cin) {
    while (std::cin >> n && n != '|') {
      errno = 0;
      std::feclearexcept(FE_ALL_EXCEPT);
      double result = std::sqrt(n);

      if (errno != 0 || n < 0) {
        std::cout << std::strerror(errno) << '\n';
        std::cout << illegal << '\n';
        n = 0;
      }
      else {
        std::cout << "sqrt(" << n << ") = " << result << '\n';
        n = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------

void drill_5()
{
  // 5. Read ten floating-point values from input and put them into a Matrix-
  //<double> . Matrix has no push_back() so be careful to handle an attempt
  // to enter a wrong number of double s. Print out the Matrix .
  Numeric_lib::Matrix<double> m(10);
  std::cout << "enter 10 floating-point values: ";
  double n = 0.0;
  // TODO: re-write input loop to better handle if user enters > 10 values
  for (int i = 0; i != 10; ++i) {
    std::cin >> n;
    m[i] = n;
  }

  // print m
  std::cout << m << '\n';
}

void drill_6()
{
  // 6. Compute a multiplication table for [0,n)*[0,m) and represent it as a 2D
  // Matrix . Take n and m from cin and print out the table nicely (assume that
  // m is small enough that the results fit on a line).

  std::cout << "Multiplication Table Generator\n";
  std::cout << "---------------------------------------------------------------"
               "----------\n";
  std::cout << "Please enter desired range as two integers\n";
  std::cout << "(ex: 10 25 generates a table with columns 0-10\n";
  std::cout << "and columns from 0-25).\n";
  std::cout << "---------------------------------------------------------------"
               "----------\n";
  std::cout << '\n';

  int n = 5;
  int m = 10;

  // std::cin >> n >> m;
  std::cout << '\n';

  // 2-dimension multiplication table
  Numeric_lib::Matrix<int, 2> m_table(n + 1, m + 1);  // handle zero-based idx

  for (int i = 0; i < m_table.dim1(); ++i)  // set values
  {
    for (int j = 0; j < m_table.dim2(); ++j) { m_table(i, j) = i * j; }
  }

  std::cout << "X  |";
  for (Numeric_lib::Index col = 1; col < m_table.dim1(); ++col) {
    std::cout << std::right << std::setfill(' ') << std::setw(2);
    std::cout << col << "  ";  // print column header
  }

  std::cout << '\n';
  for (Numeric_lib::Index col = 1; col < m_table.dim1() * 4; ++col) {
    std::cout << "-";
  }

  std::cout << '\n';
  for (Numeric_lib::Index row = 1; row < m_table.dim2(); ++row) {
    std::cout << std::right << std::setfill(' ') << std::setw(2);
    std::cout << row << " | " << m_table[row] << '\n';
    /* std::cout <<*/
  }

  /*for (int i = 0; i < m_table.dim1(); ++i) {
    for (int j = 0; i < m_table.dim2(); ++j) {
      std::cout << m_table(i, j) << " ";
    }
    std::cout << '\n';
  }*/
}

//------------------------------------------------------------------------------