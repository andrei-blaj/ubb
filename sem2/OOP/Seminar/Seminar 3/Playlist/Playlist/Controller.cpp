#include "Controller.h"

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
	DynamicVector v = this->repo.getSongs();
	Song* songs = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++)
	{
		Song s = songs[i];
		if (s.getArtist() == artist)
			this->playList.add(s);
	}
}

void Controller::startPlaylist()
{
	this->playList.play();
}

void Controller::nextSongPlaylist()
{
	this->playList.next();
}