#ifndef DESKTOP_CSCE240_HW3_MAX_HEAP_H_  //NOLINT
#define DESKTOP_CSCE240_HW3_MAX_HEAP_H_  //NOLINT
// Copyright Juan De Filippis

#include <array>
#include <iostream>
void Add(int item, int heap[], int count);
int Remove(int heap[], int count);
void MaxHeapify(int array[], int size);
void HeapSortAsc(int array[], int size);

#endif  //NOLINT
