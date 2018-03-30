//
//  ExamplePicker.swift
//  Sudoku AI
//
//  Created by Andrei-Sorin Blaj on 19/03/2018.
//  Copyright © 2018 Andrei-Sorin Blaj. All rights reserved.
//

import UIKit

extension ViewController: UIPickerViewDelegate, UIPickerViewDataSource {
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return examples.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return examples[row]
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        
        switch row {
        case 0:
            loadDefault()
        case 1:
            loadVeryEasy()
        case 2:
            loadEasy()
        case 3:
            loadMedium()
        case 4:
            loadHard()
        case 5:
            loadVeryHard()
        default:
            loadDefault()
        }
        
    }
    
}
