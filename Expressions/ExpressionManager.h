#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H
using std::string;
using std::ostream;

class ExpressionManager : public ExpressionManagerInterface {
private:
	string Expression;
	std::vector<string> inFix;
	std::vector<string> postFix;
	string operators = "([{ -+ */%";

public:
	ExpressionManager() { }
	ExpressionManager(string exp) : Expression(exp) { }
	~ExpressionManager() { }

	virtual int value(void);

	virtual string InFix(void);
	virtual string PostFix(void);
	virtual string PreFix(void);
	virtual string ToString(void);

};
