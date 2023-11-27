#include "datalogProgram.h"

string datalogProgram::toString(token* error) {
	string temp;

	if (error != nullptr) {
		temp += "Failure!\n  ";
		temp += error->printToken();
		return temp;
	}
	else
		temp += "Success!\n";

	temp += "Schemes(";
	temp += to_string(schemes.size());
	temp += "):\n";

	for (int i = 0; i < schemes.size(); i++) {
		temp += "  ";
		temp += schemes[i]->toString();
		temp += "\n";
	}

	temp += "Facts(";
	temp += to_string(facts.size());
	temp += "):\n";

	for (int i = 0; i < facts.size(); i++) {
		temp += "  ";
		temp += facts[i]->toString();
		temp += "\n";
	}

	temp += "Rules(";
	temp += to_string(rules.size());
	temp += "):\n";

	for (int i = 0; i < rules.size(); i++) {
		temp += "  ";
		temp += rules[i]->toString();
		temp += "\n";
	}

	temp += "Queries(";
	temp += to_string(queries.size());
	temp += "):\n";

	for (int i = 0; i < queries.size(); i++) {
		temp += "  ";
		temp += queries[i]->toString();
		temp += "\n";
	}

	sort(domain.begin(), domain.end());
	temp += "Domain(";
	temp += to_string(domain.size());
	temp += "):";

	for (int i = 0; i < domain.size(); i++) {
		temp += "\n  ";
		temp += domain[i];
	}

	return temp;
}

void datalogProgram::addScheme(predicate* scheme) {

	schemes.push_back(scheme);
	return;
}

void datalogProgram::addFact(predicate* fact) {
	facts.push_back(fact);
	return;
}

void datalogProgram::addRule(rule* rule) {
	rules.push_back(rule);
	return;
}

void datalogProgram::addQuery(predicate* query) {
	queries.push_back(query);
	return;
}

void datalogProgram::addDomain(string string) {
	if (find(domain.begin(), domain.end(), string) == domain.end())
		domain.push_back(string);
	return;
}

void datalogProgram::addSchemeParameter(parameter* parameter, int pos) {
	schemes[pos]->addParameter(parameter);
	return;
}

void datalogProgram::addFactParameter(parameter* parameter, int pos) {
	facts[pos]->addParameter(parameter);
	return;
}

void datalogProgram::addBCRulePredicate(predicate* predicate, int pos) {
	rules[pos]->addBCPredicate(predicate);
}

void datalogProgram::addBCRuleParameter(parameter* parameter, int pos) {
	rules[pos]->addBCParameter(parameter);
}

void datalogProgram::addACRulePredicate(predicate* predicate, int pos) {
	rules[pos]->addACPredicate(predicate);
	return;
}

void datalogProgram::addACRuleParameter(parameter* parameter, int rulePos, int predPos) {
	rules[rulePos]->addACParameter(parameter, predPos);
	return;
}

void datalogProgram::addQueryParameter(parameter* parameter, int pos) {
	queries[pos]->addParameter(parameter);
	return;
}

predicate* datalogProgram::getScheme(int position) {
	return schemes[position];
}

predicate* datalogProgram::getFact(int position) {
	return facts[position];
}

rule* datalogProgram::getRule(int position) {
	return rules[position];
}

predicate* datalogProgram::getQuery(int position) {
	return queries[position];
}

int datalogProgram::getSchemeSize() {
	return schemes.size();
}

int datalogProgram::getFactSize() {
	return facts.size();
}

int datalogProgram::getRuleSize() {
	return rules.size();
}

int datalogProgram::getQuerySize() {
	return queries.size();
}

void datalogProgram::clear() {
	for (int i = 0; i < schemes.size(); i++)
		delete schemes[i];

	for (int i = 0; i < facts.size(); i++)
		delete facts[i];

	for (int i = 0; i < rules.size(); i++)
		delete rules[i];

	for (int i = 0; i < queries.size(); i++)
		delete queries[i];

	schemes.clear();
	facts.clear();
	rules.clear();
	queries.clear();
	domain.clear();
}