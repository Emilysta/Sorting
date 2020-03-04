#pragma once
#include "TypesOfTables.h"
#include <string>

template < typename T>
void sortFragment(T** array, int size, float percent) {
	for (int i = 0; i < 100; i++) {
		quicksort(array[i], 0, (int)(size * percent - 1));
	}
}

template < typename T, int size>
void times(Tables<T,size>* arr) {
	float percent[] = {0.25,0.5,0.75,0.95,0.99,0.997 };
	T** temp = new T*[COUNT];

	for (int i = 0; i < COUNT; i++) { //building arrays of right sizes
		temp[i] = new T[size];
	}

	arr->CopyTo(temp);
	arr->QuickSort();
	for (int i = 0; i < 6; i++) {
		std::cout << "percent of sorted array: " << percent[i] << std::endl;
		sortFragment(temp, size, percent[i]);
		arr->CopyFrom(temp);
		arr->QuickSort();
		arr->isSorted();
	}

	arr->CopyTo(temp);
	arr->MergeSort();
	for (int i = 0; i < 6; i++) {
		std::cout << "percent of sorted array: " << percent[i] << std::endl;
		sortFragment(temp, size, percent[i]);
		arr->CopyFrom(temp);
		arr->MergeSort();
		arr->isSorted();
	}

	arr->CopyTo(temp);
	arr->IntroSort();
	for (int i = 0; i < 6; i++) {
		std::cout << "percent of sorted array: " << percent[i] << std::endl;
		sortFragment(temp, size, percent[i]);
		arr->CopyFrom(temp);
		arr->IntroSort();
		arr->isSorted();
	}
	std::cout << "\nxd";
	for (int i = 0; i < COUNT; i++) {
		delete[] temp[i];
	}
	delete[] temp;
}

void Times() {
	Tables10k arr10k;
	//Tables50k arr50k;
	//Tables100k arr100k;
	//Tables500k arr500k;
	//Tables1M arr1M;
	times(&arr10k);
}