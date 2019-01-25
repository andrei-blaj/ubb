//
//  ViewController.swift
//  exam
//
//  Created by Andrei Blaj on 24/01/2019.
//  Copyright © 2019 Andrei-Sorin Blaj. All rights reserved.
//

import UIKit
import SVProgressHUD

class ViewController: UIViewController {

    @IBOutlet weak var songsTableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        songsTableView.delegate = self
        songsTableView.dataSource = self
        
        getAllSongs()
        setupNavigationBar()
        
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        songsTableView.reloadData()
    }
    
    func setupNavigationBar() {
        
        let addButton = UIButton(type: .system)
        
        addButton.setTitle("Add", for: .normal)
        addButton.tintColor = #colorLiteral(red: 0.9019607843, green: 0.4392156863, blue: 0.1176470588, alpha: 1)
        
        addButton.addTarget(self, action: #selector(onAddButtonPressed), for: .touchUpInside)
        
        addButton.titleLabel?.font = UIFont.systemFont(ofSize: 18)
        navigationItem.rightBarButtonItem = UIBarButtonItem(customView: addButton)
        
        //
        
        let filterButton = UIButton(type: .system)
        
        filterButton.setTitle("Filter", for: .normal)
        filterButton.tintColor = #colorLiteral(red: 0.9019607843, green: 0.4392156863, blue: 0.1176470588, alpha: 1)
        
        filterButton.addTarget(self, action: #selector(onFilterButtonPressed), for: .touchUpInside)
        
        filterButton.titleLabel?.font = UIFont.systemFont(ofSize: 18)
        navigationItem.rightBarButtonItems = [UIBarButtonItem(customView: addButton), UIBarButtonItem(customView: filterButton)]
        
        // ---------
        
        let favButton = UIButton(type: .system)
        
        favButton.setTitle("Favourites", for: .normal)
        favButton.tintColor = #colorLiteral(red: 0.9019607843, green: 0.4392156863, blue: 0.1176470588, alpha: 1)
        
        favButton.addTarget(self, action: #selector(onFavButtonPressed), for: .touchUpInside)
        
        favButton.titleLabel?.font = UIFont.systemFont(ofSize: 18)
        navigationItem.leftBarButtonItem = UIBarButtonItem(customView: favButton)
        
    }
    
    @objc func onAddButtonPressed() {
        performSegue(withIdentifier: "addSongSegue", sender: nil)
    }
    
    @objc func onFavButtonPressed() {
        performSegue(withIdentifier: "userFavSeg", sender: nil)
    }
    
    @objc func onFilterButtonPressed() {
        SVProgressHUD.show()
        DataService.shared.getGenres(successHandler: {
            print("✅ Genres retrieved.")
            let index = Int.random(in: 0 ..< Settings.shared.genres.count)
            DataService.shared.getSongs(forGenre: Settings.shared.genres[index], successHandler: { (songs) in
                SVProgressHUD.dismiss()
                Settings.shared.allSongs = songs
                self.songsTableView.reloadData()
                print("✅ Success! \(songs.count) songs retrieved.")
            }) {
                SVProgressHUD.dismiss()
                print("❗️ Failed to retrieve songs for genre.")
            }
        }) {
            SVProgressHUD.dismiss()
            print("❗️ Failed to retrieve genres.")
        }
    }
    
    func getGenres() {
        DataService.shared.getGenres(successHandler: {
            print("✅ Genres retrieved.")
        }) {
            print("❗️ Failed to retrieve genres.")
        }
    }
    
    func getSongs(forGenre genre: String) {
        DataService.shared.getSongs(forGenre: genre, successHandler: { (songs) in
            print("✅ Success! \(songs.count) songs retrieved.")
        }) {
            print("❗️ Failed to retrieve songs for genre.")
        }
    }
    
    func getAllSongs() {
        SVProgressHUD.show()
        DataService.shared.getAllSongs(successHandler: { (songs) in
            print("✅ Success! \(songs.count) songs retrieved.")
            Settings.shared.allSongs = songs
            self.songsTableView.reloadData()
            SVProgressHUD.dismiss()
        }) {
            print("❗️ Failed to retrieve songs for genre.")
            // Get from local storage
            Settings.shared.getFromRealm()
            self.songsTableView.reloadData()
            SVProgressHUD.dismiss()
        }
    }
    
}

extension ViewController: UITableViewDelegate, UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Settings.shared.allSongs.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        guard let cell = tableView.dequeueReusableCell(withIdentifier: "songCell", for: indexPath) as? SongCell else {
            return UITableViewCell()
        }
        
        let n = Settings.shared.allSongs.count
        
        let song = Settings.shared.allSongs[n - indexPath.row - 1]
        
        cell.setupCell(song: song)
        cell.selectionStyle = .none
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        let n = Settings.shared.allSongs.count
        if editingStyle == .delete {
            SVProgressHUD.show()
            if let id = Settings.shared.allSongs[n - indexPath.row - 1].id {
                DataService.shared.deleteSong(withId: id, successHandler: {
                    SVProgressHUD.dismiss()
                    Settings.shared.allSongs.remove(at: n - indexPath.row - 1)
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

