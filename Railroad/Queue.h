#ifndef QUEUE_H
#define QUEUE_H
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
class Queue
{
private:
	Deque<T> queue;
public:
	Queue() {}
	~Queue() {}
	string push(const T& value) {
		queue.push_back(value);
		return "";
	}
	void pop() { 
		queue.pop_front(); 
	}
	T& top() { 
		return queue.front();
	}
	size_t size() {
		return queue.size();
		};
	T& at(size_t) {} 
	string toString() const {
		return queue.toString();
	}


};
#endif