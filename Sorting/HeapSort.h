#pragma once
#include <utility>
template < typename T>
void setMaxHeap(T tableToSort,int heapSize, int indexOfFirst, int lastParent, int i) { //number of Parent 
	int maxIndex = lastParent ;
	int leftFromIndex = 2 * i + 1 + indexOfFirst;
	int rightFromIndex = 2 * i + 2 + indexOfFirst;
	if (leftFromIndex < heapSize && tableToSort[leftFromIndex]> tableToSort[maxIndex]) {
		maxIndex = leftFromIndex;
	}
	if (rightFromIndex < heapSize && tableToSort[rightFromIndex]> tableToSort[maxIndex]) {
		maxIndex = rightFromIndex;
	}
	if (maxIndex != lastParent) {
		std::swap(tableToSort[maxIndex], tableToSort[lastParent]);
		i = i + maxIndex - lastParent;
		setMaxHeap(tableToSort, heapSize, indexOfFirst,maxIndex,i); //if it's now okey?
	}
}
template < typename T>
void heapsort(T tableToSort,int first, int last) {
	int n = last - first + 1;
	int lastParent = first + n / 2 - 1;
	int k = 0;
	for (int i = lastParent,k=lastParent-first; i >= first; i--,k--) {
		setMaxHeap(tableToSort, n, first,i,k);     //max Heap?
	}
	for (int i = last; i > first; i--) {
		std::swap(tableToSort[first], tableToSort[i]);
		setMaxHeap(tableToSort, --n, first, first,0);
	}
}
