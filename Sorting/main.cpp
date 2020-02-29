#include <iostream>
//#include "Class.hh"
#include <time.h>
#include "TypesOfTables.hh"

/**************************************************************************************************/
int main() {
    std::srand( time(NULL));
    Tables5 TabsToSort; //Tablice do posortowania
    TabsToSort.Show();
    TabsToSort.QuickSort(1);
    std::cout<<std::endl;
   TabsToSort.Show();
   std::cin.get();
    return 0;

}