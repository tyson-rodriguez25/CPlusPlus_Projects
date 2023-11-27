#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include "scanner.h"
#include "token.h"
#include "parser.h"
#include "datalogProgram.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc > 0) {
		for (int i = 1;i <= 10;++i) {
			string filename = "Test_" + to_string(i) + ".txt";
			ifstream file;
			cout << filename << endl;
			file.open(filename);
			if (!file.good()) {
				cout << "File '" << filename << "' could not be opened." << endl;
				return 1;
			}
			Scanner scanner = Scanner(&file);
			vector<Token*> tokens = scanner.lexicalAnalysis();
			Parser parser = Parser(tokens);
			DatalogProgram* parsedProgram = parser.datalogParsing();
			cout << parsedProgram->toString();
			file.close();
			delete parsedProgram;
		}
	}

	return 0;
}
	