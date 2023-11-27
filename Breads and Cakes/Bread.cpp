/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the definitions of the Bread.h file. In this file the functions for printing out the string for the ToString function
that is in the main and calls the Tostring function that is derived from the BakedGoods class. It also applies extra charges and applies discounts if nessecary for the order.
*/
#include "Bread.h"
#include "BakedGood.h"

Bread::Bread(string breadType) {
	this->breadType = breadType;
	this->bakedGoodPrice = BREAD_PRICE;
	return;
}

string Bread::ToString() const {
	ostringstream breadOSS;
	breadOSS << breadType << " bread " << BakedGood::ToString();

	return breadOSS.str();
}

double Bread::DiscountedPrice(int numofBakedGoods) const {
	int numOfFree = 0;
	int numPaid = 0;
	double totalPrice = 0;
	numOfFree = numofBakedGoods / 3;
	numPaid = numofBakedGoods - numOfFree;
	totalPrice = bakedGoodPrice * numPaid;
	return totalPrice;
}
