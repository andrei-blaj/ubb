//
//  song.cpp
//  Seminar 3
//
//  Created by Andrei Blaj on 3/28/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#include "song.hpp"

Song::Song(const std::string &title, const std::string &artist, int &duration, const std::string &source) {
    
    this -> title = title;
    this -> artist = artist;
    this -> duration = duration;
    this -> source = source;
    
}

Song::Song() {
    
    this -> title = "";
    this -> artist = "";
    this -> duration = 0;
    this -> source = "";
}
