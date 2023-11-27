/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the declaration that contains all of the functions, strings, and vectors used in the Bread.cpp file.
It also is taking some functions from the Parent Class BakedGood.
*/
#pragma once
#include "BakedGood.h"
#include <iostream>
#include <sstream>
class Bread :
	public BakedGood {
public:
	Bread(string BreadType = "none");
	string ToString() const;
	double DiscountedPrice(int numofBakedGoods) const;
private:
	const double BREAD_PRICE = 4.50;
	string breadType;

};

