#ifndef PARAMETER
#define PARAMETER

#include <string>
using namespace std;

class parameter {
public:
	parameter(string type, string value) : type(type), value(value) {};
	~parameter() {};

	string getType();
	string getValue();

private:
	string type;
	string value;
};

#endif