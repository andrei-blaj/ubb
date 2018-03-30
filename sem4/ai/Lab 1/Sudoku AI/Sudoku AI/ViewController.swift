//
//  ViewController.swift
//  Sudoku AI
//
//  Created by Andrei-Sorin Blaj on 18/03/2018.
//  Copyright © 2018 Andrei-Sorin Blaj. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    // Variables
    var sudoku: [[Int]] = [[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0]]
    var solutionsCount: [Int] = [0,0,0,0,0,0,0,0,0,0]
    var numberOfEmptySquares = 0
    
    var missingNumbers = [0,0,0,0,0,0,0,0,0,0]
    var existingNumbers = [0,0,0,0,0,0,0,0,0,0]
    
    var examples = ["Default", "Very Easy", "Easy", "Medium", "Hard", "Very Hard"]
    
    @IBOutlet weak var exampleField: UITextField!
    
    // Line 1
    @IBOutlet weak var sudoku00: UITextField!
    @IBOutlet weak var sudoku01: UITextField!
    @IBOutlet weak var sudoku02: UITextField!
    @IBOutlet weak var sudoku03: UITextField!
    @IBOutlet weak var sudoku04: UITextField!
    @IBOutlet weak var sudoku05: UITextField!
    @IBOutlet weak var sudoku06: UITextField!
    @IBOutlet weak var sudoku07: UITextField!
    @IBOutlet weak var sudoku08: UITextField!
    
    // Line 2
    @IBOutlet weak var sudoku10: UITextField!
    @IBOutlet weak var sudoku11: UITextField!
    @IBOutlet weak var sudoku12: UITextField!
    @IBOutlet weak var sudoku13: UITextField!
    @IBOutlet weak var sudoku14: UITextField!
    @IBOutlet weak var sudoku15: UITextField!
    @IBOutlet weak var sudoku16: UITextField!
    @IBOutlet weak var sudoku17: UITextField!
    @IBOutlet weak var sudoku18: UITextField!
    
    // Line 3
    @IBOutlet weak var sudoku20: UITextField!
    @IBOutlet weak var sudoku21: UITextField!
    @IBOutlet weak var sudoku22: UITextField!
    @IBOutlet weak var sudoku23: UITextField!
    @IBOutlet weak var sudoku24: UITextField!
    @IBOutlet weak var sudoku25: UITextField!
    @IBOutlet weak var sudoku26: UITextField!
    @IBOutlet weak var sudoku27: UITextField!
    @IBOutlet weak var sudoku28: UITextField!
    
    // Line 4
    @IBOutlet weak var sudoku30: UITextField!
    @IBOutlet weak var sudoku31: UITextField!
    @IBOutlet weak var sudoku32: UITextField!
    @IBOutlet weak var sudoku33: UITextField!
    @IBOutlet weak var sudoku34: UITextField!
    @IBOutlet weak var sudoku35: UITextField!
    @IBOutlet weak var sudoku36: UITextField!
    @IBOutlet weak var sudoku37: UITextField!
    @IBOutlet weak var sudoku38: UITextField!
    
    // Line 5
    @IBOutlet weak var sudoku40: UITextField!
    @IBOutlet weak var sudoku41: UITextField!
    @IBOutlet weak var sudoku42: UITextField!
    @IBOutlet weak var sudoku43: UITextField!
    @IBOutlet weak var sudoku44: UITextField!
    @IBOutlet weak var sudoku45: UITextField!
    @IBOutlet weak var sudoku46: UITextField!
    @IBOutlet weak var sudoku47: UITextField!
    @IBOutlet weak var sudoku48: UITextField!
    
    // Line 6
    @IBOutlet weak var sudoku50: UITextField!
    @IBOutlet weak var sudoku51: UITextField!
    @IBOutlet weak var sudoku52: UITextField!
    @IBOutlet weak var sudoku53: UITextField!
    @IBOutlet weak var sudoku54: UITextField!
    @IBOutlet weak var sudoku55: UITextField!
    @IBOutlet weak var sudoku56: UITextField!
    @IBOutlet weak var sudoku57: UITextField!
    @IBOutlet weak var sudoku58: UITextField!
    
    // Line 7
    @IBOutlet weak var sudoku60: UITextField!
    @IBOutlet weak var sudoku61: UITextField!
    @IBOutlet weak var sudoku62: UITextField!
    @IBOutlet weak var sudoku63: UITextField!
    @IBOutlet weak var sudoku64: UITextField!
    @IBOutlet weak var sudoku65: UITextField!
    @IBOutlet weak var sudoku66: UITextField!
    @IBOutlet weak var sudoku67: UITextField!
    @IBOutlet weak var sudoku68: UITextField!
    
    // Line 8
    @IBOutlet weak var sudoku70: UITextField!
    @IBOutlet weak var sudoku71: UITextField!
    @IBOutlet weak var sudoku72: UITextField!
    @IBOutlet weak var sudoku73: UITextField!
    @IBOutlet weak var sudoku74: UITextField!
    @IBOutlet weak var sudoku75: UITextField!
    @IBOutlet weak var sudoku76: UITextField!
    @IBOutlet weak var sudoku77: UITextField!
    @IBOutlet weak var sudoku78: UITextField!
    
    // Line 9
    @IBOutlet weak var sudoku80: UITextField!
    @IBOutlet weak var sudoku81: UITextField!
    @IBOutlet weak var sudoku82: UITextField!
    @IBOutlet weak var sudoku83: UITextField!
    @IBOutlet weak var sudoku84: UITextField!
    @IBOutlet weak var sudoku85: UITextField!
    @IBOutlet weak var sudoku86: UITextField!
    @IBOutlet weak var sudoku87: UITextField!
    @IBOutlet weak var sudoku88: UITextField!
    
    // ViewDidLoad
    override func viewDidLoad() {
        super.viewDidLoad()
        
        createExamplePicker()
    }
    
    func createExamplePicker() {
        let examplePicker = UIPickerView()
        examplePicker.delegate = self
        
        exampleField.inputView = examplePicker
        
        // customizations
        examplePicker.backgroundColor = .white
        
    }
    
    @IBAction func onLoadButtonPressed(_ sender: Any) {
        loadDefault()
    }
    
    @IBAction func onClearButtonPressed(_ sender: Any) {
        clearCells()
    }
    
    @IBAction func onGenerateSolutionPressed(_ sender: Any) {
        populateFromUserInput()
        generateSolution()
    }

    func getNumberOfEmptySquares() {
        
        numberOfEmptySquares = 0
        
        for i in 0..<9 {
            for j in 0..<9 {
                if sudoku[i][j] == 0 {
                    numberOfEmptySquares += 1
                } else {
                    existingNumbers[sudoku[i][j]] += 1
                }
            }
        }
        
        for i in 1..<10 {
            missingNumbers[i] = 9 - existingNumbers[i]
        }
    }
    
    func generateSolution() {
        
        getNumberOfEmptySquares()
        
        var cnt = 0
        
        while numberOfEmptySquares > 0 {
        
            for i in 0..<9 {
                for v in 1..<10 {
                    for s in 1..<10 {
                        solutionsCount[s] = 0
                    }
                    for j in 0..<9 {
                        if sudoku[i][j] == 0 {
                            
                            if !checkIf(line: i, hasValue: v) && !checkIf(column: j, hasValue: v) && !checkBoxContaining(line: i, andColumn: j, forValue: v) {
                                solutionsCount[v] += 1
                            }
                            
                        } else {
                            updateCell(onLine: i, andColumn: j, withValue: sudoku[i][j])
                        }
                    }
                    
                    if solutionsCount[v] == 1 {
                        
                        for j in 0..<9 {
                            if sudoku[i][j] == 0 {
                                
                                if !checkIf(line: i, hasValue: v) && !checkIf(column: j, hasValue: v) && !checkBoxContaining(line: i, andColumn: j, forValue: v) {
                                    sudoku[i][j] = v
                                    updateCell(onLine: i, andColumn: j, withValue: v)
                                    numberOfEmptySquares -= 1
                                    break
                                }
                                
                            } else {
                                updateCell(onLine: i, andColumn: j, withValue: sudoku[i][j])
                            }
                        }
                       
                    }
                    
                }
            }
            
            cnt += 1
            
            if cnt == 81 {
                break
            }
        
        }
        
    }
 
    func checkIf(line i: Int, hasValue x: Int) -> Bool {
        
        for j in 0..<9 {
            if sudoku[i][j] == x {
                return true
            }
        }
        
        return false
        
    }
    
    func checkIf(column j: Int, hasValue x: Int) -> Bool {
        
        for i in 0..<9 {
            if sudoku[i][j] == x {
                return true
            }
        }
        
        return false
        
    }
    
    func checkBoxContaining(line i: Int, andColumn j: Int, forValue x: Int) -> Bool {
        
        if i < 3 {
            
            if j < 3 {
                
                for h in 0..<3 {
                    for k in 0..<3 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            } else if j < 6 {
                
                for h in 0..<3 {
                    for k in 3..<6 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            } else {
                
                for h in 0..<3 {
                    for k in 6..<9 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            }
            
        } else if i < 6 {
            
            if j < 3 {
                
                for h in 3..<6 {
                    for k in 0..<3 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            } else if j < 6 {
                
                for h in 3..<6 {
                    for k in 3..<6 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            } else {
                
                for h in 3..<6 {
                    for k in 6..<9 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            }
            
        } else {
            
            if j < 3 {
                
                for h in 6..<9 {
                    for k in 0..<3 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            } else if j < 6 {
                
                for h in 6..<9 {
                    for k in 3..<6 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            } else {
                
                for h in 6..<9 {
                    for k in 6..<9 {
                        if sudoku[h][k] == x {
                            return true
                        }
                    }
                }
                
            }
            
        }
        
        
        return false
    }

}
