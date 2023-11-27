#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Quicksort.h"
using namespace std;


#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[]) {
	VS_MEM_CHECK

		if (argc < 3)
		{
			cerr << "Please provide name of input and output files";
			return 1;
		}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 1;
	}
	cout << "output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
	}

	int element = 0;
	int arraySize = 0;
	int firstIndex = 0;
	int secondIndex = 0;
	int left = 0;
	int right = 0;
	int pivotIndex = 0;
	string line;
	Quicksort<int> myArray;

	// Takes in Commands
	for (string command; in >> command;) {

		if (command == "QuickSort") {
			in >> arraySize;
			out << "QuickSort " << arraySize;
			
			if (myArray.createArray(arraySize)) {
				out << " OK" << endl;
			}
			else {
				out << " Error" << endl;
			}
		}

		if (command == "AddToArray") {
			out << "AddToArray ";
			getline(in, line);
			istringstream iss(line);
			while(iss >> element) {
				element = element;
				out << element << ",";
				myArray.addElement(element);
			}
			out << " OK" << endl;
		}

		if (command == "Capacity") {
			out << "Capacity " << myArray.capacity() << endl;
		}

		if (command == "Clear") {
			out << "Clear";
			if (myArray.clear()) {
				out << " OK" << endl;
			}
			else {
				out << " Error" << endl;
			}
		}

		if (command == "Size") {
			out << "Size ";
			out << myArray.size() << endl;
		}

		if (command == "Sort") {
			out << "Sort ";
			in >> left >> right;
			out << left << "," << right;
			if (myArray.sort(left, right)) {
				out << " OK" << endl;
			}
			else {
				out << " ERROR" << endl;
			}

		}

		if (command == "SortAll") {
			out << "SortAll ";
			if (myArray.sortAll()) {
				out << "OK" << endl;
			}
			else {
				out << "ERROR" << endl;
			}
		}

		if (command == "MedianOfThree") {
			out << "MedianOfThree ";
			in >> firstIndex >> secondIndex;
			out << firstIndex << "," << secondIndex << " = ";
			out << myArray.medianOfThree(firstIndex, secondIndex) << endl;
		}

		if (command == "Partition") {
			out << "Partition ";
			in >> left >> right >> pivotIndex;
			out << left << "," << right << "," << pivotIndex;
			out << " = " << myArray.partition(left, right, pivotIndex) << endl;
		}

		if (command == "PrintArray") {
			out << "PrintArray " << myArray.toString() << endl;

		}
	}

	return 0;
}