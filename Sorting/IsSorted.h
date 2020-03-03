#pragma once
template < typename T>
void issorted(T tableToSort, int first, int last) {
	int size = last - first + 1;
	bool Sorted = true;
	for (int i = 0; i < size - 1; ++i) {
		//std::cout << arr[i] << std::endl;
		if (tableToSort[i] > tableToSort[i + 1]) {
			Sorted = false;
		}
	}
	std::cout << "size:" << size << "\t";
	switch (Sorted) {
	case true: {
		std::cout << "Array sorted\n";
		break;
	}
	case false: {
		std::cout << "Array not sorted\n";
		break;
	}
	}
}