/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the definitions of the Song.h file. In this file the functions for setting/getting song names,setting/getting descriptions,
and setting/getting number of plays, adding a number of plays to a song, and printing out the list of songs.
*/
#include "Song.h"
#include <iostream>
#include <string>
using namespace std;
Song::Song(string songName, string songDescription, int timesPlayed) {
	this->songName = songName;
	this->songDescription = songDescription;
	this->timesPlayed = timesPlayed;
	return;
}
void Song::SetName(string songName) {
	this->songName = songName;
	return;
}

string Song::GetName() {
	return songName;
}

void Song::SetDescription(string songDescription) {
	this->songDescription = songDescription;
}

string Song::GetDescription() {
	return songDescription;
}

void Song::SetPlays(int timesPlayed) {
	this->timesPlayed = timesPlayed;
	return;
}

int Song::GetPlays() {
	return timesPlayed;
}

void Song::PrintSongs() {

	return;
}

void Song::AddPlays() {
	timesPlayed++;
}

/*void Song::PrintsongDescription() {
cout << songName << ": " << GetDescription() << endl;
return;
}
*/

