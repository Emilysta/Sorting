#pragma once
#include "HeapSort.h"
#include "IntroSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

void Driver() {
    int* arrayToTest = new int[SIZETOTEST];

    for (int j = 0; j < SIZETOTEST; j++) {
        arrayToTest[j] = rand() % 100;
    }

    std::cout << "Array to test:  ";
    for (int i = 0; i < SIZETOTEST; i++) {
        std::cout << arrayToTest[i] << "  ";
    }
    std::cout << std::endl;

    std::cout << "QuickSort test: ";
    quicksort(arrayToTest, 0, SIZETOTEST - 1);
    issorted(arrayToTest, 0, SIZETOTEST - 1);
   
	std::cout << "Sorted array:  ";
	for (int i = 0; i < SIZETOTEST; i++) {
		std::cout << arrayToTest[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Array to test:  ";
	for (int j = 0; j < SIZETOTEST; j++) {
		arrayToTest[j] = rand() % 100;
		std::cout << arrayToTest[j] << "  ";
	}

	std::cout << std::endl;

    std::cout << "MergeSort test: ";
    mergesort(arrayToTest, 0, SIZETOTEST - 1);
    issorted(arrayToTest, 0, SIZETOTEST - 1);

	std::cout << "Sorted array:  ";
	for (int i = 0; i < SIZETOTEST; i++) {
		std::cout << arrayToTest[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Array to test:  ";
	for (int j = 0; j < SIZETOTEST; j++) {
		arrayToTest[j] = rand() % 100;
		std::cout << arrayToTest[j] << "  ";
	}

	std::cout << std::endl;

    std::cout << "HeapSort test: ";
    heapsort(arrayToTest, 0, SIZETOTEST - 1);
    issorted(arrayToTest, 0, SIZETOTEST - 1);

	std::cout << "Sorted array:  ";
	for (int i = 0; i < SIZETOTEST; i++) {
		std::cout << arrayToTest[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Array to test:  ";
	for (int j = 0; j < SIZETOTEST; j++) {
		arrayToTest[j] = rand() % 100;
		std::cout << arrayToTest[j] << "  ";
	}

	std::cout << std::endl;

    std::cout << "IntroSort test: ";
    introsort(arrayToTest, 0, SIZETOTEST - 1);
    issorted(arrayToTest, 0, SIZETOTEST - 1);

	std::cout << "Sorted array:  ";
	for (int i = 0; i < SIZETOTEST; i++) {
		std::cout << arrayToTest[i] << "  ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
    delete[] arrayToTest;
}