//
//  SudokuCellOperations.swift
//  Sudoku AI
//
//  Created by Andrei-Sorin Blaj on 19/03/2018.
//  Copyright © 2018 Andrei-Sorin Blaj. All rights reserved.
//

import UIKit

extension ViewController {
    
    func loadDefault() {
        sudoku00.text = ""
        sudoku01.text = "2"
        sudoku01.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku02.text = ""
        sudoku03.text = "6"
        sudoku03.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku04.text = ""
        sudoku05.text = "8"
        sudoku05.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku06.text = ""
        sudoku07.text = ""
        sudoku08.text = "5"
        sudoku08.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        
        sudoku10.text = "5"
        sudoku10.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku11.text = "8"
        sudoku11.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku12.text = ""
        sudoku13.text = ""
        sudoku14.text = ""
        sudoku15.text = "9"
        sudoku15.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku16.text = "7"
        sudoku16.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku17.text = ""
        sudoku18.text = ""
        
        sudoku20.text = ""
        sudoku21.text = ""
        sudoku22.text = "7"
        sudoku22.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku23.text = ""
        sudoku24.text = "4"
        sudoku24.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku25.text = ""
        sudoku26.text = ""
        sudoku27.text = "2"
        sudoku27.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku28.text = "8"
        sudoku28.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        
        sudoku30.text = "3"
        sudoku30.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku31.text = "7"
        sudoku31.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku32.text = ""
        sudoku33.text = "4"
        sudoku33.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku34.text = ""
        sudoku35.text = "1"
        sudoku35.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku36.text = "5"
        sudoku36.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku37.text = ""
        sudoku38.text = ""
        
        sudoku40.text = "6"
        sudoku40.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku41.text = ""
        sudoku42.text = ""
        sudoku43.text = ""
        sudoku44.text = "8"
        sudoku44.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku45.text = ""
        sudoku46.text = ""
        sudoku47.text = ""
        sudoku48.text = ""
        
        sudoku50.text = ""
        sudoku51.text = ""
        sudoku52.text = "8"
        sudoku52.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku53.text = ""
        sudoku54.text = ""
        sudoku55.text = "2"
        sudoku55.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku56.text = ""
        sudoku57.text = "1"
        sudoku57.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku58.text = "3"
        sudoku58.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        
        sudoku60.text = "8"
        sudoku60.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku61.text = ""
        sudoku62.text = "6"
        sudoku62.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku63.text = ""
        sudoku64.text = "2"
        sudoku64.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku65.text = ""
        sudoku66.text = "1"
        sudoku66.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku67.text = ""
        sudoku68.text = ""
        
        sudoku70.text = ""
        sudoku71.text = ""
        sudoku72.text = "9"
        sudoku72.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku73.text = "8"
        sudoku73.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku74.text = ""
        sudoku75.text = ""
        sudoku76.text = ""
        sudoku77.text = "3"
        sudoku77.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku78.text = "6"
        sudoku78.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        
        sudoku80.text = "7"
        sudoku80.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku81.text = ""
        sudoku82.text = ""
        sudoku83.text = "3"
        sudoku83.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku84.text = ""
        sudoku85.text = "6"
        sudoku85.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku86.text = ""
        sudoku87.text = "9"
        sudoku87.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        sudoku88.text = ""
    }
    
    func clearCells() {
        
        for i in 0..<9 {
            for j in 0..<9 {
                sudoku[i][j] = 0
            }
        }
        
        sudoku00.text = ""
        sudoku00.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku01.text = ""
        sudoku01.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku02.text = ""
        sudoku02.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku03.text = ""
        sudoku03.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku04.text = ""
        sudoku04.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku05.text = ""
        sudoku05.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku06.text = ""
        sudoku06.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku07.text = ""
        sudoku07.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku08.text = ""
        sudoku08.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        
        sudoku10.text = ""
        sudoku10.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku11.text = ""
        sudoku11.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku12.text = ""
        sudoku12.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku13.text = ""
        sudoku13.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku14.text = ""
        sudoku14.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku15.text = ""
        sudoku15.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku16.text = ""
        sudoku16.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku17.text = ""
        sudoku17.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku18.text = ""
        sudoku18.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        
        sudoku20.text = ""
        sudoku20.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku21.text = ""
        sudoku21.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku22.text = ""
        sudoku22.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku23.text = ""
        sudoku23.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku24.text = ""
        sudoku24.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku25.text = ""
        sudoku25.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku26.text = ""
        sudoku26.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku27.text = ""
        sudoku27.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku28.text = ""
        sudoku28.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        
        sudoku30.text = ""
        sudoku30.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku31.text = ""
        sudoku31.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku32.text = ""
        sudoku32.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku33.text = ""
        sudoku33.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku34.text = ""
        sudoku34.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku35.text = ""
        sudoku35.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku36.text = ""
        sudoku36.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku37.text = ""
        sudoku37.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku38.text = ""
        sudoku38.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        
        sudoku40.text = ""
        sudoku40.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku41.text = ""
        sudoku41.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku42.text = ""
        sudoku42.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku43.text = ""
        sudoku43.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku44.text = ""
        sudoku44.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku45.text = ""
        sudoku45.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku46.text = ""
        sudoku46.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku47.text = ""
        sudoku47.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku48.text = ""
        sudoku48.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        
        sudoku50.text = ""
        sudoku50.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku51.text = ""
        sudoku51.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku52.text = ""
        sudoku52.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku53.text = ""
        sudoku53.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku54.text = ""
        sudoku54.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku55.text = ""
        sudoku55.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku56.text = ""
        sudoku56.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku57.text = ""
        sudoku57.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku58.text = ""
        sudoku58.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        
        sudoku60.text = ""
        sudoku60.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku61.text = ""
        sudoku61.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku62.text = ""
        sudoku62.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku63.text = ""
        sudoku63.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku64.text = ""
        sudoku64.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku65.text = ""
        sudoku65.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku66.text = ""
        sudoku66.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku67.text = ""
        sudoku67.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku68.text = ""
        sudoku68.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        
        sudoku70.text = ""
        sudoku70.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku71.text = ""
        sudoku71.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku72.text = ""
        sudoku72.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku73.text = ""
        sudoku73.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku74.text = ""
        sudoku74.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku75.text = ""
        sudoku75.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku76.text = ""
        sudoku76.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku77.text = ""
        sudoku77.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku78.text = ""
        sudoku78.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        
        sudoku80.text = ""
        sudoku80.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku81.text = ""
        sudoku81.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku82.text = ""
        sudoku82.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku83.text = ""
        sudoku83.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku84.text = ""
        sudoku84.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku85.text = ""
        sudoku85.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku86.text = ""
        sudoku86.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku87.text = ""
        sudoku87.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
        sudoku88.text = ""
        sudoku88.textColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 1)
    }
    
    func populateFromUserInput() {
        if sudoku00.text != "" {
            sudoku[0][0] = Int(sudoku00.text!)!
            sudoku00.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku01.text != "" {
            sudoku[0][1] = Int(sudoku01.text!)!
            sudoku01.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku02.text != "" {
            sudoku[0][2] = Int(sudoku02.text!)!
            sudoku02.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku03.text != "" {
            sudoku[0][3] = Int(sudoku03.text!)!
            sudoku03.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku04.text != "" {
            sudoku[0][4] = Int(sudoku04.text!)!
            sudoku04.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku05.text != "" {
            sudoku[0][5] = Int(sudoku05.text!)!
            sudoku05.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku06.text != "" {
            sudoku[0][6] = Int(sudoku06.text!)!
            sudoku06.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku07.text != "" {
            sudoku[0][7] = Int(sudoku07.text!)!
            sudoku07.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku08.text != "" {
            sudoku[0][8] = Int(sudoku08.text!)!
            sudoku08.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
        if sudoku10.text != "" {
            sudoku[1][0] = Int(sudoku10.text!)!
            sudoku10.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku11.text != "" {
            sudoku[1][1] = Int(sudoku11.text!)!
            sudoku11.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku12.text != "" {
            sudoku[1][2] = Int(sudoku12.text!)!
            sudoku12.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku13.text != "" {
            sudoku[1][3] = Int(sudoku13.text!)!
            sudoku13.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku14.text != "" {
            sudoku[1][4] = Int(sudoku14.text!)!
            sudoku14.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku15.text != "" {
            sudoku[1][5] = Int(sudoku15.text!)!
            sudoku15.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku16.text != "" {
            sudoku[1][6] = Int(sudoku16.text!)!
            sudoku16.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku17.text != "" {
            sudoku[1][7] = Int(sudoku17.text!)!
            sudoku17.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku18.text != "" {
            sudoku[1][8] = Int(sudoku18.text!)!
            sudoku18.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
        if sudoku20.text != "" {
            sudoku[2][0] = Int(sudoku20.text!)!
            sudoku20.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku21.text != "" {
            sudoku[2][1] = Int(sudoku21.text!)!
            sudoku21.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku22.text != "" {
            sudoku[2][2] = Int(sudoku22.text!)!
            sudoku22.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku23.text != "" {
            sudoku[2][3] = Int(sudoku23.text!)!
            sudoku23.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku24.text != "" {
            sudoku[2][4] = Int(sudoku24.text!)!
            sudoku24.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku25.text != "" {
            sudoku[2][5] = Int(sudoku25.text!)!
            sudoku25.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku26.text != "" {
            sudoku[2][6] = Int(sudoku26.text!)!
            sudoku26.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku27.text != "" {
            sudoku[2][7] = Int(sudoku27.text!)!
            sudoku27.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku28.text != "" {
            sudoku[2][8] = Int(sudoku28.text!)!
            sudoku28.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
        if sudoku30.text != "" {
            sudoku[3][0] = Int(sudoku30.text!)!
            sudoku30.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku31.text != "" {
            sudoku[3][1] = Int(sudoku31.text!)!
            sudoku31.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku32.text != "" {
            sudoku[3][2] = Int(sudoku32.text!)!
            sudoku32.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku33.text != "" {
            sudoku[3][3] = Int(sudoku33.text!)!
            sudoku33.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku34.text != "" {
            sudoku[3][4] = Int(sudoku34.text!)!
            sudoku34.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku35.text != "" {
            sudoku[3][5] = Int(sudoku35.text!)!
            sudoku35.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku36.text != "" {
            sudoku[3][6] = Int(sudoku36.text!)!
            sudoku36.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku37.text != "" {
            sudoku[3][7] = Int(sudoku37.text!)!
            sudoku37.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku38.text != "" {
            sudoku[3][8] = Int(sudoku38.text!)!
            sudoku38.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
        if sudoku40.text != "" {
            sudoku[4][0] = Int(sudoku40.text!)!
            sudoku40.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku41.text != "" {
            sudoku[4][1] = Int(sudoku41.text!)!
            sudoku41.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku42.text != "" {
            sudoku[4][2] = Int(sudoku42.text!)!
            sudoku42.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku43.text != "" {
            sudoku[4][3] = Int(sudoku43.text!)!
            sudoku43.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku44.text != "" {
            sudoku[4][4] = Int(sudoku44.text!)!
            sudoku44.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku45.text != "" {
            sudoku[4][5] = Int(sudoku45.text!)!
            sudoku45.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku46.text != "" {
            sudoku[4][6] = Int(sudoku46.text!)!
            sudoku46.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku47.text != "" {
            sudoku[4][7] = Int(sudoku47.text!)!
            sudoku47.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku48.text != "" {
            sudoku[4][8] = Int(sudoku48.text!)!
            sudoku48.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
        if sudoku50.text != "" {
            sudoku[5][0] = Int(sudoku50.text!)!
            sudoku50.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku51.text != "" {
            sudoku[5][1] = Int(sudoku51.text!)!
            sudoku51.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku52.text != "" {
            sudoku[5][2] = Int(sudoku52.text!)!
            sudoku52.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku53.text != "" {
            sudoku[5][3] = Int(sudoku53.text!)!
            sudoku53.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku54.text != "" {
            sudoku[5][4] = Int(sudoku54.text!)!
            sudoku54.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku55.text != "" {
            sudoku[5][5] = Int(sudoku55.text!)!
            sudoku55.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku56.text != "" {
            sudoku[5][6] = Int(sudoku56.text!)!
            sudoku56.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku57.text != "" {
            sudoku[5][7] = Int(sudoku57.text!)!
            sudoku57.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku58.text != "" {
            sudoku[5][8] = Int(sudoku58.text!)!
            sudoku58.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
        if sudoku60.text != "" {
            sudoku[6][0] = Int(sudoku60.text!)!
            sudoku60.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku61.text != "" {
            sudoku[6][1] = Int(sudoku61.text!)!
            sudoku61.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku62.text != "" {
            sudoku[6][2] = Int(sudoku62.text!)!
            sudoku62.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku63.text != "" {
            sudoku[6][3] = Int(sudoku63.text!)!
            sudoku63.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku64.text != "" {
            sudoku[6][4] = Int(sudoku64.text!)!
            sudoku64.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku65.text != "" {
            sudoku[6][5] = Int(sudoku65.text!)!
            sudoku65.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku66.text != "" {
            sudoku[6][6] = Int(sudoku66.text!)!
            sudoku66.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku67.text != "" {
            sudoku[6][7] = Int(sudoku67.text!)!
            sudoku67.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku68.text != "" {
            sudoku[6][8] = Int(sudoku68.text!)!
            sudoku68.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
        if sudoku70.text != "" {
            sudoku[7][0] = Int(sudoku70.text!)!
            sudoku70.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku71.text != "" {
            sudoku[7][1] = Int(sudoku71.text!)!
            sudoku71.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku72.text != "" {
            sudoku[7][2] = Int(sudoku72.text!)!
            sudoku72.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku73.text != "" {
            sudoku[7][3] = Int(sudoku73.text!)!
            sudoku73.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku74.text != "" {
            sudoku[7][4] = Int(sudoku74.text!)!
            sudoku74.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku75.text != "" {
            sudoku[7][5] = Int(sudoku75.text!)!
            sudoku75.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku76.text != "" {
            sudoku[7][6] = Int(sudoku76.text!)!
            sudoku76.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku77.text != "" {
            sudoku[7][7] = Int(sudoku77.text!)!
            sudoku77.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku78.text != "" {
            sudoku[7][8] = Int(sudoku78.text!)!
            sudoku78.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
        if sudoku80.text != "" {
            sudoku[8][0] = Int(sudoku80.text!)!
            sudoku80.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku81.text != "" {
            sudoku[8][1] = Int(sudoku81.text!)!
            sudoku81.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku82.text != "" {
            sudoku[8][2] = Int(sudoku82.text!)!
            sudoku82.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku83.text != "" {
            sudoku[8][3] = Int(sudoku83.text!)!
            sudoku83.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku84.text != "" {
            sudoku[8][4] = Int(sudoku84.text!)!
            sudoku84.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku85.text != "" {
            sudoku[8][5] = Int(sudoku85.text!)!
            sudoku85.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku86.text != "" {
            sudoku[8][6] = Int(sudoku86.text!)!
            sudoku86.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku87.text != "" {
            sudoku[8][7] = Int(sudoku87.text!)!
            sudoku87.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        if sudoku88.text != "" {
            sudoku[8][8] = Int(sudoku88.text!)!
            sudoku88.textColor = #colorLiteral(red: 1, green: 0.5226528049, blue: 0, alpha: 1)
        }
        
    }
    
    func updateCell(onLine i: Int, andColumn j: Int, withValue x: Int) {
        if i == 0 {
            if j == 0 {
                sudoku00.text = "\(x)"
                
            } else if j == 1 {
                sudoku01.text = "\(x)"
                
            } else if j == 2 {
                sudoku02.text = "\(x)"
                
            } else if j == 3 {
                sudoku03.text = "\(x)"
                
            } else if j == 4 {
                sudoku04.text = "\(x)"
                
            } else if j == 5 {
                sudoku05.text = "\(x)"
                
            } else if j == 6 {
                sudoku06.text = "\(x)"
                
            } else if j == 7 {
                sudoku07.text = "\(x)"
                
            } else if j == 8 {
                sudoku08.text = "\(x)"
            }
        } else if i == 1 {
            if j == 0 {
                sudoku10.text = "\(x)"
                
            } else if j == 1 {
                sudoku11.text = "\(x)"
                
            } else if j == 2 {
                sudoku12.text = "\(x)"
                
            } else if j == 3 {
                sudoku13.text = "\(x)"
                
            } else if j == 4 {
                sudoku14.text = "\(x)"
                
            } else if j == 5 {
                sudoku15.text = "\(x)"
                
            } else if j == 6 {
                sudoku16.text = "\(x)"
                
            } else if j == 7 {
                sudoku17.text = "\(x)"
                
            } else if j == 8 {
                sudoku18.text = "\(x)"
            }
        } else if i == 2 {
            if j == 0 {
                sudoku20.text = "\(x)"
                
            } else if j == 1 {
                sudoku21.text = "\(x)"
                
            } else if j == 2 {
                sudoku22.text = "\(x)"
                
            } else if j == 3 {
                sudoku23.text = "\(x)"
                
            } else if j == 4 {
                sudoku24.text = "\(x)"
                
            } else if j == 5 {
                sudoku25.text = "\(x)"
                
            } else if j == 6 {
                sudoku26.text = "\(x)"
                
            } else if j == 7 {
                sudoku27.text = "\(x)"
                
            } else if j == 8 {
                sudoku28.text = "\(x)"
            }
        } else if i == 3 {
            if j == 0 {
                sudoku30.text = "\(x)"
                
            } else if j == 1 {
                sudoku31.text = "\(x)"
                
            } else if j == 2 {
                sudoku32.text = "\(x)"
                
            } else if j == 3 {
                sudoku33.text = "\(x)"
                
            } else if j == 4 {
                sudoku34.text = "\(x)"
                
            } else if j == 5 {
                sudoku35.text = "\(x)"
                
            } else if j == 6 {
                sudoku36.text = "\(x)"
                
            } else if j == 7 {
                sudoku37.text = "\(x)"
                
            } else if j == 8 {
                sudoku38.text = "\(x)"
            }
        } else if i == 4 {
            if j == 0 {
                sudoku40.text = "\(x)"
                
            } else if j == 1 {
                sudoku41.text = "\(x)"
                
            } else if j == 2 {
                sudoku42.text = "\(x)"
                
            } else if j == 3 {
                sudoku43.text = "\(x)"
                
            } else if j == 4 {
                sudoku44.text = "\(x)"
                
            } else if j == 5 {
                sudoku45.text = "\(x)"
                
            } else if j == 6 {
                sudoku46.text = "\(x)"
                
            } else if j == 7 {
                sudoku47.text = "\(x)"
                
            } else if j == 8 {
                sudoku48.text = "\(x)"
            }
        } else if i == 5 {
            if j == 0 {
                sudoku50.text = "\(x)"
                
            } else if j == 1 {
                sudoku51.text = "\(x)"
                
            } else if j == 2 {
                sudoku52.text = "\(x)"
                
            } else if j == 3 {
                sudoku53.text = "\(x)"
                
            } else if j == 4 {
                sudoku54.text = "\(x)"
                
            } else if j == 5 {
                sudoku55.text = "\(x)"
                
            } else if j == 6 {
                sudoku56.text = "\(x)"
                
            } else if j == 7 {
                sudoku57.text = "\(x)"
                
            } else if j == 8 {
                sudoku58.text = "\(x)"
            }
        } else if i == 6 {
            if j == 0 {
                sudoku60.text = "\(x)"
                
            } else if j == 1 {
                sudoku61.text = "\(x)"
                
            } else if j == 2 {
                sudoku62.text = "\(x)"
                
            } else if j == 3 {
                sudoku63.text = "\(x)"
                
            } else if j == 4 {
                sudoku64.text = "\(x)"
                
            } else if j == 5 {
                sudoku65.text = "\(x)"
                
            } else if j == 6 {
                sudoku66.text = "\(x)"
                
            } else if j == 7 {
                sudoku67.text = "\(x)"
                
            } else if j == 8 {
                sudoku68.text = "\(x)"
            }
        } else if i == 7 {
            if j == 0 {
                sudoku70.text = "\(x)"
                
            } else if j == 1 {
                sudoku71.text = "\(x)"
                
            } else if j == 2 {
                sudoku72.text = "\(x)"
                
            } else if j == 3 {
                sudoku73.text = "\(x)"
                
            } else if j == 4 {
                sudoku74.text = "\(x)"
                
            } else if j == 5 {
                sudoku75.text = "\(x)"
                
            } else if j == 6 {
                sudoku76.text = "\(x)"
                
            } else if j == 7 {
                sudoku77.text = "\(x)"
                
            } else if j == 8 {
                sudoku78.text = "\(x)"
            }
        } else if i == 8 {
            if j == 0 {
                sudoku80.text = "\(x)"
                
            } else if j == 1 {
                sudoku81.text = "\(x)"
                
            } else if j == 2 {
                sudoku82.text = "\(x)"
                
            } else if j == 3 {
                sudoku83.text = "\(x)"
                
            } else if j == 4 {
                sudoku84.text = "\(x)"
                
            } else if j == 5 {
                sudoku85.text = "\(x)"
                
            } else if j == 6 {
                sudoku86.text = "\(x)"
                
            } else if j == 7 {
                sudoku87.text = "\(x)"
                
            } else if j == 8 {
                sudoku88.text = "\(x)"
            }
        }
    }
    
}
