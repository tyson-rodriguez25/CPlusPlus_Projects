/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the declaration that contains all of the functions, strings, and vectors used in the LayerCake.cpp file.
It also is taking some functions from the Parent Classes BakedGood and Cake.
*/
#pragma once
#include "Cake.h"
#include <iostream>
#include <string>
#include <sstream>
class LayerCake :
	public Cake {
public:
	LayerCake(string cakeType = "none", string frostingType = "none", int numOfLayers = 0);
	string ToString() const;
	double DiscountedPrice(int numofBakedGoods) const;
private:
	int numOfLayers;
	double const LAYERCAKE_PRICE = 9.00;
	const double CREAMCHEESE_LAYER = 1.00;
	const double ADD_LAYER = 3.00;
	const int PAST_LAYER_ONE = 1;
};

