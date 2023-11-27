/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the definitions of the Cupcake.h file. In this file the functions for printing out the string for the ToString function
that is in the main and calls the Tostring function that is derived from the BakedGoods class. It also applies extra charges and applies discounts if nessecary for the order.
It also gets the string pointers that are set in the Cake Parent Class.
*/
#include "CupCake.h"
#include "Cake.h"

CupCake::CupCake(string cakeType, string frostingType, string sprinkleColor) {
	this->cakeType = cakeType;
	this->frostingType = frostingType;
	this->sprinkleColor = sprinkleColor;
	this->bakedGoodPrice = CUPCAKE_PRICE;
	if (frostingType == "cream-cheese") {
		bakedGoodPrice = bakedGoodPrice + CUPCAKE_CREAMCHEESE;
	}
	else {

	}
}

string CupCake::ToString() const {
	ostringstream cupcakeOSS;
	cupcakeOSS << cakeType << " cupcake with " << frostingType << " frosting and " << sprinkleColor << " sprinkles " << BakedGood::ToString();
	return cupcakeOSS.str();
}

double CupCake::DiscountedPrice(int numofBakedGoods) const {
	const double TWO_OR_MORE = .30;
	const double FOUR_OR_MORE = .40;
	double totalPrice = 0;
	double totalDiscount = 0;
	if (numofBakedGoods >= 2 && numofBakedGoods < 4) {
		totalDiscount = numofBakedGoods * TWO_OR_MORE;
		totalPrice = (bakedGoodPrice * numofBakedGoods) - totalDiscount;
	}
	else if (numofBakedGoods >= 4) {
		totalDiscount = numofBakedGoods * FOUR_OR_MORE;
		totalPrice = (bakedGoodPrice * numofBakedGoods) - totalDiscount;
	}
	else {
		totalPrice = bakedGoodPrice;
	}
	return totalPrice;
}



