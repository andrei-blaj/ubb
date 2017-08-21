//
//  song.hpp
//  Seminar 3
//
//  Created by Andrei Blaj on 3/28/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#ifndef song_hpp
#define song_hpp

#include <stdio.h>
#include <string>

class Song {

private:
    std::string title; // title of the song
    std::string artist; // artist of the song
    int duration; // duration of the song
    std::string source; // link to youtube
public:
    Song();
    Song(const std::string &title, const std::string &artist, int &duration, const std::string &source);
    //~Song(); // destructor
    std::string getTitle() const { return this -> title; }
    std::string getArtist() const { return this -> artist; }
};

#endif /* song_hpp */
