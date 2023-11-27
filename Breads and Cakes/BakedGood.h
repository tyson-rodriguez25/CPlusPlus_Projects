/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the declaration that contains all of the functions, strings, and vectors used in the BakedGood.cpp file.
It is also the Parent Class of all of the children classes.
*/
#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
class BakedGood {
protected:
	double bakedGoodPrice = 0.0;
public:
	BakedGood();
	virtual string ToString() const;
	virtual double DiscountedPrice(int numofBakedGoods) const = 0;
};

