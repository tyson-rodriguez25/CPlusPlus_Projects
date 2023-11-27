#include "token.h"

string token::getType() {
	return type;
}

string token::getValue() {
	return value;
}

int token::getLine() {
	return line;
}

string token::printToken() {
	string temp;
	temp = "(" + type + "," + "\"" + value + "\"," + to_string(line) + ")";
	return temp;
}