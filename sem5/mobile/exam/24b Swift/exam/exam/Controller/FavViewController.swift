//
//  FavViewController.swift
//  exam
//
//  Created by Andrei Blaj on 24/01/2019.
//  Copyright © 2019 Andrei-Sorin Blaj. All rights reserved.
//


import UIKit
import SVProgressHUD

class FavViewController: UIViewController {
    
    @IBOutlet weak var songsTableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        songsTableView.delegate = self
        songsTableView.dataSource = self
        
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        Settings.shared.favourites = []
        
        for song in Settings.shared.userFavourites.values {
            Settings.shared.favourites.append(song)
        }
        
        songsTableView.reloadData()
    }
    
}

extension FavViewController: UITableViewDelegate, UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Settings.shared.favourites.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        guard let cell = tableView.dequeueReusableCell(withIdentifier: "songCell", for: indexPath) as? SongCell else {
            return UITableViewCell()
        }
        
        let n = Settings.shared.favourites.count
        
        let song = Settings.shared.favourites[n - indexPath.row - 1]
        
        cell.setupCell(song: song)
        cell.selectionStyle = .none
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        let n = Settings.shared.allSongs.count
        if editingStyle == .delete {
            SVProgressHUD.show()
            if let id = Settings.shared.favourites[n - indexPath.row - 1].id {
                DataService.shared.deleteSong(withId: id, successHandler: {
                    SVProgressHUD.dismiss()
                    Settings.shared.favourites.remove(at: n - indexPath.row - 1)
                    tableView.deleteRows(at: [indexPath], with: .fade)
                }) {
                    SVProgressHUD.dismiss()
                    self.displayError(message: "Could not delete, error occured")
                }
            } else {
                self.displayError(message: "Could not delete, could not find movie")
            }
        }
    }
    
    func displayError(message: String) {
        let alert = UIAlertController(title: nil, message: message, preferredStyle: UIAlertController.Style.alert)
        alert.addAction(UIAlertAction(title: "Dismiss", style: UIAlertAction.Style.default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }
    
}


