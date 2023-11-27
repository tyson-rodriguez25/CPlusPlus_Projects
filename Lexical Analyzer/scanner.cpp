#include "scanner.h"
#include <ctype.h>
#include <vector>
using namespace std;

Scanner::Scanner(istream* in) {
	this->in = in;
}

Scanner::~Scanner() { 
	tokens.clear();
}

vector<Token*> Scanner::lexicalAnalyzer() {
	char c;
	this->line = 1;
	while (true) {
		c = this->in->get();
		if (this->in->eof()) {
			tokens.push_back(new Token(END_OF_FILE, "", this->line));
			break;
		}
		if (isspace(c)) {
			if (c == '\n') this->line++;
			continue;
		}

		switch (c) {
		case ',':
			tokens.push_back(new Token(COMMA, ",", this->line));
			break;

		case '.':
			tokens.push_back(new Token(PERIOD, ".", this->line));
			break;

		case '?':
			tokens.push_back(new Token(Q_MARK, "?", this->line));
			break;

		case '(':
			tokens.push_back(new Token(LEFT_PAREN, "(", this->line));
			break;

		case ')':
			tokens.push_back(new Token(RIGHT_PAREN, ")", this->line));
			break;

		case ':':
			if (this->in->peek() == '-') {
				this->in->get();
				tokens.push_back(new Token(COLON_DASH, ":-", this->line));
			}
			else {
				tokens.push_back(new Token(COLON, ":", this->line));
			}
			break;

		case '*':
			tokens.push_back(new Token(MULTIPLY, "*", this->line));
			break;

		case '+':
			tokens.push_back(new Token(ADD, "+", this->line));
			break;

		case '\'':
			tokens.push_back(this->Eat_string());
			break;

		case '#':
			if (this->in->peek() == '|') {
				this->in->get();
				tokens.push_back(this->block_comment());
			}
			else {
				tokens.push_back(this->line_comment());
			}
			break;

		default:

			if (!isalpha(c)) {
				string extracted = "";
				extracted += c;
				tokens.push_back(new Token(UNDEFINED, extracted, this->line));
			}
			else {
				this->in->putback(c);
				tokens.push_back(this->alpha_numeric());
			}
		}
	}

	return tokens;
}

Token* Scanner::alpha_numeric() {
	string extracted = "";
	while (isalpha(this->in->peek()) || isalnum(this->in->peek())) {
		extracted += this->in->get();
	}

	if (this->keyword.find(extracted) != this->keyword.end()) {
		return new Token(this->keyword[extracted], extracted, this->line);
	}
	else {
		return new Token(ID, extracted, this->line);
	}
}

Token* Scanner::line_comment() {
	string extracted = "#";
	int start_line = this->line;
	char c;
	while (true) {
		c = this->in->get();
		if (this->in->eof()) {
			break;
		}
		if (c == '\n') {
			this->line++;
			break;
		}
		extracted += c;
	}
	return new Token(COMMENT, extracted, start_line);
}

Token* Scanner::block_comment() {
	string extracted = "#|";
	int start_line = this->line;
	char c;
	while (true) {
		c = this->in->get();
		if (this->in->eof()) {
			return new Token(UNDEFINED, extracted, start_line);
		}
		if (c == '|' && this->in->peek() == '#') {
			this->in->get();
			extracted += "|#";
			return new Token(COMMENT, extracted, start_line);
		}
		if (c == '\n') this->line++;
		extracted += c;
	}
}

Token* Scanner::Eat_string() {
	string extracted = "'";
	int start_line = this->line;
	char c;
	while (true) {
		c = this->in->get();
		if (this->in->eof()) {
			return new Token(UNDEFINED, extracted, start_line);
		}

		if (c == '\'') {
			if (this->in->peek() == '\'') {
				extracted += c;
				c = this->in->get();
			}
			else {
				extracted += '\'';
				return new Token(STRING, extracted, start_line);
			}
		}


		if (c == '\n') this->line++;

		extracted += c;
	}
}