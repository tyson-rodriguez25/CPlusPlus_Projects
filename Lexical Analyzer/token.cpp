#include "token.h"
#include <string>
#include <sstream>
using namespace std;

Token::Token(tokenType type, string extracted, int line) {
	this->type = type;
	this->extracted = extracted;
	this->line = line;
}

Token::~Token() {
}

string Token::toString() {
	stringstream ss;
	ss << this->line;
	return "(" + this->tokenString[this->type] + ",\"" + this->extracted + "\"," + ss.str() + ")";
}