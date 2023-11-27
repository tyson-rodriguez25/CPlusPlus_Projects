/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the declaration that contains all of the functions, strings, and vectors used in the CupCake.cpp file.
It also is taking some functions from the Parent Classes BakedGood and Cake.
*/
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Cake.h"
class CupCake :
	public Cake {
public:
	CupCake(string cakeType = "none", string frostingType = "none", string sprinkleColor = "none");
	string ToString() const;
	double DiscountedPrice(int numofBakedGoods) const;
private:
	string sprinkleColor;
	double const CUPCAKE_PRICE = 1.95;
	const double CUPCAKE_CREAMCHEESE = .20;
};

