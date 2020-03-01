#pragma once
#include <utility>
template < typename T>
void setMax(T tableToSort,int heapSize, int index) { //index of Parent
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
		setMax(tableToSort, heapSize, maxIndex);
	}
}
template < typename T>
void heapsort(T tableToSort,int size) {
	int n = size;
	int lastParent = n / 2 - 1;
	for (int i = lastParent; i >= 0; i--) {
		setMax(tableToSort, n, i);				//maksymalny kopiec
	}
	for (int i = n - 1; i > 0; i--) {
		std::swap(tableToSort[0], tableToSort[i]);
		setMax(tableToSort, --n, 0);
	}
}
