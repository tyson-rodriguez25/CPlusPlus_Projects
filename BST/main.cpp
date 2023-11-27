#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "BST.h"
#include "BSTInterface.h"
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
	BST<int> node;
	string command, item2;
	
	for (string command; in >> command;) {
		// Calls the addNode function
		if (command == "Add") {
			in >> item2;
			out << "Add " << item2 << " ";
			out << boolalpha << node.addNode(stoi(item2)) << endl;
		}
		
		// Calls the removeNode function
		else if (command == "Remove") {
			in >> item2;
			out << "Remove " << item2 << " ";
			out << boolalpha << node.removeNode(stoi(item2)) << endl;
		}

		// Calls the clearTree function
		else if (command == "Clear") {
			out << "Clear ";
			out << boolalpha << node.clearTree() << endl;
		}

		// Calls the toString function
		else if (command == "PrintBST") {
			out << "PrintBST";
			out << node.toString() << endl;
		}
	}

	return 0;
}