/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the definitions of the LayerCake.h file. In this file the functions for printing out the string for the ToString function
that is in the main and calls the Tostring function that is derived from the BakedGoods class. It also applies extra charges and applies discounts if nessecary for the order.
It also gets the string pointers that are set in the Cake Parent Class.
*/
#include "LayerCake.h"
#include "Cake.h"

LayerCake::LayerCake(string cakeType, string frostingType, int numOfLayers) {
	this->cakeType = cakeType;
	this->frostingType = frostingType;
	this->numOfLayers = numOfLayers;
	this->bakedGoodPrice = LAYERCAKE_PRICE;
	if (numOfLayers > 1) {
		bakedGoodPrice = bakedGoodPrice + ADD_LAYER * (numOfLayers - PAST_LAYER_ONE);
	}
	if (frostingType == "cream-cheese") {
		bakedGoodPrice = bakedGoodPrice + (CREAMCHEESE_LAYER * numOfLayers);
	}
	else {

	}
}

string LayerCake::ToString() const {
	ostringstream layercakeOSS;
	layercakeOSS << numOfLayers << "-layer " << cakeType << " cake with " << frostingType << " frosting " << BakedGood::ToString();
	return layercakeOSS.str();
}

double LayerCake::DiscountedPrice(int numofBakedGoods) const {
	const double THREE_OR_MORE = 2.00;
	double totalPrice = 0;
	double totalDiscount = 0;
	if (numofBakedGoods >= 3) {
		totalDiscount = numofBakedGoods * THREE_OR_MORE;
		totalPrice = (bakedGoodPrice * numofBakedGoods) - totalDiscount;
	}
	else {
		totalPrice = bakedGoodPrice * numofBakedGoods;
	}
	return totalPrice;
}
