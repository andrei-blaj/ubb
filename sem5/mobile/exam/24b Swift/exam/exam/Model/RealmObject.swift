//
//  RealmObject.swift
//  exam
//
//  Created by Andrei Blaj on 24/01/2019.
//  Copyright © 2019 Andrei-Sorin Blaj. All rights reserved.
//

import Foundation
import RealmSwift

class RealmObject: Object {
    
    @objc dynamic var id: String?
    @objc dynamic var title: String?
    @objc dynamic var songDescription: String?
    @objc dynamic var album: String?
    @objc dynamic var genre: String?
    @objc dynamic var year: String?
    
}
