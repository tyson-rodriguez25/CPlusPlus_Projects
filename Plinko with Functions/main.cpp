/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This program simulates a plinko game. The user can select putting one chip or multiple chips in one and multiple slots
and outputs their winnings and average winnings.

Test case 1:
Input: (4,-1,4,5)
Expected Output: (Menu,error,menu,quit)
Result: Passed

Test case 2:
Input: (-1,3,5,4,5)
Expected Output: (error,multi slot chip, 5 chips, All slot winnings, menu, quit)
Result: Passed

Test case 3:
Input: (4,-4,1,6,9,1,4,5)
Expected Output: (Menu,error,single Chip,slot 6, slot 6 winnings, error, single chip, slot4, winnings, quit)
Result: Passed

LATE DAYS USED : 1
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

int winnings[] = { 100, 500, 1000, 0, 10000, 0, 1000, 500, 100 };

double ComputeWinnings(int chipSpot) {


	return winnings[chipSpot];
}

int GetMenu(int optionNum) {
	const int SINGLE = 1;
	const int QUIT = 5;
	int menuNum = optionNum;
	while (cin.fail() || menuNum < SINGLE || menuNum > QUIT) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid selection. Enter 4 to see options." << endl;
		cin >> menuNum;
		cout << endl << endl;
		cout << "Enter your selection now:" << endl << endl;
	}
	return menuNum;
}

int MultiSlots(int optionNum) {
	// int slotNum = 0;
	const int MULTI_SLOT = 3;
	const int FIRST_SLOT = 0;
	const int LAST_SLOT = 8;
	int multichipNum = 0;
	const double CHIP_MOVE = 0.5;
	const int MONEY_DECIMAL = 2;
	const int NUM_ROWS = 12;
	double direction = 0.0;
	double chipSpot = 0.0;
	double winningsTotal = 0.0;
	double winningAvrg = 0.0;
	double winnings = 0;

	winningsTotal = 0;
	cout << endl << "*** Sequentially drop multiple chips ***" << endl << endl;
	cout << "How many chips do you want to drop (>0)?";
	cin >> multichipNum;
	cout << endl << endl;
	while (cin.fail() || multichipNum <= 0) {
		cout << "Invalid number of chips." << endl << endl;
		cout << "How many chips do you want to drop (>0)?";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> multichipNum;
		cout << endl << endl;

	}

	for (int k = 0;k <= LAST_SLOT;++k) {
		winningsTotal = 0;
		for (int i = 0; i < multichipNum; ++i) {
			chipSpot = k;
			for (int j = 0; j < NUM_ROWS; ++j) {

				if (chipSpot > FIRST_SLOT && chipSpot < LAST_SLOT) {
					direction = rand() % 2;
					if (direction == 0) {
						chipSpot = chipSpot - CHIP_MOVE;
					}
					else {
						chipSpot = chipSpot + CHIP_MOVE;
					}
				}
				else if (chipSpot == FIRST_SLOT || chipSpot == LAST_SLOT) {
					if (chipSpot == FIRST_SLOT) {
						chipSpot = chipSpot + CHIP_MOVE;
					}
					else {
						chipSpot = chipSpot - CHIP_MOVE;
					}
				}

			}
			winnings = ComputeWinnings(chipSpot);
			winningsTotal = winningsTotal + winnings;

		}
		cout << "Total winnings on slot " << k << " chips: "
			<< fixed << setprecision(MONEY_DECIMAL) << winningsTotal << endl;
		winningAvrg = winningsTotal / multichipNum;
		cout << "Average winnings per chip: " << winningAvrg;
		cout << endl << endl;

	}
	return optionNum;
}




int MultiChip(int optionNum) {
	int slotNum = 0;
	//const int MULTI = 2;
	const int FIRST_SLOT = 0;
	const int LAST_SLOT = 8;
	int multichipNum = 0;
	const double CHIP_MOVE = 0.5;
	const int MONEY_DECIMAL = 2;
	const int NUM_ROWS = 12;
	double direction = 0.0;
	double chipSpot = 0.0;
	double winningsTotal = 0.0;
	double winningAvrg = 0.0;
	double winnings = 0;


	winningsTotal = 0;
	cout << endl << "*** Drop multiple chips ***" << endl << endl;
	cout << "How many chips do you want to drop (>0)?";
	cin >> multichipNum;
	cout << endl << endl;
	while (cin.fail() || multichipNum <= 0) {
		cout << "Invalid number of chips." << endl << endl;
		cout << "How many chips do you want to drop (>0)?";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> multichipNum;
		cout << endl << endl;

	}

	cout << "Which slot do you want to drop the chip in (" << FIRST_SLOT << "-" << LAST_SLOT << ")?";
	cin >> slotNum;
	cout << endl << endl;
	while (cin.fail() || slotNum < FIRST_SLOT || slotNum > LAST_SLOT) {
		cout << "Invalid slot." << endl << endl;
		cout << "Which slot do you want to drop the chip in (" << FIRST_SLOT << "-" << LAST_SLOT << ")?";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> slotNum;
		cout << endl << endl;

	}


	for (int i = 0; i < multichipNum; ++i) {
		chipSpot = slotNum;
		for (int j = 0; j < NUM_ROWS; ++j) {
			if (chipSpot > FIRST_SLOT && chipSpot < LAST_SLOT) {
				direction = rand() % 2;
				if (direction == 0) {
					chipSpot = chipSpot - CHIP_MOVE;
				}
				else {
					chipSpot = chipSpot + CHIP_MOVE;
				}
			}
			else if (chipSpot == FIRST_SLOT || chipSpot == LAST_SLOT) {
				if (chipSpot == FIRST_SLOT) {
					chipSpot = chipSpot + CHIP_MOVE;
				}
				else {
					chipSpot = chipSpot - CHIP_MOVE;
				}
			}
		}

		winnings = ComputeWinnings(chipSpot);
		winningsTotal = winningsTotal + winnings;
	}
	cout << "Total winnings on " << multichipNum << " chips: $"
		<< fixed << setprecision(MONEY_DECIMAL) << winningsTotal << endl;
	winningAvrg = winningsTotal / multichipNum;
	cout << "Average winnings per chip: $" << winningAvrg;
	cout << endl << endl;



	return optionNum;
}


int SingleChip(int optionNum) {
	int slotNum = 0;
	const int FIRST_SLOT = 0;
	const int LAST_SLOT = 8;
	const int CHIP_DECIMAL = 1;
	double chipSpot = 0.0;

	const double CHIP_MOVE = 0.5;
	const int NUM_ROWS = 12;
	double direction = 0.0;
	const int MONEY_DECIMAL = 2;

	double winnings = 0;

	cout << "*** Drop a single chip ***" << endl << endl;
	cout << "Which slot do you want to drop the chip in (" << FIRST_SLOT << "-" << LAST_SLOT << ")?";
	cin >> slotNum;
	cout << endl << endl;
	while (cin.fail() || slotNum < FIRST_SLOT || slotNum > LAST_SLOT) {
		cout << "Invalid slot." << endl << endl;
		cout << "Which slot do you want to drop the chip in (" << FIRST_SLOT << "-" << LAST_SLOT << ")?";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> slotNum;
		cout << endl << endl;

	}

	cout << "*** Dropping chip into slot " << slotNum << " ***" << endl;
	chipSpot = slotNum;
	cout << "Path: [" << fixed << setprecision(CHIP_DECIMAL) << chipSpot;
	for (int i = 0; i < NUM_ROWS; ++i) {
		if (chipSpot > FIRST_SLOT && chipSpot < LAST_SLOT) {
			direction = rand() % 2;
			if (direction == 0) {
				chipSpot = chipSpot - CHIP_MOVE;
			}
			else {
				chipSpot = chipSpot + CHIP_MOVE;
			}
		}
		else if (chipSpot == FIRST_SLOT || chipSpot == LAST_SLOT) {
			if (chipSpot == FIRST_SLOT) {
				chipSpot = chipSpot + CHIP_MOVE;
			}
			else {
				chipSpot = chipSpot - CHIP_MOVE;
			}
		}
		cout << ", " << fixed << setprecision(CHIP_DECIMAL) << chipSpot;
	}

	cout << "]" << endl;
	winnings = ComputeWinnings(chipSpot);
	cout << fixed << setprecision(MONEY_DECIMAL) << "Winnings: $" << winnings;


	return optionNum;
}


int DifferentOptions(int optionNum) {
	const int SINGLE = 1;
	const int MULTI = 2;
	const int MULTI_SLOT = 3;
	const int MENU = 4;
	const int QUIT = 5;
	optionNum = GetMenu(optionNum);
	if (optionNum < SINGLE || optionNum > QUIT) {
		cout << "Invalid selection. Enter 4 to see options." << endl;

	}
	if (optionNum == SINGLE) {

		optionNum = SingleChip(optionNum);
	}
	if (optionNum == MULTI) {

		optionNum = MultiChip(optionNum);
	}
	if (optionNum == MULTI_SLOT) {
		optionNum = MultiSlots(optionNum);
	}
	if (optionNum == MENU) {
		cout << "Menu: Please select one of the following options:" << endl;
		cout << endl;
		cout << "1 - Drop a single chip into one slot" << endl;
		cout << "2 - Drop multiple chips into one slot" << endl;
		cout << "3 - Drop multiple chips into each slot" << endl;
		cout << "4 - Show the options menu" << endl;
		cout << "5 - Quit the program" << endl;
		cout << endl;

	}


	return optionNum;
}

int main() {
	int optionNum = 0;
	const int QUIT = 5;
	const int SEED = 42;
	srand(SEED);



	cout << "Welcome to the Plinko Simulator! Enter 4 to see options." << endl;
	cout << endl;

	do {
		cout << "Enter your selection now: ";
		cin >> optionNum;
		cout << endl;
		optionNum = DifferentOptions(optionNum);

		cout << endl << endl;

	} while (optionNum != QUIT);

	cout << "Goodbye!" << endl;


	//	system("pause");
	return 0;
}