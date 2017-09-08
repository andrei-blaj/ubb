#include "Tests.h"
#include <assert.h>
#include "DynamicVector.h"
#include "Repository.h"
#include "PlayList.h"
#include "Controller.h"

void Tests::testSong()
{
	Duration d{ 4, 54 };
	Song s{ "Ed Sheeran", "I see fire", d, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	assert(s.getArtist() == "Ed Sheeran");
	assert(s.getTitle() == "I see fire");
	assert(s.getSource() == "https://www.youtube.com/watch?v=2fngvQS_PmQ");
	assert(s.getDuration().getMinutes() == 4);
	assert(s.getDuration().getSeconds() == 54);
}

void Tests::testDynamicVector()
{
	DynamicVector<int> v1{ 2 };
	v1.add(10);
	v1.add(20);
	assert(v1.getSize() == 2);
	assert(v1[1] == 20);
	v1.add(30);
	assert(v1.getSize() == 3);

	DynamicVector<int> v2 = v1;
	assert(v2.getSize() == 3);

	DynamicVector<int> v3;
	v3 = v1;
	assert(v3[0] == 10);

	// test iterator
	DynamicVector<int>::iterator it = v1.begin();
	assert(*it == 10);
	assert(it != v1.end());
	it++;
	assert(*it == 20);
}

void Tests::testRepository()
{
	Repository repo{};
	Song s{ "Ed Sheeran", "I see fire", Duration{ 4, 54 }, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	repo.addSong(s);
	Song res = repo.findByArtistAndTitle("Ed Sheeran", "I see fire");
	assert(res.getTitle() == s.getTitle() && res.getArtist() == s.getArtist());
	res = repo.findByArtistAndTitle("Ed Sheeran", "");
	assert(res.getArtist() == "");

	DynamicVector<Song> songs = repo.getSongs();
	assert(songs.getSize() == 1);
}

void Tests::testPlaylist()
{
	PlayList playList{};
	Song s1{ "Ed Sheeran", "I see fire", Duration{ 4, 54 }, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	Song s2{ "Two Steps From Hell", "Heart of Courage", Duration{ 8, 12 }, "https://www.youtube.com/watch?v=XYKUeZQbMF0" };
	playList.add(s1);
	playList.add(s2);

	assert(playList.isEmpty() == false);

	/*playList.play();
	assert(playList.getCurrentSong().getArtist() == "Ed Sheeran");
	playList.next();
	assert(playList.getCurrentSong().getArtist() == "Two Steps From Hell");
	playList.next();
	assert(playList.getCurrentSong().getArtist() == "Ed Sheeran");*/
}

void Tests::testController()
{
	Repository repo{};
	Controller ctrl{ repo };
	ctrl.addSongToRepository("Ed Sheeran", "I see fire", 4, 54, "https://www.youtube.com/watch?v=2fngvQS_PmQ");
	ctrl.addSongToRepository("Two Steps From Hell", "Heart of Courage", 8, 12, "https://www.youtube.com/watch?v=XYKUeZQbMF0");
	Song s{ "Ed Sheeran", "I see fire", Duration{ 4, 54 }, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	ctrl.addSongToPlaylist(s);
	ctrl.addAllSongsByArtistToPlaylist("Two Steps From Hell");

	assert(ctrl.getRepo().getSongs().getSize() == 2);
	
	PlayList list = ctrl.getPlaylist();
	assert(list.isEmpty() == false);
	assert(list.getCurrentSong().getArtist() == "Ed Sheeran");

	ctrl.startPlaylist();
	ctrl.nextSongPlaylist();	
}

void Tests::testAll()
{
	testSong();
	testDynamicVector();
	testRepository();
	testPlaylist();
	testController();
}
