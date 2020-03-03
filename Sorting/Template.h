#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "IntroSort.h"
#include "IsSorted.h"
#include <iostream>
#define COUNT 10
template < typename T, int Size>
class Tables {
  T Tab[COUNT][Size];
  //T TabCopy[COUNT][Size]
  public:
  //constructor
  Tables();
  //destructor
  ~Tables()=default;
  //lets show these arrays/tables
  void Show();
  void QuickSort();
  void MergeSort();
  void HeapSort();
  void IntroSort();
  void isSorted();
  };

template < typename T , int Size >
Tables<T, Size>::Tables(){
    for(int i=0;i<COUNT;i++)
        for(int j=0;j<Size;j++)
            Tab[i][j]=rand();
}

template < typename T , int Size >
void Tables<T, Size>::Show(){
    for(int i=1;i<2;i++){
        std::cout<<"Table"<<i+1;
        std::cout<<"\t";
        for(int j=0;j< Size;j++)
            std::cout<<Tab[i][j]<<"\n";
        std::cout<<"\n";
    }
}

template < typename T , int Size >
void Tables<T, Size>::QuickSort(){
    for(int i=0;i<COUNT;i++)
        quicksort(Tab[i],0, Size-1);
}

template < typename T, int Size >
void Tables<T, Size>::MergeSort() {
    for (int i = 0; i < COUNT; i++)
        mergesort(Tab[i], 0, Size-1);
}

template < typename T, int Size >
void Tables<T, Size>::HeapSort() {
	//heapsort(Tab[1], 0, Size - 1);
	for (int i = 0; i < COUNT; i++)
		heapsort(Tab[i],0, Size-1);
}
template < typename T, int Size >
void Tables<T, Size>::IntroSort() {
	introsort(Tab[1], 0, Size-1);
	/*for (int i = 0; i < COUNT; i++)
		introsort(Tab[i], 0, Size-1);*/
}


template < typename T, int Size >
void Tables<T, Size>::isSorted() {
	for (int i = 0; i < COUNT; i++) {
		std::cout << i << ".\t";
		issorted(Tab[i], 0, Size - 1);
	}
}