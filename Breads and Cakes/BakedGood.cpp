/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the definitions of the BakedGood.h file. It is also the parent class of other classes Bread, Cake, CupCake, and LayerCake.
This is where the definition for the ToString function that is called in all of the other classes.
*/
#include "BakedGood.h"

BakedGood::BakedGood() {
}

string BakedGood::ToString() const {
	ostringstream bakedgoodOSS;
	bakedgoodOSS << "($" << fixed << setprecision(2) << bakedGoodPrice << ")";
	return bakedgoodOSS.str();
}



double BakedGood::DiscountedPrice(int numofBakedGoods) const {

	return 0.0;
}
