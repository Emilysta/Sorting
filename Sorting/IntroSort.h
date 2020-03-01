#pragma once
#include <utility>
#include "HeapSort.h"
#include "QuickSort.h"
#pragma once
#include <cmath>
#include "HeapSort.h"
#include "QuickSort.h"

template < typename T>
int sort(T tableToSort,int maxDepth, int first, int last) {
	int n = last - first + 1;
	int pivot;
	if (n<=1) {
		return 0;
	}
	else if (maxDepth == 0) {
		heapsort(tableToSort, n);
	}
	else {
		pivot = division(tableToSort, first, last); //Recursive division with returning pivot
		sort(tableToSort, maxDepth - 1, first, pivot-1);
		sort(tableToSort, maxDepth - 1, pivot+1,last);
	}
}
template < typename T>
void introsort(T tableToSort, int first, int last) {
	int size = last - first + 1;
	int maxDepth = (int)(log(size)*2);//"2" that's  standard also can choose anything else
	sort(tableToSort, maxDepth, first, last);
}
