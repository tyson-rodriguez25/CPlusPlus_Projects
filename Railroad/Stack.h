#ifndef STACK_H
#define STACK_H
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
template<typename T>
class Stack
{
private:
	Deque<T> stack;
public:
	Stack() {}
	~Stack() {}
	string push(const T& value) {
		stack.push_back(value);
		return "";
	}
	void pop() {
		stack.pop_back();
	}
	T& top() {
		 return stack.back();
	}
	size_t size() {
		return stack.size();
	};
	T& at(size_t) {}
	string toString() const {
		return stack.toString();
	}


};
#endif