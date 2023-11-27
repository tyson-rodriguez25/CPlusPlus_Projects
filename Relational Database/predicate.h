#ifndef PREDICATE
#define PREDICATE

#include "parameter.h"

#include <vector>
using namespace std;

class predicate {
public:
	predicate(string type, string ID) : type(type), ID(ID) {};
	~predicate() { clear(); };

	int getParameterSize();
	parameter* getParameter(int position);
	string toString();
	string getType();
	string getID();
	void addParameter(parameter* parameter);
	void clear();

private:
	string type;
	string ID;
	vector<parameter*> parameters;
};

#endif