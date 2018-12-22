/* Copyright 2018 Jeremy S Lewis
 * A very simple test of max_heap int array functions.
 */

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

#include "max_heap.h"  //NOLINT


/* Turns int array into a delimited string. */
const string ToString(const int array[], int size, string delim=" ");

/* Tests Add function for right child of a left child at depth 2 */
bool TestAdd();

/* Tests Remove function by two removals */
bool TestRemove();

/* Tests MaxHeapify function by adding ints from 0 - 9 */
bool TestMaxHeapify();

/* Tests TestHeapSortAsc function by adding ints from 0 - 9 in a random order */
bool TestHeapSortAsc();

/* Checks for inclusion of algorithm lib in target architecture */
bool TestLibrary();

int main(int argc, char* argv[]) {
  if (TestAdd())
    cout << "\tPASSED" << endl;
  else
    cout << "\tFAILED" << endl;

  if (TestRemove())
    cout << "\tPASSED" << endl;
  else
    cout << "\tFAILED" << endl;

  if (TestMaxHeapify())
    cout << "\tPASSED" << endl;
  else
    cout << "\tFAILED" << endl;

  if (TestHeapSortAsc())
    cout << "\tPASSED" << endl;
  else
    cout << "\tFAILED" << endl;

  cout << "Checking Prohibited Libraries" << endl;
  if (TestLibrary())
    cout << "\tPASSED" << endl;
  else
    cout << "\tFAILED" << endl;

  return 0;
}

bool TestAdd() {
  // create a heap of item count 4, initialize extra space to -1
  int heap[] = {9, 7, 8, 4, -1};
  int count = 4;

  // add value 6 to heap and update item count
  Add(6, heap, count);
  ++count;

  string expected = "9 7 8 4 6";
  string actual = ToString(heap, count);

  cout << "TestAdd" << endl;
  if (expected != actual) {
    cout << "\tExpected: " << expected << endl;
    cout << "\tActual: " << actual << endl;

    return false;
  }

  return true;
}


bool TestRemove() {
  // create a heap of item count 4, initialize extra space to -1
  int heap[] = {9, 7, 8, 4, 6, 1, 5};
  int count = 7;

  // remove top value from heap and update item count
  int exp_val = 9;
  int act_val = Remove(heap, count);
  --count;

  string exp_heap = "8 7 5 4 6 1";
  string act_heap = ToString(heap, count);

  cout << "TestRemove" << endl;
  if (exp_val != act_val) {
    cout << "\tExpected Value Removed: " << exp_val << endl;
    cout << "\tActual Value Remove: " << act_val << endl;

    return false;
  }

  if (exp_heap != act_heap) {
    cout << "\tExpected Heap After Removal: " << exp_heap << endl;
    cout << "\tActual Heap After Removal: " << act_heap << endl;

    return false;
  }

  exp_val = 8;
  act_val = Remove(heap, count);
  --count;

  exp_heap = "7 6 5 4 1";
  act_heap = ToString(heap, count);

  if (exp_val != act_val) {
    cout << "\tExpected Value Removed: " << exp_val << endl;
    cout << "\tActual Value Remove: " << act_val << endl;

    return false;
  }

  if (exp_heap != act_heap) {
    cout << "\tExpected Heap After Removal: " << exp_heap << endl;
    cout << "\tActual Heap After Removal: " << act_heap << endl;

    return false;
  }

  return true;
}

bool TestMaxHeapify() {
  int array[] = {2, 0, 1, 4, 9, 8, 5, 6, 3, 7};
  int count = 10;

  // add value 6 to heap and update item count
  MaxHeapify(array, count);

  string expected = "9 7 8 4 6 1 5 0 3 2";
  string actual = ToString(array, count);

  cout << "TestMaxHeapify" << endl;
  if (expected != actual) {
    cout << "\tExpected: " << expected << endl;
    cout << "\tActual: " << actual << endl;

    return false;
  }

  return true;
}


bool TestHeapSortAsc() {
  // create a heap of item count 4, initialize extra space to -1
  int array[] = {2, 0, 1, 4, 9, 8, 5, 6, 3, 7};
  int count = 10;

  // add value 6 to heap and update item count
  HeapSortAsc(array, count);

  string expected = "0 1 2 3 4 5 6 7 8 9";
  string actual = ToString(array, count);

  cout << "TestHeapSortAsc" << endl;
  if (expected != actual) {
    cout << "\tExpected: " << expected << endl;
    cout << "\tActual: " << actual << endl;

    return false;
  }

  return true;
}


bool TestLibrary() {
  bool algorithm_included = false;
  #ifdef _GLIBCXX_ALGORITHM
  // this will be defined if algorithm library is included on target
  //    architecture
  algorithm_included = true;
  #endif
  if (algorithm_included) {
    cout << "\tSTL algorithm lib included." << endl;
    return false;
  }

  return true;
}


const string ToString(const int array[], int size, string delim) {
  stringstream sout;

  for (int i = 0; i < size; ++i)
    if (i < size - 1)
      sout << array[i] << delim;
    else
      sout << array[i];

  return sout.str();
}
/*
inline int parent (int n){
    return (n-1)/2;
}
inline int left(int n){
    return (2*n +1);
}
inline int right (int n){
    return +(n*2 +2)
}

*/
