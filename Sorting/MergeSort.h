#pragma once
#include <algorithm>
template < typename T >
void merge(T Table[], int first, int pivot, int last) {
	int number = last - first + 1;
	T* Tab = new T[number];
	int i1 = first, i2 = pivot+1;
	int i = 0;
	while ((i1 <= pivot) && (i2 <= last)) {
		if (Table[i1] <= Table[i2]) {
			Tab[i] = Table[i1];
			++i1;
		}
		else {
			Tab[i] = Table[i2];
			++i2;
		}
		++i;
	}
	while (i1 <= pivot) {
		Tab[i] = Table[i1];
		++i1; ++i;
	}
	while (i2 <= last) {
		Tab[i] = Table[i2];
		++i2; ++i;
	}
	for(int i=first;i<=last;i++){
		Table[i] = Tab[i-first];
	}
	delete[] Tab;
 }

template < typename T >
void mergesort(T Table[], int first, int last) {
	if (first < last){
		int pivot = first + (last - first) / 2;
		mergesort(Table, first, pivot);
		mergesort(Table, pivot+1 , last);
		merge(Table, first, pivot, last);
	}
}
