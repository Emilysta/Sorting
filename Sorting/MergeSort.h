#pragma once
#include <algorithm>
template < typename T >
void merge(T Table[], int first, int pivot, int last) {
	//int number1 = pivot - first + 1;
	//int number2 = last - pivot + 1;
	//T* L = new T[number1];
	//T* R = new T[number2];
	//
	//for (int i = 0; i < number1; i++) {
	//	L[i] = Table[first + i];
	//}
	//for (int i = 0; i < number2; i++) {
	//	R[i] = Table[pivot + 1 + i];
	//}
	//int i=0, j=0, c=0;
	//while (i<number1 && j<number2) {
	//	if (L[i] <= R[j]) {
	//		Table[c] = L[i];
	//		i++;
	//	}
	//	else {
	//		Table[c] = R[j];
	//		j++;
	//	}
	//	c++;
	//}
	//while (i < number1) {
	//	Table[c] = L[i];
	//	i++;
	//	c++;
	//}
	//while (j < number2) {
	//	Table[c] = R[j];
	//	j++;
	//	c++;
	//}
	int number = last - first + 1;
	std::cout << number;
	T* Tab = new T[last - first + 1];
	int i1 = first, i2 = pivot + 1, i = first;
	for (int i = 0; i < last - first +1; i++) {
		if (i1 == (pivot + 1) || (i2 < last && Table[i1] > Table[i2])) {
			Tab[i] = Table[i2];
			i2++;
		}
		else {
			Tab[i] = Table[i1];
			i1++;
		}
	}
	int ind = 0;
	for(int i=first;i<last;i++){
		Table[i] = Tab[ind];
		ind++;
	}
	delete[] Tab;
}
template < typename T >
void mergesort(T Table[], int first, int last) {
	if (first < last){
		int pivot = first + (last - first) / 2;
		mergesort(Table, first, pivot);
		mergesort(Table, pivot + 1, last);
		merge(Table, first, pivot, last);
	}
}