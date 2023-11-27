#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include "scanner.h"
#include "token.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc > 0) {
		string filename = string(argv[1]);
		ifstream file;
		file.open(filename);
		if (!file.good()) {
			cout << "File '" << filename << "' could not be opened." << endl;
			return 0;
		}
		Scanner scanner = Scanner(&file);
		vector<Token*> tokens = scanner.lexicalAnalyzer();
		for (unsigned int i = 0; i < tokens.size(); i++) {
			cout << tokens[i]->toString() << endl;
			delete tokens[i];
		}
		cout << "Total Tokens = " << tokens.size() << endl;
		tokens.clear(); // EDITED
	}
	system("Pause");
	return 0;
}