#include "QuickSort.hh"
#include <iostream>
#define COUNT 100 
template < typename T, int Wymiar>
class Tables {
  T Tab[COUNT][Wymiar];
  public:
  ///konstruktor domyślny
  Tables();
  ///destruktor
  ~Tables()=default;
  //funkvja wyświetlająca
  void Show();
  void QuickSort(int number);
  };

/**************************************************************************/
template < typename T , int Wymiar >
Tables<T,Wymiar>::Tables(){
    for(int i=0;i<COUNT;i++)
        for(int j=0;j<Wymiar;j++)
            Tab[i][j]=rand()%10;
}
/**************************************************************************/
template < typename T , int Wymiar >
void Tables<T,Wymiar>::Show(){
    for(int i=0;i<COUNT;i++){
        std::cout<<"Table"<<i+1;
        std::cout<<"\t";
        for(int j=0;j<Wymiar;j++)
            std::cout<<Tab[i][j]<<"\t";
        std::cout<<"\n";
    }
}
/**************************************************************************/
template < typename T , int Wymiar >
void Tables<T,Wymiar>::QuickSort(int number){
quicksort(Tab[number],0,Wymiar-1);
}
