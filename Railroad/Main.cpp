//typename unsigned int size_t;

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "DequeInterface.h"
#include "Deque.h"
#include "Vector.h"
#include "Queue.h"
#include "Stack.h"
#include "Station.h"

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
	
	Station<size_t> railroad;
	int data;
	// Checks what command is being read in
	for (string command; in >> command;) {
		try {
			if (command == "Add:station") {
				in >> data;
				out << command << " " << data << " " << railroad.addCar(data);
			}
			else if (command == "Add:queue") {
				out << command << " " << railroad.addQueue();
			}
			else if (command == "Add:stack") {
				out << command << " " << railroad.addStack();
			}
			else if (command == "Remove:station") {
				out << command << " " << railroad.removeCar();
			}
			else if (command == "Remove:queue") {
				out << command << " " << railroad.removeQueue();
			}
			else if (command == "Remove:stack") {
				out << command << " " << railroad.removeStack();
			}
			else if (command == "Top:queue") {
				out << command << " " << railroad.topQueue();
			}
			else if (command == "Top:stack") {
				out << command << " " << railroad.topStack();
			}
			else if (command == "Size:queue") {
				out << command << " " << railroad.sizeQueue();
			}
			else if (command == "Size:stack") {
				out << command << " " << railroad.sizeStack();
			}
			else if (command == "Train:") {
				out << command << " " << railroad.toString() << endl;
			}
			else throw command;
		}
		catch (string error) {
			out << error << " ** Undefined " << error << endl;
		}
	}
	return 0; 
}