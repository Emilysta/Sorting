#pragma once
#include <utility>
template < typename T>
void setMaxHeap(T tableToSort,int heapSize, int index) { //index of Parent
	int maxIndex = index;
	int leftFromIndex = 2 * index + 1;
	int rightFromIndex = 2 * index + 2;
	if (leftFromIndex < heapSize && tableToSort[leftFromIndex]> tableToSort[maxIndex]) {
		maxIndex = leftFromIndex;
	}
	if (rightFromIndex < heapSize && tableToSort[rightFromIndex]> tableToSort[maxIndex]) {
		maxIndex = rightFromIndex;
	}
	if (maxIndex != index) {
		std::swap(tableToSort[maxIndex], tableToSort[index]);
		setMaxHeap(tableToSort, heapSize, maxIndex); //if it's now okey?
	}
}
template < typename T>
void heapsort(T tableToSort,int size) {
	int n = size;
	int lastParent = n / 2 - 1;
	for (int i = lastParent; i >= 0; i--) {
		setMaxHeap(tableToSort, n, i);				//max Heap?
	}
	for (int i = n - 1; i > 0; i--) {
		std::swap(tableToSort[0], tableToSort[i]);
		setMaxHeap(tableToSort, --n, 0);
	}
}
