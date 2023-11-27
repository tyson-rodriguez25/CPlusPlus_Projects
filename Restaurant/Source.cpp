/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This program simulates a battle tournament That tells the user to add or remove restaurants.
Cut or Shuffle the amount of restaurants and checks if the amount of restaurnats are a power of two.

Test case 1:
Input: (add,a,add,b,add,c,add,d,display,quit)
Expected Output: (added a, added b, added c, added d, showed vector, quit)
Result: Passed

Test case 2:
Input: (add, Taco Bell, add, Papa Johns, add Pizza Hut, add, Whataburger, remove, Hardees, shuffle, quit)
Expected Output: (added Taco Bell, added Papa Johns, added Pizza Hut, added Whataburger, error, shuffled vector, quit )
Result: Passed

Test case 3:
Input: (add Mcdonalds, add Golden Corral, add Carls Jr., add Taco Bell, battle, 1, 2, 2, quit)
Expected Output: (added Mcdonalds, added Golden Corral, added Carls Jr. added Taco Bell,
chose Mcdonalds, chose TacoBell, Chose Taco Bell, Winner: Taco Bell, quit )
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
int foodNum = 0;
vector<string> restaurantNames;

//bool notfound = true;
void CutVector(int cutNumber) {
	string hold = "";
	while (cin.fail() || cutNumber > restaurantNames.size() || cutNumber < 0) {
		cout << "The cut number must be between 0 and " << restaurantNames.size() << endl;
		cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> cutNumber;
	}
	for (int i = 0; i < cutNumber; ++i) {

		hold = restaurantNames.at(0);
		restaurantNames.erase(restaurantNames.begin());
		restaurantNames.push_back(hold);
	}
	return;
}

void ShuffleVector() {
	int split = restaurantNames.size() / 2;
	vector <string> shuffledVector;

	for (int i = 0; i < split; i++) {
		shuffledVector.push_back(restaurantNames.at(i + split));
		shuffledVector.push_back(restaurantNames.at(i));
	}

	restaurantNames = shuffledVector;

	return;
}
bool FindIfPowerTwoBattle(int vectorSize) {
	bool powerTwo = false;

	if (vectorSize < 1 || log2(static_cast<double>(vectorSize)) >
		static_cast<int>(log2(static_cast<double>(vectorSize)))) {
		cout << "The current tournament size (" << restaurantNames.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
		return false;
	}

	return true;
}

bool FindIfPowerTwo(int vectorSize) {
	bool powerTwo = false;

	if (vectorSize < 1 || log2(static_cast<double>(vectorSize)) >
		static_cast<int>(log2(static_cast<double>(vectorSize)))) {
		cout << "The current tournament size (" << restaurantNames.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
		return false;
	}

	return true;
}
int GetInt(const string inputMessage, const string errorMessage, const int minInput, const int maxInput = INT_MAX) {

	int intValue = 0;
	bool gotInt = false;
	string errorBuffer = "";

	while (!gotInt) {
		cout << endl << inputMessage;
		cin >> intValue;
		if (cin.fail() || !(intValue >= minInput && intValue <= maxInput)) {
			cin.clear();
			getline(cin, errorBuffer);
			cout << errorMessage << endl;
		}
		else {
			gotInt = true;
		}
	}
	return intValue;
}
void BeginTournament(vector<string>& restaurantNames) {
	const int FIRST_CHOICE = 1;
	const int SECOND_CHOICE = 2;
	double numRounds = 0.0;
	int numIterations = 0;
	int userChoice = 0;

	vector<string> choiceOneVector;
	vector<string> choiceTwoVector;
	vector<string> roundWinnerVector;
	vector<string> tempRestaurantNames;
	ostringstream sout;
	string inputMessage;

	tempRestaurantNames = restaurantNames;
	numRounds = log(restaurantNames.size()) / log(2);

	for (int i = 0; i < restaurantNames.size(); ++i) {
		if (i % 2 == 0) {
			choiceOneVector.push_back(restaurantNames.at(i));
		}
		else if (i % 2 == 1) {
			choiceTwoVector.push_back(restaurantNames.at(i));
		}
	}

	for (int i = 1; i <= numRounds; ++i) {

		cout << "Round: " << i << endl << endl;
		numIterations = tempRestaurantNames.size() / 2;

		for (int j = 0; j < numIterations; ++j) {
			sout.str("");
			sout << "Type \"1\" if you prefer " << choiceOneVector.at(j) << " or" << endl;
			sout << "type \"2\" if you prefer " << choiceTwoVector.at(j) << endl;
			sout << "Choice: " << endl;
			userChoice = GetInt(sout.str(), "Invalid Choice", FIRST_CHOICE, SECOND_CHOICE);

			if (userChoice == FIRST_CHOICE) {
				roundWinnerVector.push_back(choiceOneVector.at(j));
			}
			else if (userChoice == SECOND_CHOICE) {
				roundWinnerVector.push_back(choiceTwoVector.at(j));
			}
		}

		choiceOneVector.clear();
		choiceTwoVector.clear();
		tempRestaurantNames.clear();
		tempRestaurantNames = roundWinnerVector;
		roundWinnerVector.clear();

		for (int k = 0; k < tempRestaurantNames.size(); ++k) {
			if (k % 2 == 0) {
				choiceOneVector.push_back(tempRestaurantNames.at(k));
			}
			else if (k % 2 == 1) {
				choiceTwoVector.push_back(tempRestaurantNames.at(k));
			}
		}
	}

	cout << "The winning restaurant is " << tempRestaurantNames.at(0) << ".";

	return;
}

bool FindNameRemove(string newRestaurant) {

	//cin.clear();
	//cin.ignore(1000, '\n');
	for (int i = 0; i < restaurantNames.size(); ++i) {

		if (restaurantNames.at(i) == newRestaurant) {
			//found = true;
			restaurantNames.erase(restaurantNames.begin() + i);

			return true;
		}
	}
	return false;
}
bool FindName(string newRestaurant) {
	for (int i = 0; i < restaurantNames.size(); ++i) {
		if (restaurantNames.at(i) == newRestaurant) {
			//found = true;
			return true;
		}
	}
	return false;
}

int main() {
	string optionString;
	string newRestaurant;
	int cutNumber;

	cout << "Welcome to the restaurant battle! Enter \"options\" to see options." << endl;
	//	cout << "Enter your selection : " << endl << endl;
	//	cin >> optionString;
	do {

		cout << "Enter your selection: " << endl << endl;
		cin >> optionString;
		if (optionString == "options") {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please select one of the following options:" << endl << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl;
			//cout << "Enter Your Selection: " << endl;

			//cin >> optionString;
			cout << endl;
		}
		else if (optionString == "cut") {

			cout << "How many restaurants should be taken from the top and put on the bottom?";
			cin >> cutNumber;
			CutVector(cutNumber);
		}

		else if (optionString == "add") {
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "What is the name of the restaurant you want to add?" << endl;
			getline(cin, newRestaurant);
			if (FindName(newRestaurant)) {
				cout << "That restaurant is already on the list, you can not add it again." << endl;
			}

			//cout << newRestaurant;

			else {
				restaurantNames.push_back(newRestaurant);
				cout << endl << newRestaurant << " has been added." << endl;

				//foodNum = foodNum + 1;
				//cin >> optionString;
				cout << endl;
			}
		}
		else if (optionString == "display") {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Here are the current restaurants:" << endl;
			for (int i = 0; i<restaurantNames.size(); ++i) {
				cout << "\"" << restaurantNames.at(i) << "\"" << endl;
			}
		}

		else if (optionString == "remove") {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "What is the name of the restaurant you want to remove?" << endl;
			getline(cin, newRestaurant);
			if (FindNameRemove(newRestaurant) == false) {
				cout << "That restaurant is not on the list, you can not remove it." << endl;
			}
			else {
				cout << newRestaurant << " has been removed.";
			}
		}
		else if (optionString == "shuffle") {
			cin.clear();
			cin.ignore(1000, '\n');
			if (FindIfPowerTwo(restaurantNames.size())) {
				ShuffleVector();
			}
			else {
			}
			//cout << endl << endl << "Enter your selection:" << endl;
			//cin >> optionString;
		}
		else if (optionString == "battle") {
			if (FindIfPowerTwoBattle(restaurantNames.size())) {
				BeginTournament(restaurantNames);
			}
			else {
			}

		}

		else if (optionString != "quit") {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid selection" << endl << endl;
			cout << "Please select one of the following options:" << endl << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl << endl;
			//cout << "Enter Your Selection: " << endl;
			//cin >> optionString;
			cout << endl;
		}

		cout << endl;

	} while (optionString != "quit");
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Goodbye!" << endl;


	//	system("Pause");
	return 0;
}