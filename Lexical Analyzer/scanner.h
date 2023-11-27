#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include "token.h"
using namespace std;

#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
public:
	Scanner(istream* in);
	~Scanner();
	vector<Token*> lexicalAnalyzer();
private:
	vector<Token*> tokens;
	Token* Eat_string();
	Token* line_comment();
	Token* block_comment();
	Token* alpha_numeric();
	map<string, tokenType> keyword = { { "Schemes", SCHEMES },{ "Facts", FACTS },{ "Rules", RULES },{ "Queries", QUERIES } };
	int line = 1;
	istream* in;
};

#endif

