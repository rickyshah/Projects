//
//  ViewController.swift
//  Quizzler
//
//  Created by Angela Yu on 25/08/2015.
//  Copyright (c) 2015 London App Brewery. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    // create a constant variable that is initialised to class 'QuestionBank'
    // so that it can access all the properties and method of the class
    let allQuestion = QuestionBank()
    
    // create another variable to hold the value
    // the user picked by pressing the button
    var pickedAnswer: Bool = false
    
    // create variable 'questionNumber' to track
    // what question number the user is on
    // the value is initalised to 0 as the first question
    // is alawys 0 because the first index is 0
    var questionNumber:Int = 0
    
    // create variable 'score' to store user score
    var score: Int = 0
    
    @IBOutlet weak var questionLabel: UILabel!
    @IBOutlet weak var scoreLabel: UILabel!
    @IBOutlet var progressBar: UIView!
    @IBOutlet weak var progressLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // call 'nextQuestion' function to start the quiz
        // function is below
        nextQuestion()

    }

    // function to check what key is pressed
    // and update the 'pickedAnswer' value and
    // perform other remaining bits
    @IBAction func answerPressed(_ sender: AnyObject) {
        // check the answer user pressed and store
        // in the variable 'pressedAnswer'
        
        if sender.tag == 1 {
            pickedAnswer = true
        }else if sender.tag == 2 {
            pickedAnswer = false
        }
        
        // call function to check the picked answer
        // against the correct answer
        checkAnswer()
        
        // add 1 to the variable 'questionNumber' created above
        // for counting the state of the question after the
        // check answer is excecuted
        questionNumber = questionNumber + 1
        
        // call 'nextQuestion' function
        // to go to next question
        nextQuestion()
  
    }
    
    // function to update user interface
    func updateUI() {
        // update score label text properties
        scoreLabel.text = "Score: \(score)"
        
        // update progress label text properties
        progressLabel.text = "\(questionNumber + 1)/13"
        
        // update progress bar
        // to obtain width each size of progress bar, divide
        // total screen size width  by total number of question
        // then multiply by 'questionNumber' to increase the width
        progressBar.frame.size.width = (view.frame.size.width / 13) * CGFloat(questionNumber + 1)
    }
    
    // function to go to next question
    func nextQuestion() {
         // as long as questionNumber is less or equal to 12
        // assign 'text' properties of UILabel 'questionLabel'
        // to question chosen from allQuestion that holds array 'list'
        // and the index number is whatever the int var 'questionNumber'
        // number is
        if questionNumber <= 12{
            questionLabel.text = allQuestion.list[questionNumber].questionText
            
            // update user interface by calling 'updateUI' function
            updateUI()
        }
        else {
            
            // create constant 'alert' and assign UIAlertController
            // to display alert using the built in style
            let alert = UIAlertController(title: "End of Quiz!", message: "Do you want to restart?", preferredStyle: .alert)
            
            // create a constant 'restart' and assign UIAlertAction and call
            // function 'startOver' inside the action
            let restart = UIAlertAction(title: "Restart", style: .default, handler: {(UIAlertAction) in self.startOver()})
            
            // add the restart action to 'alert'
            alert.addAction(restart)
            
            // display the alert on screen using in built 'present'
            present(alert, animated: true, completion: nil)
            
            score = 0
            
        }
        
    }
    
    // function to check correct answer
    func checkAnswer() {
        // assign correct answer from 'list' QuestionTank class
        // to variable 'correctAnswer' accessing using 'allQuestion'
        let correctAnswer = allQuestion.list[questionNumber].answer
        
        // if 'pickedAnswer' is same as correct answer
        // print and increase 'score' by 1
        if correctAnswer == pickedAnswer {
            ProgressHUD.showSuccess("Correct")
            score = score + 1
        }
        else{
            ProgressHUD.showError("Wrong")
        }
    }
    
    
    func startOver() {
       questionNumber = 0
        nextQuestion()
    }
    

    
}
