//
//  Question.swift
//  Quizzler
//
//  Created by Ricky on 31/01/2019.
//  Copyright © 2019 London App Brewery. All rights reserved.
//

import Foundation

// create a class
class Question{
    let questionText: String
    let answer: Bool
    
    // use initialiser method to add value to above
    // properties(variable) 'questionText' and 'answer'
    init(text: String, correctAnswer: Bool ) {
        questionText = text
        answer = correctAnswer
    }
    
    
}
