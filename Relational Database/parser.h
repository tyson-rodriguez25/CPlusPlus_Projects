#ifndef PARSER
#define PARSER

#include "token.h"
#include "datalogProgram.h"

#include <vector>
#include <fstream>
using namespace std;

class parser {
public:
	parser(vector<token*> dataLog) :dataLog(dataLog), error(nullptr) {};
	~parser() { clear(); };

	void parseDatalogProgram();
	bool parseSchemeList();
	bool parseFactList();
	bool parseRuleList();
	bool parseQueryList();
	bool parseScheme();
	bool parseFact();
	bool parseRule();
	bool parseQuery();
	bool parseHeadPredicate();
	bool parsePredicate();
	bool parsePredicateList();
	bool parseParameterList();
	bool parseStringList();
	bool parseIDList();
	bool parseParameter();
	bool parseExpression();
	bool parseOperators();

	bool match(string check);
	void printOutput(string outputFile);
	string makeExpression(string soFar);
	void removeComments();
	void clear();
	datalogProgram getDatalogProgram();

private:
	vector<token*> dataLog;
	int parsePosition;
	int expressionIncriment;
	datalogProgram output;
	token* error;
};

#endif