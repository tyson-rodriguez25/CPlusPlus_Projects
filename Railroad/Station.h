#ifndef STATION_H
#define STATION_H
using namespace std;

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"

template<typename T>
class Station 
{
private:
	Queue<T> queue;
	Vector<T> train;
	Stack<T> stack;
	T turnTableCar = empty;
	bool empty;
public:
	// Add something to the Turn table
	string addCar(T value) {
		if (turnTableCar == empty) {
			stringstream out;
			turnTableCar = value;
			out << "OK" << endl;
			return out.str();
		}
		else {
			stringstream out;
			out << "Turntable occupied!" << endl;
			return out.str();
		}
	}
	//Removes something from the turntable
	string removeCar() {
		if (turnTableCar != empty) {
			train.push_back(turnTableCar);
			stringstream out;
			out << "OK" << endl;
			turnTableCar = empty;
			return out.str();
			
		}
		else {
			stringstream out;
			out << "Turntable empty!" << endl;
			return out.str();
			
		}
	}
	// Checks the turn table value
	string topCar() {
		ostringstream topCar;
		topCar << train.at(0) << endl;
		return topCar.str();
	}
	// Adds to the stack and checks the turntable
	string addStack() {
		if (turnTableCar != empty) {
			stack.push(turnTableCar);
			stringstream out;
			out << "OK" << endl;
			turnTableCar = empty;
			return out.str();

		}
		else {
			stringstream out;
			out << "Turntable empty!" << endl;
			return out.str();
		}
	}
	// Removes from stack and checks if stack is empty or turntable is open
	string removeStack() {
		if (stack.size() == 0) {
			stringstream out;
			out << "Stack empty!" << endl;
			return out.str();
		}
		else {
			if (turnTableCar == empty) {
				stringstream out;
				turnTableCar = stack.top();
				stack.pop();
				out << "OK" << endl;
				return out.str();
			}
			else {
				stringstream out;
				out << "Turntable occupied!" << endl;
				return out.str();
			}
		}
	}
	// Checks what value is at the top of the stack
	string topStack() {
		stringstream out;
		out << stack.top() << endl;
		return out.str();
	}
	// Outputs the top of the Stack
	string sizeStack() {
		stringstream out;
		out << stack.size() << endl;
		return out.str();
	}
	// Adds to the queue and checks the turntable
	string addQueue() {
		if (turnTableCar != empty) {
			queue.push(turnTableCar);
			stringstream out;
			out << "OK" << endl;
			turnTableCar = empty;
			return out.str();

		}
		else {
			stringstream out;
			out << "Turntable empty!" << endl;
			return out.str();
		}
	}
	// Removes from queue and checks if stack is empty or turntable is open
	string removeQueue() {
		if (queue.size() == 0) {
			stringstream out;
			out << "Queue empty!" << endl;
			return out.str();
		}
		else {
			if (turnTableCar == empty) {
				stringstream out;
				turnTableCar = queue.top();
				queue.pop();
				out << "OK" << endl;
				return out.str();
			}
			else {
				stringstream out;
				out << "Turntable occupied!" << endl;
				return out.str();
			}
		}
	}
	//Outputs the top of the queue
	string topQueue() {
		stringstream out;
		out << queue.top() << endl;
		return out.str();
	}
	// Outputs the top of the queue
	string sizeQueue() {
		stringstream out;
		out << queue.size() << endl;
		return out.str();
	}
	// Screw this
	string find(T) {}
	//Outputs the vector
	string toString() const {
		train.toString();
		return train.toString();
	}


};
#endif