#include <stdio.h>
#include <iostream>
#include "Utils.h"
void printArraySize(char* array[])
{
  int arraySize = sizeof(array) / sizeof(array[0]);

  // print size of array
  std::cout << "size of array (as function argument): ";
  std::cout << arraySize;
}

int main(int argc, char* argv[])
{
  char* array[] = {"Process Variable Names", "Process Variable Parameters"};

  // call function to print array size
  printArraySize(array);

  // calculate array size
  int arraySize = sizeof(array) / sizeof(array[0]);

  // print size of array
  std::cout << "\nsize of array (declared in function): ";
  std::cout << arraySize << std::endl;
  keep_window_open("~");
  return 0;
}