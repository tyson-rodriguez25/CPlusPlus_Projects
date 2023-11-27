#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include <string>
#include "QSInterface.h"
using namespace std;

template<typename T>
class Quicksort : public QSInterface<T>
{
private:
	int* myArray;
	size_t arrayCapacity;
	size_t numItems;
	int firstElement = 0;
	int middleElement = 0;
	int lastElement = 0;
	

public:
	Quicksort() {
		myArray = new int[5];
	}
	~Quicksort() {
		delete[] myArray;
	}

	//Creates an array
	virtual bool createArray(size_t capacity) {
		delete[] myArray;
		myArray = new int[capacity];
		numItems = 0;
		arrayCapacity = capacity;
		return 1;
	}

	// Adds things to the Array and Dynamically Allocates
	virtual bool addElement(T element) {
		if (numItems == arrayCapacity) {
			int* newArray = new int[arrayCapacity * 2];
			for (int i = 0; i < arrayCapacity;i++) {
				newArray[i] = myArray[i];
			}
			int* temp;
			temp = myArray;
			myArray = newArray;
			myArray[numItems] = element;
			++numItems;
			delete[] temp;
			arrayCapacity = arrayCapacity * 2;
		}
		else {
			myArray[numItems] = element;
			++numItems;
		}
		return true;
	}

	// Sorts from the left index to the right index
	virtual bool sort(size_t left, size_t right) {
		if (right - left > 1) {
			int pivot = medianOfThree(left, right);
			int down = partition(left, right, pivot);

			sort(left, down);
			sort(down + 1, right);
			return 1;
		}
		return 0;
	}

	// Sorts all the numbers in the array
	virtual bool sortAll() {
		sort(0, numItems);
		return 1;
	}

	// Clears the Array
	virtual bool clear() {
		numItems = 0;
		return 1;
	}

	// Outputs the Capacity
	virtual size_t capacity() const {
		return arrayCapacity;
	}

	//Outputs the Size
	virtual size_t size() const {
		return numItems;
	}

	// Finds the Median of Three from a left and right index
	virtual int medianOfThree(size_t left, size_t right) {
		if (numItems == 0) {
			return -1;
		}
		else if (left < 0 || right > arrayCapacity + 1) {
			return -1;
		}
		else if (!(left < right)) {
			return -1;
		}
	
		middleElement = ((left + right) / 2);
		if (myArray[left] > myArray[middleElement]) {
			int temp;
			temp = myArray[left];
			myArray[left] = myArray[middleElement];
			myArray[middleElement] = temp;
			
		}
		if (myArray[middleElement] > myArray[right - 1]) {
			int temp;
			temp = myArray[middleElement];
			myArray[middleElement] = myArray[right - 1];
			myArray[right - 1] = temp;
			
		}
		if (myArray[left] > myArray[right - 1]) {
			int temp;
			temp = myArray[left];
			myArray[left] = myArray[right-1];
			myArray[right-1] = temp;
			
		}
		if (myArray[left] > myArray[middleElement]) {
			int temp;
			temp = myArray[left];
			myArray[left] = myArray[middleElement];
			myArray[middleElement] = temp;
		}

		return middleElement;
	}

	// Partitions numbers that are left and right of the pivot Index
	virtual int partition(size_t left, size_t right, size_t pivotIndex) {
		if (numItems == 0) {
			return -1;
		}
		else if (left < 0 || right > arrayCapacity + 1) {
			return -1;
		}
		else if (!(left < right)) {
			return -1;
		}
		else if (right == (left + 1)) {
			return -1;
		}
		int leftIndex = left;
		int rightIndex = right - 1;
		
		int temp = myArray[pivotIndex];
		myArray[pivotIndex] = myArray[leftIndex];
		myArray[leftIndex] = temp;
		
		int up = left + 1;
		int down = right - 1;
		
		while (true) {
				while (myArray[up] <= myArray[leftIndex] && up != rightIndex) {
					++up;
				}
				while (myArray[down] > myArray[leftIndex] && down != leftIndex) {
					--down;
				}
				if (up < down) {
					int temp = myArray[down];
					myArray[down] = myArray[up];
					myArray[up] = temp;
				}
				else {
					int temp = myArray[down];
					myArray[down] = myArray[leftIndex];
					myArray[leftIndex] = temp;
					break;
				}
		}

		return down;
	}

	// Outputs the Array
	virtual std::string toString() const {
		ostringstream out;
		if (numItems == 0) {
			out << "Empty";
		}
		for (int i = 0; i < numItems; ++i) {
			out << myArray[i] << ",";
		}
		return out.str();
	}
};

#endif