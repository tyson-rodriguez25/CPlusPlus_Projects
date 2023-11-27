#include "scanner.h"

void scanner::setInfile(string fileName) {
	infile.open(fileName);
	return;
}

void scanner::scan() {
	while (infile.peek() != EOF) {
		if (infile.peek() == '\n') {
			infile.get();
			currentLine++;
		}
		else
			addToken();
	}
	currentLine++;
	list.push_back(new token("EOF", "", currentLine));
}

void scanner::addToken() {
	char c = infile.get();

	string temp = "";
	char a;
	int tempLine;
	bool foundEnd;

	switch (c) {

	case ' ':
		break;

	case ',':
		list.push_back(new token("COMMA", ",", currentLine));
		break;

	case '.':
		list.push_back(new token("PERIOD", ".", currentLine));
		break;

	case '?':
		list.push_back(new token("Q_MARK", "?", currentLine));
		break;

	case '(':
		list.push_back(new token("LEFT_PAREN", "(", currentLine));
		break;

	case ')':
		list.push_back(new token("RIGHT_PAREN", ")", currentLine));
		break;

	case ':':
		if (infile.peek() == '-') {
			infile.get();
			list.push_back(new token("COLON_DASH", ":-", currentLine));
		}
		else
			list.push_back(new token("COLON", ":", currentLine));
		break;

	case '*':
		list.push_back(new token("MULTIPLY", "*", currentLine));
		break;

	case '+':
		list.push_back(new token("ADD", "+", currentLine));
		break;

	case '\'':
		temp.push_back(c);
		foundEnd = false;
		tempLine = currentLine;

		while (!foundEnd && infile.peek() != EOF) {
			a = infile.get();
			if (a == '\n')
				currentLine++;
			else if (a == '\'' && infile.peek() != '\'')
				foundEnd = true;
			else if (a == '\'' && infile.peek() == '\'') {
				temp.push_back(a);
				a = infile.get();
			}
			temp.push_back(a);
		}
		if (foundEnd)
			list.push_back(new token("STRING", temp, tempLine));
		else {
			temp.push_back('\n');
			list.push_back(new token("UNDEFINED", temp, tempLine));
		}
		break;

	case '\t':
		break;

	case '#':
		if (infile.peek() == '|') {
			temp.push_back(c);
			a = infile.get();
			foundEnd = false;
			tempLine = currentLine;

			temp.push_back(a);
			while (!foundEnd && infile.peek() != EOF) {
				a = infile.get();
				if (a == '\n')
					currentLine++;
				else if (a == '|' && infile.peek() == '#') {
					foundEnd = true;
					temp.push_back(a);
					a = infile.get();
				}
				temp.push_back(a);
			}
			if (foundEnd)
				list.push_back(new token("COMMENT", temp, tempLine));
			else
				list.push_back(new token("UNDEFINED", temp, tempLine));
		}
		else {
			temp.push_back(c);
			while (infile.peek() != '\n') {
				a = infile.get();
				temp.push_back(a);
			}
			list.push_back(new token("COMMENT", temp, currentLine));
		}
		break;

	default:
		temp.push_back(c);
		bool ID = false;
		if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
			while ((infile.peek() <= 'z' && infile.peek() >= 'a') || (infile.peek() <= 'Z' && infile.peek() >= 'A') || (infile.peek() <= '9' && infile.peek() >= '0')) {
				a = infile.get();
				temp.push_back(a);
			}
			ID = true;
		}
		if (temp == "Schemes")
			list.push_back(new token("SCHEMES", temp, currentLine));
		else if (temp == "Facts")
			list.push_back(new token("FACTS", temp, currentLine));
		else if (temp == "Rules")
			list.push_back(new token("RULES", temp, currentLine));
		else if (temp == "Queries")
			list.push_back(new token("QUERIES", temp, currentLine));
		else if (ID)
			list.push_back(new token("ID", temp, currentLine));
		else
			list.push_back(new token("UNDEFINED", temp, currentLine));
		break;
	}
}

void scanner::printList(string fileName) {
	ofstream outfile;
	outfile.open(fileName);

	for (int i = 0; i < list.size(); i++) {
		outfile << list[i]->printToken();
		outfile << "\n";
	}
	outfile << "Total Tokens = " << to_string(list.size());
}

void scanner::clearList() {
	for (int i = 0; i < list.size(); i++)
		delete list[i];
	list.clear();
	return;
}

vector<token*> scanner::getList() {
	return list;
}