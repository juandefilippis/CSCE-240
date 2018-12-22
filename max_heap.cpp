// Copyright juan
#include "max_heap.h" //NOLINT
void bubbleUp(int count, int heap[]) {
    int curr = count;
    while (curr > 0 && (heap[(curr-1)/2]-heap[curr]) < 0) {
        int temp = heap[(curr-1)/2];
        heap[(curr-1)/2] = heap[curr];
        heap[curr] = temp;
        curr = (curr-1)/2;
    }
}
void bubbleDown(int count, int heap[]) {
    int currIndex = 0;
    while (currIndex*2+1 < count) {
        int bigIndex = currIndex*2+1;
        if (currIndex*2+2 < count && heap[currIndex*2+1]-(heap[currIndex*2+2]) < 0)
            bigIndex = currIndex*2+2;
        if (heap[currIndex]-(heap[bigIndex]) < 0) {
            int temp = heap[currIndex];
            heap[currIndex]= heap[bigIndex];
            heap[bigIndex] = temp;
        } else {
            break;
        }
        currIndex = bigIndex;
    }
}
void Add(int item, int heap[], int count) {
    heap[count] = item;
    bubbleUp(count , heap);
}
int Remove(int heap[], int count) {
    int temp = heap[0];
    heap[0]= heap[count-1];
    heap[count-1]= 0;
    bubbleDown(count, heap);
    return temp;
}
void MaxHeapify(int array[], int size) {
    int array2[size];  //NOLINT
    for (int i = 0; i < size; i++)
        Add(array[i], array2, i);
    for (int i = 0; i < size; i++)
        array[i] = array2[i];
}
void HeapSortAsc(int array[], int size) {
    int r = size/2-1;
    int temp;
    for (int i = r; i > 0; i--)
        MaxHeapify(array, size);
    for (int i = size-1; i > 0; i--) {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        MaxHeapify(array, i);
    }
}

