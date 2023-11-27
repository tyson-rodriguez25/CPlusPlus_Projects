/*
Tyson Rodriguez, Section 2, tyson.rodriguez25@yahoo.com
Description: This is the definitions of the Playlist.h file. In this file the functions for printing, setting/getting names of playlists,
playing the playlists, deleteing the song on a playlist, printing the songs on a playlist, and finding a song on a playlist.
*/
#include "Playlist.h"
#include <iostream>
#include <string>
using namespace std;
Playlist::Playlist(string playlistName) {
	this->playlistName = playlistName;
	return;
}
void Playlist::SetName(string playlistName) {
	this->playlistName = playlistName;
	return;
}

string Playlist::GetName() {
	return playlistName;
}

void Playlist::PrintPlaylists() {

	return;
}
void Playlist::AddSongToPlaylist(Song* song) {
	songsOnPlaylist.push_back(song);

}
void Playlist::PlayPlaylist() {
	for (unsigned int i = 0; i < songsOnPlaylist.size(); ++i) {
		cout << songsOnPlaylist.at(i)->GetDescription() << endl;
		(songsOnPlaylist.at(i)->AddPlays());
	}
}
void Playlist::DeleteSongOnPlaylist(int songIndex) {

	songsOnPlaylist.erase(songsOnPlaylist.begin() + songIndex);
}

void Playlist::PrintSongsOnPlaylist() {
	for (unsigned int i = 0; i < songsOnPlaylist.size(); ++i) {
		cout << i << ": " << songsOnPlaylist.at(i)->GetName() << endl;
	}
}
void Playlist::FindSongInPlaylist(Song* song) {
	for (int i = 0; i < songsOnPlaylist.size(); ++i) {
		if (songsOnPlaylist.at(i) == song) {
			DeleteSongOnPlaylist(i);

		}
		else {

		}
	}

}