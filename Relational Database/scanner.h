#ifndef SCANNER
#define SCANNER

#include "token.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class scanner {
public:
	scanner() : currentLine(1) {};
	~scanner() { clearList(); };

	void scan();
	void addToken();
	void setInfile(string fileName);
	void printList(string fileName);
	void clearList();

	vector<token*> getList();

private:
	ifstream infile;
	vector<token*> list;
	int currentLine;
};

#endif