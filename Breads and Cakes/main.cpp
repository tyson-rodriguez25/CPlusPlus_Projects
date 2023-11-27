/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This program simulates an order that a customer can input many different suborders. The customer enters a suborder type and other details
pertaining to the suborder like cupcake sprinkle color, layercake number of layers, or type of bread. After they input the different sub orders it prints out
all of the customers suborders and then prints an invoice with the quantity and price for all the objects in the order along with a total amount of items and price.
Also if the customer wants cream cheese frosting and wants to add a layer to the layer cake it will charge them extra and will also apply discounts for each sub-order.

Test case 1:
Input: ("Bread White 3", "Bread Sourdough 5", "done")
Expected Output: (
Order Confirmations:
White bread ($4.50)
White bread ($4.50)
White bread ($4.50)
Sourdough bread ($4.50)
Sourdough bread ($4.50)
Sourdough bread ($4.50)
Sourdough bread ($4.50)
Sourdough bread ($4.50)
Invoice:
Baked Good                                                                 Quantity     Total
White bread ($4.50)                                                                3     9.00
Sourdough bread ($4.50)                                                            5    18.00
Totals                                                                             8    27.00)
Result: Passed

Test case 2:
Input: ("Bread Pumpernickle 2", "Cupcake Vanilla Vanilla Red 6", "Layer-cake red-velvet cream-cheese 3 1", done)
Expected Output: (
Order Confirmations:
Pumpernickle bread ($4.50)
Pumpernickle bread ($4.50)
Vanilla cupcake with Vanilla frosting and Red sprinkles ($1.95)
Vanilla cupcake with Vanilla frosting and Red sprinkles ($1.95)
Vanilla cupcake with Vanilla frosting and Red sprinkles ($1.95)
Vanilla cupcake with Vanilla frosting and Red sprinkles ($1.95)
Vanilla cupcake with Vanilla frosting and Red sprinkles ($1.95)
Vanilla cupcake with Vanilla frosting and Red sprinkles ($1.95)
3-layer red-velvet cake with cream-cheese frosting ($18.00)
Invoice:
Baked Good                                                                 Quantity     Total
Pumpernickle bread ($4.50)                                                         2     9.00
Vanilla cupcake with Vanilla frosting and Red sprinkles ($1.95)                    6     9.30
3-layer red-velvet cake with cream-cheese frosting ($18.00)                        1    18.00
Totals                                                                             9    36.30)
Result: Passed

Test case 3:
Input: ("Bread rye 2", "Cupcake chocolate cream-cheese blue 2", "Cupcake Vanilla chocolate none 2", Layer-cake spice cream-cheese 2 1", "Layer-cake vanilla vanilla 32 2", "done")
Expected Output: (
Order Confirmations:
rye bread ($4.50)
rye bread ($4.50)
chocolate cupcake with cream-cheese frosting and blue sprinkles ($2.15)
chocolate cupcake with cream-cheese frosting and blue sprinkles ($2.15)
vanilla cupcake with chocolate frosting and none sprinkles ($1.95)
vanilla cupcake with chocolate frosting and none sprinkles ($1.95)
2-layer spice cake with cream-cheese frosting ($14.00)
32-layer vanilla cake with vanilla frosting ($102.00)
32-layer vanilla cake with vanilla frosting ($102.00)
Invoice:
Baked Good                                                                 Quantity     Total
rye bread ($4.50)                                                                  2     9.00
chocolate cupcake with cream-cheese frosting and blue sprinkles ($2.15)            2     3.70
vanilla cupcake with chocolate frosting and none sprinkles ($1.95)                 2     3.30
2-layer spice cake with cream-cheese frosting ($14.00)                             1    14.00
32-layer vanilla cake with vanilla frosting ($102.00)                              2   204.00
Totals                                                                             9   234.00)
Result: Passed
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "LayerCake.h"
#include "CupCake.h"

int main() {
	string subOrder;
	string bakedGoodType;
	string cakeType;
	string frostingType;
	string breadType;
	string sprinkleColor;
	int numOfLayers = 0;
	int orderQuantity = 0;
	const double CUPCAKE_CREAMCHEESE = .90;
	const double CREAMCHEESE_LAYER = 1.00;
	const double ADD_LAYER = 3.00;
	vector <BakedGood*> bakedGoods;
	int sameCounter = 0;
	int totalGoods = 0;
	double totalOrderPrice = 0;


	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	while (subOrder != "done") {

		cout << "Sub-order: ";
		cin >> bakedGoodType;
		if (bakedGoodType == "Cupcake") {
			cin >> cakeType;
			cin >> frostingType;
			cin >> sprinkleColor;
			cin >> orderQuantity;
			for (int i = 0; i < orderQuantity; ++i) {
				BakedGood* newItem = new CupCake(cakeType, frostingType, sprinkleColor);
				bakedGoods.push_back(newItem);
			}
		}
		else if (bakedGoodType == "Bread") {
			cin >> breadType;
			cin >> orderQuantity;
			for (int i = 0; i < orderQuantity; ++i) {
				BakedGood* newItem = new Bread(breadType);
				bakedGoods.push_back(newItem);
			}

		}
		else if (bakedGoodType == "Layer-cake") {
			cin >> cakeType;
			cin >> frostingType;
			cin >> numOfLayers;
			cin >> orderQuantity;
			for (int i = 0; i < orderQuantity; ++i) {
				BakedGood* newItem = new LayerCake(cakeType, frostingType, numOfLayers);
				bakedGoods.push_back(newItem);
			}
		}
		else if (bakedGoodType == "done") {
			cout << endl;
			break;
		}
	}
	cout << "Order Confirmations:" << endl;
	for (int i = 0; i < bakedGoods.size(); ++i) {
		cout << bakedGoods.at(i)->ToString() << endl;
	}
	cout << "Invoice:" << endl;
	cout << left << setw(75) << "Baked Good" << left << setw(9) << "Quantity" << right << setw(9);
	cout << "Total" << endl;
	for (int i = 0; i < bakedGoods.size(); ++i) {
		sameCounter = 1;
		for (int j = i + 1; j < bakedGoods.size(); ++j) {
			if (bakedGoods.at(i)->ToString() == bakedGoods.at(j)->ToString()) {
				bakedGoods.erase(bakedGoods.begin() + j);
				j--;
				++sameCounter;
			}
			else {

			}
		}
		cout << left << setw(75) << bakedGoods.at(i)->ToString() << right << setw(9) << sameCounter << setw(9);
		cout << fixed << setprecision(2) << bakedGoods.at(i)->DiscountedPrice(sameCounter) << endl;
		totalGoods = totalGoods + sameCounter;
		totalOrderPrice += bakedGoods.at(i)->DiscountedPrice(sameCounter);
	}
	cout << left << setw(75) << "Totals" << right << setw(9) << totalGoods << right << setw(9);
	cout << fixed << setprecision(2) << totalOrderPrice << endl;
	cout << "Good Bye";


	//system("Pause");
	return 0;
}