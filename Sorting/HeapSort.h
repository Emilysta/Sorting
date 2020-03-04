#pragma once
#include <utility>
template < typename T>
//void setMaxHeap(T tableToSort, int heapSize, int indexOfFirst, int lastParent, int i) { //number of Parent 
//	int maxIndex = lastParent;
//	int leftFromIndex = 2 * i + 1 + indexOfFirst;
//	int rightFromIndex = 2 * i + 2 + indexOfFirst;
//	if (leftFromIndex < heapSize && tableToSort[leftFromIndex]> tableToSort[maxIndex]) {
//		maxIndex = leftFromIndex;
//	}
//	if (rightFromIndex < heapSize && tableToSort[rightFromIndex]> tableToSort[maxIndex]) {
//		maxIndex = rightFromIndex;
//	}
//	if (maxIndex != lastParent) {
//		std::swap(tableToSort[maxIndex], tableToSort[lastParent]);
//		i = i + maxIndex - lastParent;
//		setMaxHeap(tableToSort, heapSize, indexOfFirst, maxIndex, i); //if it's now okey?
//	}
//}
//template < typename T>
//void heapsort(T tableToSort, int first, int last) {
//	int n = last - first + 1;
//	int lastParent = first + n / 2 - 1;
//	int k = 0;
//	for (int i = lastParent, k = lastParent - first; i >= first; i--, k--) {
//		setMaxHeap(tableToSort, n, first, i, k);     //max Heap?
//	}
//	for (int i = last; i > first; i--) {
//		std::swap(tableToSort[first], tableToSort[i]);
//		setMaxHeap(tableToSort, --n, first, first, 0);
//	}
//}


void Heapify(T arr, int size, int root) {
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
        Heapify(arr, size, largest);
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
        Heapify(temp, (end - start), i);
    }
    for (int i = (end - start) - 1; i >= 0; --i) {
        std::swap(temp[0],temp[i]);
        Heapify(temp, i, 0);
    }

    for (int i = 0; i < end - start; i++) {
        arr[i + start] = temp[i];
    }
    delete[] temp;
}