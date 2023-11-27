#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include<conio.h>
#include "token.h"
#include "scanner.h"
#include "datalogProgram.h"
#include "parser.h"
#include "Database.h"
using namespace std;


#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

int main(int argc, char* argv[]) {
	VS_MEM_CHECK
		if (argc > 0) {
				string filename = string(argv[1]); // Edited
				ifstream file;
				file.open(filename);
				if (!file.good()) {
					cout << "File '" << filename << "' could not be opened." << endl;
					return 1;
				}

				scanner* mainScanner = new scanner();
				mainScanner->setInfile(filename);
				mainScanner->scan();

				parser* mainParser = new parser(mainScanner->getList());
				mainParser->parseDatalogProgram();

				database* mainDatabase = new database();
				mainDatabase->evaluateDatalog(mainParser->getDatalogProgram());
				delete mainDatabase;
				delete mainParser;
				delete mainScanner;
		}
	system("Pause");
	return 0;
}