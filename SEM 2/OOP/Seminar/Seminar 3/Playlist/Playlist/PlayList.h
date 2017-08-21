#pragma once
#include "DynamicVector.h"

class PlayList
{
private:
	DynamicVector songs;
	int current;

public:
	PlayList();

	// Adds a song to the playlist.
	void add(const Song& song);

	// Returns the song that is currently playing.
	Song PlayList::getCurrentSong();

	// Starts the playlist - plays the first song.
	void play();

	// Plays the next song in the playlist.
	void next();

	// Checks if the playlist is empty.
	bool isEmpty();
};

