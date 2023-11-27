#ifndef RULE
#define RULE

#include "predicate.h"
using namespace std;

class rule {
public:
	rule() {};
	~rule() { clear(); };

	string toString();
	void addBCPredicate(predicate* predicate);
	void addBCParameter(parameter* parameter);
	void addACPredicate(predicate* predicate);
	void addACParameter(parameter* parameter, int pos);
	predicate* getBCPredicate();
	vector<predicate*> getACPredicates();
	predicate* getACPredicate(int i);
	void clear();

private:
	predicate* beforeColon;
	vector<predicate*> afterColon;
};

#endif