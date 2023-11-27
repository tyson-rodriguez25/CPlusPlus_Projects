#ifndef TOKEN
#define TOKEN

#include <string>
using namespace std;

class token {
public:
	token(string type, string value, int line) : type(type), value(value), line(line) {};
	~token() {};

	string getType();
	string getValue();
	int getLine();
	string printToken();

private:
	string type;
	string value;
	int line;
};

#endif 