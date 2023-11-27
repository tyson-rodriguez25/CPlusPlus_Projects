/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the definitions of the Cake.h file. It also is sets the strings that are used for the children classes Cupcake and LayerCake.
*/
#include "Cake.h"
#include "BakedGood.h"

Cake::Cake(string cakeType, string frostingType) {
	this->cakeType = cakeType;
	this->frostingType = frostingType;
}

double Cake::DiscountedPrice(int numofBakedGoods) const {
	return 0.0;
}

