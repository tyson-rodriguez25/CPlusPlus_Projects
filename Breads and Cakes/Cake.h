/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the declaration that contains all of the functions, strings, and vectors used in the Cake.cpp file.
It also is taking some functions from the Parent Class BakedGood.
*/
#pragma once
#include <iostream>
#include <string>
#include "BakedGood.h"
using namespace std;
class Cake :
	public BakedGood {
protected:
	string cakeType;
	string frostingType;
public:
	Cake(string cakeType = "none", string frostingType = "none");
	virtual double DiscountedPrice(int numofBakedGoods) const = 0;
private:

};

