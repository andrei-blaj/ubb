#include "PlayList.h"


PlayList::PlayList()
{
	this->current = 0;
}

void PlayList::add(const Song& song)
{
	this->songs.add(song);
}

Song PlayList::getCurrentSong()
{
	if (this->current == this->songs.getSize())
		this->current = 0;
	Song* elems = this->songs.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Song{};
}

void PlayList::play()
{
	if (this->songs.getSize() == 0)
		return;
	this->current = 0;
	Song currentSong = this->getCurrentSong();
	currentSong.play();
}

void PlayList::next()
{
	if (this->songs.getSize() == 0)
		return;
	this->current++;
	Song currentSong = this->getCurrentSong();
	currentSong.play();
}

bool PlayList::isEmpty()
{
	return this->songs.getSize() == 0;
}