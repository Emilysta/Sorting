#include <iostream>
#include <time.h>
#include "TypesOfTables.h"

void menu() {
    std::cout << "1.Quicksort\n";
    std::cout << "2.Mergesort\n";
    std::cout << "3.Introsort\n";
    std::cout << "4.End\n";
}

/**************************************************************************************************/
int main() {
    std::srand( time(nullptr) );
    Tables10 TabsToSort; //Tablice do posortowania
    TabsToSort.Show();
    //std::cout<<std::endl;
    
    int option;
    menu();
    std::cout << "Choose an option: ";
    std::cin >> option;

    while (option != 4) {
        switch (option)
        {
        case 1: {
            TabsToSort.QuickSort();
            TabsToSort.Show();
            std::cout << std::endl;
            break;
            }
        case 2: {
            TabsToSort.MergeSort();
            TabsToSort.Show();
            std::cout << std::endl;
            break;
            }
        case 3: {
            TabsToSort.QuickSort();
            TabsToSort.Show();
            std::cout << std::endl;
            break;
            }
        case 4: break;
        default: {
            std::cout << "Wrong option! ";
            break;
            }

        }
        menu();
        std::cout << "Choose again: ";
        std::cin >> option;
    }
    return 0;
}