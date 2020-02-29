#define COUNT 10
#define SIZE 100
#include <stdlib.h>
#include "QuickSort.hh"
class Tables {
  int Tab[COUNT][SIZE];
  public:
  ///konstruktor domyślny
  Tables();
  ///destruktor
  ~Tables()=default;
  //funkcja wyświetlająca
  void Show();
  //funkcja sortowanie tablic oparta na algorytmie szybkliego sortowania 
  void QuickSort();
  };

/**************************************************************************/

Tables::Tables(){
    for(int i=0;i<COUNT;i++)
        for(int j=0;j<SIZE;j++)
            Tab[i][j]=rand()%SIZE;
}
/**************************************************************************/
void Tables::Show(){
    for(int i=0;i<COUNT;i++){
        std::cout<<"Table"<<i+1;
        std::cout<<"\t";
        for(int j=0;j<SIZE;j++)
            std::cout<<Tab[i][j]<<"\t";
        std::cout<<"\n";
    }
}
/**************************************************************************/
void Tables::QuickSort(){
    for(int i=0;i<COUNT;i++)
        quicksort(Tab[i],0,SIZE-1);
}