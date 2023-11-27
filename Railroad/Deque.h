#ifndef DEQUE_H
#define DEQUE_H
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "DequeInterface.h"
template<typename T> class Deque : public DequeInterface<T>
{
private:
	static const size_t DEFAULT_CAPACITY = 4;
	size_t capacity;
	size_t numItems;
	size_t frontIndex;
	size_t rearIndex;
	T* theData;
	void reallocate() { 
		T* temp;	
		if (numItems == capacity) {
			T* newData = new T[capacity * 2];
			for (int i = 0; i < capacity;++i) {
				newData[i] = theData[(i + frontIndex) % capacity];
			}
			frontIndex = 0;
			rearIndex = capacity - 1;
			capacity = capacity * 2;
			temp = theData;
			theData = newData;
			delete temp;
		}
	};
public:
	Deque() { 
		capacity = DEFAULT_CAPACITY;
		numItems = 0; 
		frontIndex = 0; 
		rearIndex = capacity - 1;
		theData = new T[DEFAULT_CAPACITY];
	}
	~Deque() { delete theData; }
	virtual void push_front(const T& value){
		if (numItems == capacity) {
			reallocate();
		}
		frontIndex--;
		if (frontIndex == -1) {
			frontIndex = capacity - 1;
		}
		theData[frontIndex] = value;
		++numItems;
	}
	virtual void push_back(const T& value){
		if (numItems == capacity) {
			reallocate();
		}
		rearIndex++;
		if (rearIndex == capacity) {
			rearIndex = 0;
		}
		theData[rearIndex] = value;
		++numItems;
	}
	virtual void pop_front(){
		frontIndex++;
		if (frontIndex == capacity) {
			frontIndex = 0;
		}
		--numItems;
	}
	virtual void pop_back(){
		rearIndex--;
		if (rearIndex == -1) {
			rearIndex = capacity - 1;
		}
		--numItems;
	}
	virtual T& front(){
		return theData[frontIndex];
	}
	virtual T& back(){
		return theData[rearIndex];
	}
	virtual size_t size() const {
		return numItems;
	}
	virtual bool empty() const{
		if (numItems == 0) {
			return true;
		}
		return false;
	}
	virtual T& at(size_t index){
		return theData[(frontIndex + index) % capacity];
	}
	virtual string toString() const {
		ostringstream str;
		for (size_t i = 0; i < numItems; ++i) {
			str << theData[(frontIndex + i) % capacity] << " ";
		}
		return str.str();
	}
};
#endif