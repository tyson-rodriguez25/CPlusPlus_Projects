#include "predicate.h"

int predicate::getParameterSize() {
	return parameters.size();
}

parameter* predicate::getParameter(int position) {
	return parameters[position];
}

string predicate::toString() {
	string temp;

	temp += ID;
	temp += "(";

	for (int i = 0; i < parameters.size(); i++) {

		temp += parameters[i]->getValue();
		if (i != parameters.size() - 1)
			temp += ",";
	}

	temp += ")";

	if (type == "FACTS")
		temp += ".";
	else if (type == "QUERIES")
		temp += "?";

	return temp;
}

void predicate::addParameter(parameter* parameter) {
	parameters.push_back(parameter);
	return;
}

string predicate::getType() {
	return type;
}

string predicate::getID() {
	return ID;
}

void predicate::clear() {
	for (int i = 0; i < parameters.size(); i++) {
		if (parameters[i] != nullptr)
			delete parameters[i];
	}

	parameters.clear();
	return;
}