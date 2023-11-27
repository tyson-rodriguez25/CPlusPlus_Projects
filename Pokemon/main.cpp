#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Map.h"
#include "Set.h"
using namespace std;


#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[]) {
	VS_MEM_CHECK

		if (argc < 3)
		{
			cerr << "Please provide name of input and output files";
			return 1;
		}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 1;
	}
	cout << "output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
	}

	string type;
	string line;
	string secondType;
	string moveType;
	string weakType;
	string pokemonOne;
	string pokemonTwo;
	string moveOne;
	string moveTwo;
	string pokeOneType;
	string pokeTwoType;
	string pokeOneMove;
	string pokeTwoMove;
	string blank;
	int resultOne;
	int resultTwo;
	string battleStart;
	Map<string, string> pokemon;
	Map<string, string> moves;
	Map<string, Set<string>> effectivities;
	Map<string, Set<string>> ineffectivities;

	// Reads in the lines and inputs them into sets and maps respectivly
	while (getline(in, line)) {
		if (line == "Pokemon:") {
			out << "Pokemon: " << endl;
			for (string names; in >> names;) {
				if (names == "Moves:") {
					for (string moveName; in >> moveName;) {
						if (moveName == "Effectivities:") {
							for (string effectiveType; in >> effectiveType;) {
								if (effectiveType == "Ineffectivities:") {
									for (string ineffectiveType; in >> ineffectiveType;) {
										if (ineffectiveType == "Battles:") {
											battleStart = "Battle";
											break;
										}
										getline(in, line);
										stringstream weakOut;
										weakOut << line;
										ineffectiveType.pop_back();
										ineffectivities[ineffectiveType];
										while (weakOut >> weakType) {
											ineffectivities[ineffectiveType].insert(weakType);
										}
									}
									break;
								}
								getline(in, line);
								stringstream out;
								out << line;
								effectiveType.pop_back();
								effectivities[effectiveType];
								while (out >> secondType) {
									effectivities[effectiveType].insert(secondType);
								}
							}
							break;
						}
						in >> moveType;
						moves[moveName] = moveType;
					}
					break;
				}
				in >> type;
				pokemon[names] = type;
			}
			out << pokemon.toString() << endl;
			out << "Moves: " << endl << moves.toString() << endl;
			out << "Effectivities:" << endl << effectivities.toString() << endl;
			out << "Ineffectivites:" << endl << ineffectivities.toString() << endl;
		}
		
		// Checks the pokemon types and outputs the battle winner
		if (battleStart == "Battle") {
			while (getline(in, line)) {
				if (line == "") {
					continue;
				}
				istringstream iss(line);
				iss >> pokemonOne;
				pokemonOne.pop_back();
				iss >> moveOne;
				iss >> pokemonTwo;
				pokemonTwo.pop_back();
				iss >> moveTwo;

				pokeOneType = pokemon[pokemonOne];
				pokeTwoMove = moves[moveTwo];
				
				if (effectivities[pokeTwoMove].count(pokeOneType) == 1) {
					resultOne = 2;
				}
				else if (ineffectivities[pokeTwoMove].count(pokeOneType) == 1) {
					resultOne = 0;
				}
				else {
					resultOne = 1;
				}

				pokeTwoType = pokemon[pokemonTwo];
				pokeOneMove = moves[moveOne];

				if (effectivities[pokeOneMove].count(pokeTwoType) == 1) {
					resultTwo = 2;
				}
				else if (ineffectivities[pokeOneMove].count(pokeTwoType) == 1) {
					resultTwo = 0;
				}
				else {
					resultTwo = 1;
				}

				if (resultOne < resultTwo) {
					out << pokemonOne << " (" << moveOne << ") vs " << pokemonTwo << " (" << moveTwo << "): " << pokemonOne << " wins!" << endl;
				}
				else if (resultOne > resultTwo) {
					out << pokemonOne << " (" << moveOne << ") vs " << pokemonTwo << " (" << moveTwo << "): " << pokemonTwo << " wins!" << endl;
				}
				else {
					out << pokemonOne << " (" << moveOne << ") vs " << pokemonTwo << " (" << moveTwo << "): Tie!" << endl;
				}
			}
		}
	}
	
	return 0;
}
