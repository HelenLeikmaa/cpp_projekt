#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Question{
private:
    string questionMessage;
    string questionType;
    vector<string> correctAnswers;
    vector<string> incorrectAnswers;
public:
    // Konstruktor
    Question(string questionMessageInput, string questionTypeInput, vector<string> correctAnswersInput, vector<string> incorrectAnswersInput)
        : questionMessage{questionMessageInput}, questionType{questionTypeInput}, correctAnswers{correctAnswersInput}, incorrectAnswers{incorrectAnswersInput}  {}

    string getQuestionMessage(){
        return questionMessage;
    }

    string getQuestiontype(){
        return questionType;
    }

    vector<string> getCorrectAnswers(){
        return correctAnswers;
    }

    vector<string> getWrongAnswers(){
        return incorrectAnswers;
    }
};

#endif // QUESTION_H
