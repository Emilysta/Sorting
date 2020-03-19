#pragma once
#include <utility>
template < typename T>

void setMaxHeap(T arr, int size, int parent) {
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != parent) {
        std::swap(arr[parent],arr[largest]);
        setMaxHeap(arr, size, largest);
    }
}
template < typename T>
void heapsort(T* arr, int first, int last) {
    ++last;

    T* temp = new int[last - first];
    for (int i = 0; i < last - first; i++) {
        temp[i] = arr[i + first];
    }

    for (int i = (last - first) / 2 - 1; i >= 0; --i) {
        setMaxHeap(temp, (last - first), i);
    }
    for (int i = (last - first) - 1; i >= 0; --i) {
        std::swap(temp[0],temp[i]);
        setMaxHeap(temp, i, 0);
    }

    for (int i = 0; i < last - first; i++) {
        arr[i + first] = temp[i];
    }
    delete[] temp;
}