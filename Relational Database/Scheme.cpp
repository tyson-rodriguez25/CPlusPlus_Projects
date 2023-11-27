#include "Scheme.h"

void scheme::addAttributeName(string attributeName) {
	attributeNames.push_back(attributeName);
	return;
}

void scheme::addAttributeNames(vector<string> allNames) {
	attributeNames = allNames;
	return;
}

string scheme::getAttributeName(int position) {
	return attributeNames[position];
}

vector<string> scheme::getAttributeNames() {
	return attributeNames;
}