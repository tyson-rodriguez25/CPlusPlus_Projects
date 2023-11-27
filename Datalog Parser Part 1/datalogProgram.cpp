#include "datalogProgram.h"

DatalogProgram::DatalogProgram() {
	this->errorToken = NULL;
}

DatalogProgram::~DatalogProgram() {
	for (unsigned int i = 0; i < this->schemes.size(); i++) {
		delete this->schemes[i];
	}
	for (unsigned int i = 0; i < this->facts.size(); i++) {
		delete this->facts[i];
	}
	for (unsigned int i = 0; i < this->rules.size(); i++) {
		delete this->rules[i];
	}
	for (unsigned int i = 0; i < this->queries.size(); i++) {
		delete this->queries[i];
	}
	delete this->errorToken;
}

void DatalogProgram::addScheme(Predicate* scheme) {
	this->schemes.push_back(scheme);
}

void DatalogProgram::addFact(Predicate* fact) {
	this->facts.push_back(fact);
}

void DatalogProgram::addRule(Rule* rule) {
	this->rules.push_back(rule);
}

void DatalogProgram::addQuery(Predicate* query) {
	this->queries.push_back(query);
}

void DatalogProgram::addDomainValue(string domainValue) {
	bool found = false;
	for (unsigned int i = 0; i < this->domain.size(); i++) {
		if (domain[i] == domainValue) {
			found = true;
			break;
		}
	}

	if (!found) this->domain.push_back(domainValue);
}

void DatalogProgram::setError(Token* errorToken) {
	this->errorToken = errorToken;
}

string DatalogProgram::toString() {
	if (this->errorToken != NULL) return "Failure!\n  " + this->errorToken->toString() + "\n\n";

	string output = "Success!\n\n";
	return output;
}

void DatalogProgram::sortDomain() {
	sort(this->domain.begin(), this->domain.end());
}
