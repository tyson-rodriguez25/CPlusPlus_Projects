/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This Program simulates a playlist program that allows the user to add songs, add playlists, add songs to playlists,
lists the songs on the library with the title, the first line, and times played (the user added these when they added the song),
lists the playlists that the user creates,delete playlists, delete songs on a playlist or the song library, show options menu and quit the program
***Deletes are on lines: 157,185,211***

Test case 1:
Input: (options, add, "Hello","how are you", "STOP", list, quit)
Expected Output: (menu, added the song "Hello" with the first line, lists the songs with the title, first line,
and times played, quit)
Result: Passed

Test case 2:
Input: (add, "Whats Up", "yo whats up", "How are you", "I sing this song", "Black Parade", "When I was a young boy",
addp, "Chill", addsp, 0, 0, delsl, 1, quit)
Expected Output: (added the songs "Whats up" "How are you" and "Black Parade with the first lines,
added the "Chill" playlist,added "Whats up" to the playlist "Chill", deleted the song "how are you" from the library, quit)
Result: Passed

Test case 3:
Input: (add, "Hey Mom", "How are you", "Yo whats up", "How you doin",  "Bad", "Im bad", "STOP", addp, "Chill", addp, "Gaming",
listp, addsp, 0, 0, addsp, 1, 2, addsp, 0, 2, delsp, 0, 0, delp, 1, quit)
Expected Output: (added the songs "Hey Mom", "Yo whats up", and "Bad" with the first lines, added playlists "Chill" and "Gaming",
added the song "Hey Mom" to play list "Chill", added the song "Yo whats up" to playlist "Gaming", added the song "Bad to playlist "Chill",
delted playlist "Gaming", quit)
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
#include "Song.h"
#include "Playlist.h"

void GetLineNotWS(string& inpString) {

	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos) {
		getline(cin, inpString);
	}
	return;
}

int main() {
	string optionChoice;
	string songName;
	string songDescription;
	vector <Song*> songList;
	int timesPlayed = 0;
	string playlistName;
	vector <Playlist*> playlists;
	int playlistIndex = 0;
	int songIndex = 0;


	double itemPrice = 0.0;
	int itemQuantity = 0;

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;


	while (optionChoice != "quit") {

		cout << "Enter your selection now: ";
		cin >> optionChoice;
		cout << endl;

		if (optionChoice == "add") {
			cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			while (songName != "STOP") {

				cout << "Song Name: ";
				getline(cin, songName);
				cout << endl;
				if (songName == "STOP") {
					break;
				}
				else {

					cout << "Song's first line: ";
					getline(cin, songDescription);
					cout << endl;

					Song* newItem = new Song(songName, songDescription, timesPlayed);
					songList.push_back(newItem);
				}
			}
		}
		else if (optionChoice == "list") {
			for (int i = 0; i < songList.size(); ++i) {
				cout << songList.at(i)->GetName() << ": ";
				cout << "\"" << songList.at(i)->GetDescription() << "\", ";
				cout << songList.at(i)->GetPlays() << " play(s)." << endl;
			}
			cout << endl;
		}

		else if (optionChoice == "addp") {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Playlist name: ";
			getline(cin, playlistName);
			Playlist* newItem = new Playlist(playlistName);
			playlists.push_back(newItem);

		}

		else if (optionChoice == "addsp") {
			for (int i = 0; i < playlists.size(); ++i) {
				cout << i << ": " << playlists.at(i)->GetName() << endl;
			}
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			for (int i = 0; i < songList.size(); ++i) {
				cout << i << ": " << songList.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: ";
			cin >> songIndex;

			playlists.at(playlistIndex)->AddSongToPlaylist(songList.at(songIndex));
		}

		else if (optionChoice == "listp") {
			for (int i = 0; i < playlists.size(); ++i) {
				cout << i << ": " << playlists.at(i)->GetName() << endl;
			}
		}

		else if (optionChoice == "play") {
			for (int i = 0; i < playlists.size(); ++i) {
				cout << i << ": " << playlists.at(i)->GetName() << endl;
			}
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cout << endl;
			cout << "Playing first lines of playlist: " << playlists.at(playlistIndex)->GetName()
				<< endl;

			playlists.at(playlistIndex)->PlayPlaylist();


		}

		else if (optionChoice == "delp") {
			for (int i = 0; i < playlists.size(); ++i) {
				cout << i << ": " << playlists.at(i)->GetName() << endl;
			}
			cout << "Pick a playlist index number to delete: ";
			cin >> playlistIndex;
			delete playlists.at(playlistIndex);
			playlists.erase(playlists.begin() + playlistIndex);
			cout << endl;
		}

		else if (optionChoice == "delsp") {
			for (int i = 0; i < playlists.size(); ++i) {
				cout << i << ": " << playlists.at(i)->GetName() << endl;
			}
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cout << endl;
			playlists.at(playlistIndex)->PrintSongsOnPlaylist();
			cout << "Pick a song index number to delete: ";
			cin >> songIndex;
			playlists.at(playlistIndex)->DeleteSongOnPlaylist(songIndex);

		}

		else if (optionChoice == "delsl") {
			for (int i = 0; i < songList.size(); ++i) {
				cout << i << ": " << songList.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: ";
			cin >> songIndex;
			for (int i = 0; i < playlists.size(); ++i) {
				playlists.at(i)->FindSongInPlaylist(songList.at(songIndex));
			}
			delete songList.at(songIndex);
			songList.erase(songList.begin() + songIndex);


		}

		else if (optionChoice == "quit") {
			break;
		}
		else {
			cout << "add      Adds a list of songs to the library" << endl;
			cout << "list     Lists all the songs in the library" << endl;
			cout << "addp     Adds a new playlist" << endl;
			cout << "addsp    Adds a song to a playlist" << endl;
			cout << "listp    Lists all the playlists" << endl;
			cout << "play     Plays a playlist" << endl;
			cout << "delp     Deletes a playlist" << endl;
			cout << "delsp    Deletes a song from a playlist" << endl;
			cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
			cout << "options  Prints this options menu" << endl;
			cout << "quit     Quits the program" << endl << endl;
		}


	}
	for (int i = 0; i < songList.size(); ++i) {
		delete songList.at(i);
	}
	cout << "Goodbye!" << endl;

	system("pause");
	return 0;
}
