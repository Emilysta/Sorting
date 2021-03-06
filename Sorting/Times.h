#pragma once
#include "TypesOfTables.h"
#include <iostream>
#include <fstream>
#include <string>

//template < typename T>
//void sortFragment(T** array, int size, float percent) {
//	for (int i = 0; i < COUNT; i++) {
//		quicksort(array[i], 0, (int)(size * percent - 1));
//	}
//}

template < typename T, int size>
void times(Tables<T,size>* arr) {
	float percent[] = {0.25,0.5,0.75,0.95,0.99,0.997 }; 
	T** temp = new T*[COUNT];

	for (int i = 0; i < COUNT; i++) { //building arrays of right sizes
		temp[i] = new T[size];
	}
	std::ofstream myFile;
	myFile.open("Dane.txt",std::ios::out|std::ios::app);
	if (!myFile) {
		std::cout << "err";
	}
	arr->CopyTo(temp);
	myFile << "Percent of sorted array;Name;Size;Time[micros]"<<std::endl<<"0;";
	myFile.close();
	arr->QuickSort();
	for (int i = 0; i < 6; i++) {
		myFile.open("Dane.txt", std::ios::out | std::ios::app);
		myFile << percent[i] <<";";
		myFile.close();
		arr->CopyFrom(temp);
		arr->SortFragment(percent[i]);
		arr->QuickSort();
		arr->isSorted();
	}
	arr->CopyFrom(temp);
	arr->Reverse();
	arr->isReverseSorted();
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
	myFile << "Reverse;";
	myFile.close();
	arr->QuickSort();
	arr->isSorted();

	arr->CopyFrom(temp);
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
	myFile << "0;";
	myFile.close();
	arr->MergeSort();
	for (int i = 0; i < 6; i++) {
		myFile.open("Dane.txt", std::ios::out | std::ios::app);
		myFile << percent[i] << ";";
		myFile.close();
		arr->CopyFrom(temp);
		arr->SortFragment(percent[i]);
		arr->MergeSort();
		arr->isSorted();
	}
	arr->CopyFrom(temp);
	arr->Reverse();
	arr->isReverseSorted();
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
	myFile << "Reverse;";
	myFile.close();
	arr->MergeSort();
	arr->isSorted();

	arr->CopyFrom(temp);
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
	myFile << "0;";
	myFile.close();
	arr->IntroSort();
	for (int i = 0; i < 6; i++) {
		myFile.open("Dane.txt", std::ios::out | std::ios::app);
		myFile << percent[i] << ";";
		myFile.close();
		arr->CopyFrom(temp);
		arr->SortFragment(percent[i]);
		arr->IntroSort();
		arr->isSorted();
	}
	arr->CopyFrom(temp);
	arr->Reverse();
	arr->isReverseSorted();
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
	myFile << "Reverse;";
	myFile.close();
	arr->IntroSort();
	arr->isSorted();
	myFile << std::endl;

	myFile.close();
	for (int i = 0; i < COUNT; i++) {
		delete[] temp[i];
	}
	delete[] temp;
}

void Times() {
	std::cout << "Allocation... "<<std::endl;
	Tables10k arr10k;
	Tables50k arr50k;
	Tables100k arr100k;
	Tables500k arr500k;
	Tables1M arr1M;

	std::cout << "Saving..." << std::endl;

	times(&arr10k);
	std::cout << "Saving..." << std::endl;
	times(&arr50k);
	std::cout << "Saving..." << std::endl;
	times(&arr100k);
	std::cout << "Saving..." << std::endl;
	times(&arr500k);
	std::cout << "Saving..." << std::endl;
	times(&arr1M);
	std::cout << "Saved times to file" << std::endl;

}