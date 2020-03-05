#include <iostream>
#include <time.h>
#include "TypesOfTables.h"
#include "Driver.h"
#include "Times.h"
void menu2() {
    std::cout << "1.Quicksort\n";
    std::cout << "2.Mergesort\n";
    std::cout << "3.Heapsort\n";
	std::cout << "4.Introsort\n";
    std::cout << "0.End\n";
}
void menu1() {
    std::cout << "1.Test\n";
    std::cout << "2.Times\n";
    std::cout << "3.TestOnOneArray\n";
    std::cout << "0.End\n";
}

/**************************************************************************************************/
int main() {
    std::srand( (unsigned int)(time(nullptr)) );
    int exit;
    int exit2;
    do {
        menu1();
        std::cout << "choose:";
        std::cin >> exit;
		system("cls");
        switch (exit) {
        case 1: Driver();
            break;
        case 2: Times();
            break;
        case 3: {
            do {
                Tables1M TabsToSort;
                menu2();
                std::cout << "choose:";
                std::cin >> exit2;
                switch (exit2)
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
                case 0: break;
                default: {
                    std::cout << "Wrong option! ";
                    break;
                }
                       break;
				} 
            } while (exit2 != 0);
			system("cls");
            break;
        }
        case 0: {
            std::cout << "Ending program...";
            break;
        }
        default: {
            std::cout << "Wrong option! ";
            break;
        }
        }
    } while (exit != 0);
    return 0;
}