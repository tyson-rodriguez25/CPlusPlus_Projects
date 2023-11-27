#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "MyArray.h"
#define MAX_ARRAY_SIZE	1000


using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif


int main(int argc, char * argv[])
{
	VS_MEM_CHECK;

	if (argc < 3)
	{
		cout << "Please provide name of input and output files" << endl;
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "Unable to open " << argv[1] << " for input" << endl;
		return 1;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cout << "Unable to open " << argv[2] << " for output" << endl;
	}
	out.close();

	MyArray<int> numbers(MAX_ARRAY_SIZE);

	int i;
	while (in >> i)
	{
		numbers.push_back(i);
	}

	out.open(argv[2]);

	out << "My Array" << endl;
	MyArray<int>::Iterator iter = numbers.begin();
	int line = 0;
	for (; iter != numbers.end(); ++iter)
	{
		out << *iter << ' ';
		line++;
		if (line == 10)
		{
			out << endl;
			line = 0;
		}
	}
	out << endl;
	


	out << "SEQUENTIAL" << endl;
	MyArray<int>::Iterator iter1 = numbers.begin();
	out << "iter1: " << iter1 << endl;
	for (; iter1 != numbers.end(); ++iter1)
		out << *iter1 << ' ';
	out << endl << endl;

	out << "PRIME" << endl;
	MyArray<int>::Iterator iter2 = numbers.begin(PRIME);
	out << "iter2: " << iter2 << endl;
	for (; iter2 != numbers.end(); ++iter2)
		out << *iter2 << ' ';
	out << endl << endl;

	out << "COMPOSITE" << endl;
	MyArray<int>::Iterator iter3 = numbers.begin(COMPOSITE);
	out << "iter3: " << iter3 << endl;
	for (; iter3 != numbers.end(); ++iter3)
		out << *iter3 << ' ';
	out << endl << endl;

	out << "FIBINOCCI" << endl;
	MyArray<int>::Iterator iter4 = numbers.begin(FIB);
	out << "iter4: " << iter4 << endl;
	for (; iter4 != numbers.end(); ++iter4)
		out << *iter4 << "=" << iter4[-2] << "+" << iter4[-1] << ' ';
	out << endl << endl;
	return 0;

}