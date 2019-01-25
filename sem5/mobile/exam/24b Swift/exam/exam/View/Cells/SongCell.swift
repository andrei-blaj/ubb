//
//  SongCell.swift
//  exam
//
//  Created by Andrei Blaj on 24/01/2019.
//  Copyright © 2019 Andrei-Sorin Blaj. All rights reserved.
//

import UIKit

class SongCell: UITableViewCell {

    @IBOutlet weak var songTitle: UILabel!
    @IBOutlet weak var songDetails: UILabel!
    @IBOutlet weak var favouriteButton: UIButton!
    
    @IBAction func onFavouriteButtonPressed(_ sender: UIButton) {
        let songId = sender.tag
        
        if Settings.shared.userFavourites[songId] != nil {
            favouriteButton.setImage(UIImage(named: "favourite.png"), for: .normal)
            Settings.shared.removeFavourite(id: songId)
        } else {
            Settings.shared.addFavourite(id: songId)
            favouriteButton.setImage(UIImage(named: "favourite_checked.png"), for: .normal)
        }
        
    }
    
    func setupCell(song: Song) {
        
        if let title = song.title {
            songTitle.text = title
        }
        
        if let album = song.album, let genre = song.genre, let year = song.year {
            songDetails.text = "\(album) • \(genre) • \(year)"
        }
        
        if let id = song.id {
            
            favouriteButton.tag = id
            
            if Settings.shared.userFavourites[id] != nil {
                favouriteButton.setImage(UIImage(named: "favourite_checked.png"), for: .normal)
            } else {
                favouriteButton.setImage(UIImage(named: "favourite.png"), for: .normal)
            }
        }
    }

}
