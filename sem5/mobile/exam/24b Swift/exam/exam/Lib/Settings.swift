//
//  Settings.swift
//  exam
//
//  Created by Andrei Blaj on 24/01/2019.
//  Copyright © 2019 Andrei-Sorin Blaj. All rights reserved.
//

import Foundation
import RealmSwift

class Settings {
    
    static let instance = Settings()
    
    class var shared: Settings {
        return instance
    }
    
    var genres: [String] = []
    var allSongs: [Song] = []
    var userFavourites: [Int: Song] = [:]
    var favourites: [Song] = []
    
    func removeFavourite(id: Int) {
        userFavourites.removeValue(forKey: id)
        if let song = userFavourites[id] {
            removeFavourite(song: song)
        }
    }
    
    func addFavourite(id: Int) {
        
        
        let songs = allSongs.filter({ $0.id == id })
        
        if songs.count > 0 {
            if let song = songs.first {
                userFavourites[id] = song
                addFavourite(song: song)
            }
        }
        
    }
    
    func addFavourite(song: Song) {
        let realm = try! Realm()

        if let id = song.id, let title = song.title, let description = song.description, let album = song.album, let year = song.year, let genre = song.genre {

            let elementExists = realm.objects(RealmObject.self).filter("id = '\(id)'").count > 0

            if !elementExists {
                let realmSong = RealmObject()

                realmSong.id = "\(id)"
                realmSong.title = title
                realmSong.songDescription = description
                realmSong.album = album
                realmSong.genre = genre
                realmSong.year = "\(year)"

                try! realm.write {
                    realm.add(realmSong)
                }
            }
        }
    }
    
    func removeFavourite(song: Song) {
        let realm = try! Realm()

        if let id = song.id {

            let object = realm.objects(RealmObject.self).filter("id = '\(id)'")

            if object.count == 1 {
                try! realm.write {
                    realm.delete(object)
                }
            }

        }

    }
    
    func removeAllFromRealm() {
        let realm = try! Realm()
        try! realm.write {
            realm.deleteAll()
        }
    }
    
    func getFromRealm() {
        Settings.shared.userFavourites = [:]
        Settings.shared.allSongs = []
        let realm = try! Realm()
        let realmSongs = realm.objects(RealmObject.self)
        for realmSong in realmSongs {
            if let id = realmSong.id, let title = realmSong.title, let description = realmSong.songDescription, let album = realmSong.album, let genre = realmSong.genre, let year = realmSong.year {
                
                let song = Song(id: Int(id)!, title: title, desc: description, album: album, genre: genre, year: Int(year)!)
                
                Settings.shared.userFavourites[Int(id)!] = song
                Settings.shared.allSongs.append(song)
            }
        }
    }
    
}
