#pragma once 
#include <utility>
template < typename T>
int division(T Table[], int first, int last) {
    int pivot = (last - first) / 2 + first;
    T piv = Table[pivot];
    int l = first, r = last;
    while (true) {
        while (Table[l] < piv)
            l++;
        while (Table[r] > piv)
            r--;
        if (l < r) {
            std::swap(Table[l], Table[r]);
            l++;
            r--;
        }
        else
            return r;
    }
}

template < typename T >
void  quicksort(T Table[], int first, int last){
    int pivot;
    if (first < last)
    {
        pivot = division(Table, first, last);
        quicksort(Table, first, pivot);
        quicksort(Table, pivot + 1, last);
    }
}