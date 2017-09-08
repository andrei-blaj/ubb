#include "Repository.h"
#include <string>

using namespace std;

void Repository::addSong(const Song& s)
{
	this->songs.add(s);
}

Song Repository::findByArtistAndTitle(const std::string& artist, const std::string& title)
{
	Song* songsInDynamicVector = this->songs.getAllElems();
	if (songsInDynamicVector == NULL)
		return Song{};

	for (int i = 0; i < this->songs.getSize(); i++)
	{
		Song s = songsInDynamicVector[i];
		if (s.getArtist() == artist && s.getTitle() == title)
			return s;
	}

	return Song{};
}