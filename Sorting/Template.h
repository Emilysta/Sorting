#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "IntroSort.h"
#include "IsSorted.h"
#include <iostream>
#include <chrono>
#include <fstream>

#define COUNT 100
#define SIZETOTEST 15

template < typename T, int Size>
class Tables{
  T** Tab=new T*[COUNT];
  //T Tab[COUNT][Size];
  public:
  //constructor
  Tables();
  //destructor
  ~Tables();
  //lets show these arrays/tables
  void Show();
  void Generate();
  void QuickSort();
  void MergeSort();
  void HeapSort();
  void IntroSort();
  void isSorted();
  void CopyTo(T **tableToCopy);
  void CopyFrom(T** tableToCopy);
  };

template < typename T , int Size >
Tables<T, Size>::Tables(){
    for (int i = 0; i < COUNT; i++) {
        Tab[i] = new T[Size];
        for (int j = 0; j < Size; j++) {
            Tab[i][j] = rand();
        }
    }

}

template < typename T, int Size >
void Tables<T, Size>::CopyTo(T **tableToCopy) {
    for (int i = 0; i < COUNT; i++) {
        for (int j = 0; j < Size; j++) {
            tableToCopy[i][j] = Tab[i][j];
        }
    }

}

template < typename T, int Size >
void Tables<T, Size>::CopyFrom(T** tableToCopy) {
    for (int i = 0; i < COUNT; i++) {
        for (int j = 0; j < Size; j++) {
            Tab[i][j]=tableToCopy[i][j];
        }
    }

}

template < typename T, int Size >
void Tables<T, Size>::Generate() {
    for(int i=0;i<COUNT;i++)
        for(int j=0;j<Size;j++)
            Tab[i][j]=rand();
}

template < typename T, int Size >
Tables<T, Size>::~Tables() {
    for (int i = 0; i < COUNT; i++)
        delete[] Tab[i];
    delete[] Tab;
}

template < typename T , int Size >
void Tables<T, Size>::Show(){
    for(int i=0;i<COUNT;i++){
        std::cout<<"Table"<<i+1;
        std::cout<<"\t";
        for(int j=0;j< Size;j++)
            std::cout<<Tab[i][j]<<"\n";
        std::cout<<"\n";
    }
}

template < typename T , int Size >
void Tables<T, Size>::QuickSort(){
	std::ofstream myFile;
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<COUNT;i++)
        quicksort(Tab[i],0, Size-1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    myFile << "QuickSort, sizes:" << Size << " time:" << duration.count() << "ms\n";
	myFile.close();
}

template < typename T, int Size >
void Tables<T, Size>::MergeSort() {
	std::ofstream myFile;
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < COUNT; i++)
        mergesort(Tab[i], 0, Size-1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    myFile << "MergeSort, sizes:" << Size << " time:" << duration.count() << "ms\n";
	myFile.close();
}

template < typename T, int Size >
void Tables<T, Size>::HeapSort() {
	std::ofstream myFile;
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
    auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; i++)
		heapsort(Tab[i],0, Size-1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    myFile << "HeapSort, sizes:" << Size << " time:" << duration.count() << "ms\n";
	myFile.close();
}

template < typename T, int Size >
void Tables<T, Size>::IntroSort() {
	std::ofstream myFile;
	myFile.open("Dane.txt", std::ios::out | std::ios::app);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < COUNT; i++) {
        introsort(Tab[i], 0, Size - 1);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    myFile << "IntroSort, sizes:" << Size << " time:" << duration.count() << "ms\n";
	std::cout<< "IntroSort, sizes:" << Size << " time:" << duration.count() << "ms\n";
	myFile.close();
}

template < typename T, int Size >
void Tables<T, Size>::isSorted() {
	for (int i = 0; i < COUNT; i++) {
		issorted(Tab[i], 0, Size - 1);
	}
}

