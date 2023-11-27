#ifndef DATABASE
#define DATABASE

#include "relation.h"
#include "datalogProgram.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class database {
public:
	database() {};
	~database() { clear(); };

	void evaluateDatalog(datalogProgram datalog);
	void evaluateSchemes(datalogProgram datalog);
	void evaluateFacts(datalogProgram datalog);
	string evaluateQuery(predicate* query);
	string evaluateRule(rule* rule);

	void clear();
private:
	vector<relation*> relations;
};

#endif