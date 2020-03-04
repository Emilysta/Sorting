#include <iostream>
#include <time.h>
#include "TypesOfTables.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
void menu() {
    std::cout << "1.Quicksort\n";
    std::cout << "2.Mergesort\n";
    std::cout << "3.Heapsort\n";
	std::cout << "4.Introsort\n";
    std::cout << "5.End\n";
}

/**************************************************************************************************/
int main() {
    std::srand( (unsigned int)(time(nullptr)) );
    Tables1M TabsToSort; //to sort
    //TabsToSort.Show();
    //TabsToSort.Generate();
    
    int option;
    menu();
    std::cout << "Choose an option: ";
    std::cin >> option;

    while (option != 5) {
        switch (option)
        {
        case 1: {
            TabsToSort.QuickSort();
			TabsToSort.isSorted();
            std::cout << std::endl;
            break;
            }
        case 2: {
            TabsToSort.MergeSort();
			TabsToSort.isSorted();
            std::cout << std::endl;
            break;
            }
        case 3: {
            TabsToSort.HeapSort();
			TabsToSort.isSorted();
            std::cout << std::endl;
            break;
            }
		case 4: {
			TabsToSort.IntroSort();
			TabsToSort.isSorted();
			std::cout << std::endl;
			break;
		}
        case 5: break;
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