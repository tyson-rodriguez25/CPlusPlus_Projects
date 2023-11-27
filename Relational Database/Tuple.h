#ifndef TUPLE
#define TUPLE

#include <vector>
using namespace std;

class Tuple {
public:
	Tuple() {};
	~Tuple() {};

	void addAttribute(string attribute);
	void addAttributes(vector<string> newAttributes);
	string getAttribute(int position);
	vector<string> getAttributes();
private:
	vector<string> attributes;
};

#endif