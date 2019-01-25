//
//  AddSongViewController.swift
//  exam
//
//  Created by Andrei Blaj on 24/01/2019.
//  Copyright © 2019 Andrei-Sorin Blaj. All rights reserved.
//

import UIKit

class AddSongViewController: UIViewController {

    @IBOutlet weak var titleTextField: UITextField!
    @IBOutlet weak var descriptionTextField: UITextField!
    @IBOutlet weak var albumTextField: UITextField!
    @IBOutlet weak var genreTextField: UITextField!
    @IBOutlet weak var yearTextField: UITextField!
    
    @IBOutlet weak var addSongButton: UIButton!
    
    @IBAction func onAddSongButtonPressed(_ sender: UIButton) {
        
        if let title = titleTextField.text, let description = descriptionTextField.text, let album = albumTextField.text, let genre = genreTextField.text, let year = yearTextField.text {
            
            if let intYear = Int(year) {
            
                DataService.shared.addSong(title: title, description: description, album: album, genre: genre, year: intYear, successHandler: { (songs) in
                    
                    if songs.count > 0 {
                        if let song = songs.first {
                            Settings.shared.allSongs.append(song)
                            self.navigationController?.popViewController(animated: true)
                        }
                    } else {
                        self.displayError(message: "Song already exists")
                    }
                    
                }) {
                    self.displayError(message: "Could not add song")
                }
            } else {
                displayError(message: "Year must be an integer")
            }
            
            
        } else {
            displayError(message: "Error")
        }
        
    }
    
    func displayError(message: String) {
        let alert = UIAlertController(title: nil, message: message, preferredStyle: UIAlertController.Style.alert)
        alert.addAction(UIAlertAction(title: "Dismiss", style: UIAlertAction.Style.default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

}
