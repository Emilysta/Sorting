#pragma once
template < typename T>
void issorted(T tableToSort, int first, int last) { //information only when array isn't sorted
	int size = last - first + 1;
	bool sorted = true;
	for (int i = 0; i < size-1; ++i) {
		if (tableToSort[i] > tableToSort[i + 1]) {
			sorted = false;
		}
	}
	switch (sorted) {
	case true: {
		//std::cout << "Array sorted\n";
		break;
	}
	case false: {
		std::cout << "Array not sorted\n";
		break;
	}
	}
}

template <typename T>
void isreversesorted(T tableToSort, int first, int last) { //information only when array isn't sorted
	int size = last - first + 1;
	bool sorted = true;
	for (int i = 0; i < size - 1; ++i) {
		if (tableToSort[i] < tableToSort[i + 1]) {
			sorted = false;
		}
	}
	switch (sorted) {
	case true: {
		//std::cout << "Array sorted\n"; 
		break;
	}
	case false: {
		std::cout << "Array not sorted\n";
		break;
	}
	}
}
