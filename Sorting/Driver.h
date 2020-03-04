#pragma once
#include "HeapSort.h"
#include "IntroSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

void Driver() {
    int* arrayToTest = new int[SIZETOTEST];
    int* tempArrayToTest = new int[SIZETOTEST];
    for (int j = 0; j < SIZETOTEST; j++) {
        arrayToTest[j] = rand() % 100;
        tempArrayToTest[j] = arrayToTest[j];
    }

    std::cout << "Array to test:  ";
    for (int i = 0; i < SIZETOTEST; i++) {
        std::cout << arrayToTest[i] << "  ";
    }
    std::cout << std::endl;

    std::cout << "QuickSort test: ";
    quicksort(tempArrayToTest, 0, SIZETOTEST - 1);
    issorted(tempArrayToTest, 0, SIZETOTEST - 1);
    std::cout << std::endl;
    /*copy to test next sorting*/
    for (int j = 0; j < SIZETOTEST; j++) {
        tempArrayToTest[j] = arrayToTest[j];
    }

    std::cout << "MergeSort test: ";
    mergesort(tempArrayToTest, 0, SIZETOTEST - 1);
    issorted(tempArrayToTest, 0, SIZETOTEST - 1);
    std::cout << std::endl;
    /*copy to test next sorting*/
    for (int j = 0; j < SIZETOTEST; j++) {
        tempArrayToTest[j] = arrayToTest[j];
    }

    std::cout << "HeapSort test: ";
    heapsort(tempArrayToTest, 0, SIZETOTEST - 1);
    issorted(tempArrayToTest, 0, SIZETOTEST - 1);
    std::cout << std::endl;
    /*copy to test next sorting*/
    for (int j = 0; j < SIZETOTEST; j++) {
        tempArrayToTest[j] = arrayToTest[j];
    }

    std::cout << "IntroSort test: ";
    introsort(tempArrayToTest, 0, SIZETOTEST - 1);
    issorted(tempArrayToTest, 0, SIZETOTEST - 1);
    std::cout << std::endl;
    delete[] arrayToTest;
    delete[] tempArrayToTest;
}