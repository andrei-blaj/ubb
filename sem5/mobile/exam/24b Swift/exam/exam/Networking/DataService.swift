//
//  DataService.swift
//  exam
//
//  Created by Andrei Blaj on 24/01/2019.
//  Copyright © 2019 Andrei-Sorin Blaj. All rights reserved.
//

import Foundation
import Alamofire
import AlamofireImage
import RealmSwift
import SwiftyJSON

class DataService {
    
    static let instance = DataService()
    
    class var shared: DataService {
        return instance
    }
    
    func getGenres(successHandler: @escaping (() -> Void), failureHandler: @escaping (() -> Void)) {
        
        let url = "\(BASE_URL)/genres"
        
        Alamofire.request(url, method: .get).responseJSON { (response) in
            switch response.result {
            case .success(let data):
                let json = JSON(data)
                
                if let genres = json.array {
                    for genre in genres {
                        Settings.shared.genres.append(genre.stringValue)
                    }
                }
                
                successHandler()
            case .failure( _):
                failureHandler()
            }
        }
        
    }
    
    func getSongs(forGenre genre: String, successHandler: @escaping (([Song]) -> Void), failureHandler: @escaping (() -> Void)) {
        
        let url = "\(BASE_URL)/songs/\(genre)"
        
        Alamofire.request(url, method: .get).responseJSON { (response) in
            switch response.result {
            case .success(let data):
                let json = JSON(data)
                
                var songs: [Song] = []
                
                if let jsonSongs = json.array {
                    for song in jsonSongs {
                        songs.append(Song(json: song))
                    }
                }
                
                successHandler(songs)
            case .failure( _):
                failureHandler()
            }
        }
        
    }
    
    func getAllSongs(successHandler: @escaping (([Song]) -> Void), failureHandler: @escaping (() -> Void)) {
        
        let url = "\(BASE_URL)/all"
        
        Alamofire.request(url, method: .get).responseJSON { (response) in
            switch response.result {
            case .success(let data):
                let json = JSON(data)
                
                var songs: [Song] = []
                
                if let jsonSongs = json.array {
                    for song in jsonSongs {
                        songs.append(Song(json: song))
                    }
                }
                
                successHandler(songs)
            case .failure( _):
                failureHandler()
            }
        }
        
    }
    
    func addSong(title: String, description: String, album: String, genre: String, year: Int, successHandler: @escaping (([Song]) -> Void), failureHandler: @escaping (() -> Void)) {
        
        let params: Parameters = ["title": title, "description": description, "album": album, "genre": genre, "year": year]
        
        let url = "\(BASE_URL)/song"
        
        Alamofire.request(url, method: .post, parameters: params, encoding: URLEncoding.httpBody).responseJSON { (response) in
            switch response.result {
            case .success(let data):
                let json = JSON(data)
                var songs: [Song] = []
                
                songs.append(Song(json: json))
                
                successHandler(songs)
            case .failure( _):
                failureHandler()
            }
        }
        
    }
    
    func deleteSong(withId id: Int, successHandler: @escaping (() -> Void), failureHandler: @escaping (() -> Void)) {
        
        let url = "\(BASE_URL)/song/\(id)"
        
        Alamofire.request(url, method: .delete, encoding: JSONEncoding.default).responseData(completionHandler: { (response) in
            switch response.result {
            case .success( _):
                successHandler()
            case .failure( _):
                failureHandler()
            }
        })
        
    }
    
}
