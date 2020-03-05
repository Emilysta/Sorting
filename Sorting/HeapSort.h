#pragma once
#include <utility>
template < typename T>

void setMaxHeap(T arr, int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        std::swap(arr[root],arr[largest]);
        setMaxHeap(arr, size, largest);
    }
}
template < typename T>
void heapsort(T* arr, int start, int end) {
    ++end;

    T* temp = new int[end - start];
    for (int i = 0; i < end - start; i++) {
        temp[i] = arr[i + start];
        //std::cout << temp[i] << "=" << arr[i + start] << std::endl;
    }

    for (int i = (end - start) / 2 - 1; i >= 0; --i) {
        setMaxHeap(temp, (end - start), i);
    }
    for (int i = (end - start) - 1; i >= 0; --i) {
        std::swap(temp[0],temp[i]);
        setMaxHeap(temp, i, 0);
    }

    for (int i = 0; i < end - start; i++) {
        arr[i + start] = temp[i];
    }
    delete[] temp;
}