#ifndef VECTOR_H
#define VECTOR_H
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
class Vector
{
private:
	Deque<T> vector;
public:
	Vector() {}
	~Vector() {}
	void push_back(const T& data) {
		vector.push_back(data);
	}
	void pop_back() {
		T temp = vector.back();
		vector.pop_back();
		return temp;
	}
	T& back() {}
	size_t size() {
		return vector.size();
	}
	T& at(size_t) {}
	string toString() const {
		return vector.toString();
	
	}


};
#endif