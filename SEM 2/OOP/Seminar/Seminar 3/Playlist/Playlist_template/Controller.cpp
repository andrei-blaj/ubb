#include "Controller.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

void Controller::addSongToRepository(const std::string& artist, const std::string& title, double minutes, double seconds, const std::string& source)
{
	Song s{ artist, title, Duration{minutes, seconds}, source };
	this->repo.addSong(s);
}

void Controller::addSongToPlaylist(const Song& song)
{
	this->playList.add(song);
}

void Controller::addAllSongsByArtistToPlaylist(const std::string& artist)
{
	// get all the songs from the repository
	DynamicVector<Song> songs = this->repo.getSongs();
	/*for (int i = 0; i < songs.getSize(); i++)
	{
		Song s = songs[i];
		if (s.getArtist() == artist)
			this->playList.add(s);
	}*/
	
	for (DynamicVector<Song>::iterator it = songs.begin(); it != songs.end(); it++)
	{
		if (it->getArtist() == artist)
			this->playList.add(*it);
	}

	/*int songsByArtist = static_cast<int>(std::count_if(songs.begin(), songs.end(), [artist](Song s) {return s.getArtist() == artist; }));
	DynamicVector<Song> result;
	result.setSize(songsByArtist);
	std::copy_if(songs.begin(), songs.end(), result.begin(), [artist](Song s) {return s.getArtist() == artist; });
	for (auto it = result.begin(); it != result.end(); it++)
		this->playList.add(*it);*/
}

void Controller::startPlaylist()
{
	this->playList.play();
}

void Controller::nextSongPlaylist()
{
	this->playList.next();
}