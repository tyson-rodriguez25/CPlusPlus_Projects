#ifndef PREDICATE_H
#define PREDICATE_H

#include <vector>
#include "token.h"
#include "parameter.h"

class Predicate {
public:
	Predicate(Token* id);
	~Predicate();
	void addParameter(Parameter* parameter);
	string toString();

	Token* id;
	vector<Parameter*> parameterList;
};

#endif