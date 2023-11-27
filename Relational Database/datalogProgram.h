#ifndef DATALOGPROGRAM
#define DATALOGPROGRAM

#include "predicate.h"
#include "rule.h"
#include "token.h"

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class datalogProgram {
public:
	datalogProgram() {};
	~datalogProgram() {};

	string toString(token* error);
	void addScheme(predicate* scheme);
	void addFact(predicate* fact);
	void addRule(rule* rule);
	void addQuery(predicate* query);
	void addDomain(string string);

	void addSchemeParameter(parameter* parameter, int pos);
	void addFactParameter(parameter* parameter, int pos);
	void addBCRulePredicate(predicate* predicate, int pos);
	void addBCRuleParameter(parameter* parameter, int pos);
	void addACRulePredicate(predicate* predicate, int pos);
	void addACRuleParameter(parameter* parameter, int rulePos, int predPos);
	void addQueryParameter(parameter* parameter, int pos);

	predicate* getScheme(int position);
	predicate* getFact(int position);
	rule* getRule(int position);
	predicate* getQuery(int position);
	int getSchemeSize();
	int getFactSize();
	int getRuleSize();
	int getQuerySize();

	void clear();

private:
	vector<predicate*> schemes;
	vector<predicate*> facts;
	vector<rule*> rules;
	vector<predicate*> queries;

	vector<string> domain;
};

#endif