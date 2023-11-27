#ifndef SCHEME
#define SCHEME

#include <string>
#include <vector>
using namespace std;

class scheme {
public:
	scheme() {};
	~scheme() {};

	void addAttributeName(string attributeName);
	void addAttributeNames(vector<string> allNames);
	string getAttributeName(int position);
	vector<string> getAttributeNames();
private:
	vector<string> attributeNames;
};

#endif