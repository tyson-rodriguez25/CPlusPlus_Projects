/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the declaration that contains all of the functions, strings, and variables used in the Songs.cpp file
*/
#pragma once
#include<string>
#include<iostream>
#include <iomanip>
using namespace std;
class Song {
public:
	Song(string songName = "none", string songDescription = "none", int timesPlayed = 0);
	//~Song();
	void SetName(string songName);
	string GetName();
	void SetDescription(string songDescription);
	string GetDescription();
	void SetPlays(int timesPlayed);
	int GetPlays();
	void PrintSongs();
	void AddPlays();
	//void PrintsongDescription();
private:
	string songName;
	string songDescription;
	int timesPlayed;

};