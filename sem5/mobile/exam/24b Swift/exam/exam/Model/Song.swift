//
//  Song.swift
//  exam
//
//  Created by Andrei Blaj on 24/01/2019.
//  Copyright © 2019 Andrei-Sorin Blaj. All rights reserved.
//

import Foundation
import SwiftyJSON

class Song {
    
    public private(set) var id: Int?
    public private(set) var title: String?
    public private(set) var description: String?
    public private(set) var album: String?
    public private(set) var genre: String?
    public private(set) var year: Int?
    
    init(json: JSON) {
        id = json["id"].intValue
        title = json["title"].stringValue
        description = json["descrption"].stringValue
        album = json["album"].stringValue
        genre = json["genre"].stringValue
        year = json["year"].int
    }
    
    init(id: Int, title: String, desc: String, album: String, genre: String, year: Int) {
        self.id = id
        self.title = title
        self.description = desc
        self.album = album
        self.genre = genre
        self.year = year
    }
    
}
