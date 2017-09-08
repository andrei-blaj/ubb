//
//  main.cpp
//  Seminar 3
//
//  Created by Andrei Blaj on 3/28/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#include <iostream>
#include "song.cpp"
#include "DynamicVector.hpp"
#include <assert.h>

void testSong() {
    //Song s { "Title", "Artist", 100, "www.youtube.com" };
    //assert(s.getTitle() == "Title");
}

void testDynamicVector() {
    
    DynamicVector<Song> songs{ 1 };
    
    //Song s1{"TItle1", "Artist1", 10, "www.youtube.com"};
    //Song s2{"Title2", "Artist2", 15, "www.youtube.com"};
    
    //songs.AddElement(s1);
    //songs.AddElement(s2);
    
    assert(songs.getSize() == 2);
    
    DynamicVector<Song> v{};
    
    
}

int main() {
    
    testSong();
    testDynamicVector();
    
    return 0;
}

