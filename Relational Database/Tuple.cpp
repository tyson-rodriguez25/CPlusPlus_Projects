#include "Tuple.h"

void Tuple::addAttribute(string attribute) {
	attributes.push_back(attribute);
	return;
}

void Tuple::addAttributes(vector<string> newAttributes) {
	attributes = newAttributes;
	return;
}

string Tuple::getAttribute(int position) {
	return attributes[position];
}

vector<string> Tuple::getAttributes() {
	return attributes;
}