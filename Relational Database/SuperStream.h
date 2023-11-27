#pragma once
#include <string>

using namespace std;

class SuperStream {
public:
	string stream;
	int lineNum;
	int index;

	SuperStream(string stream, int lineNum);
	virtual ~SuperStream();
	int getLineNum();
	char peek();
	char superPeek();
	char getChar();
	char proceed();
};