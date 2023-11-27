/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the declaration that contains all of the functions, strings, and vectors used in the Playlist.cpp file
*/
#pragma once
#include<string>
#include<iostream>
#include <iomanip>
#include <vector>
#include "Song.h"
using namespace std;
class Playlist {
public:
	Playlist(string playlistName = "none");
	//~Playlist();
	void SetName(string playlistName);
	string GetName();
	void PrintPlaylists();
	void AddSongToPlaylist(Song* song);
	void PlayPlaylist();
	void DeleteSongOnPlaylist(int songIndex);
	void PrintSongsOnPlaylist();
	void FindSongInPlaylist(Song* song);
private:
	string playlistName;
	vector <Song*> songsOnPlaylist;

};

