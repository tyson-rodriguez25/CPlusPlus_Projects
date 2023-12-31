#ifndef RULE_H_
#define RULE_H_

#include <string>
#include <vector>

#include "Token.h"
#include "Predicate.h"

using namespace std;

class Rule {
public:
	Rule(Predicate predicate) {
		this->predicate = predicate;
	}
	~Rule() {}
	Predicate getHeadPredicate() {
		return predicate;
	}
	vector<Predicate> getPredicateList() {
		return predicateList;
	}
	void setPredicateList(vector<Predicate> predicateList) {
		this->predicateList = predicateList;
	}
	string toString();
private:
	Predicate predicate;
	vector<Predicate> predicateList;
};

#endif /* RULE_H_ */