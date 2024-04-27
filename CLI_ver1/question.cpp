#include "question.h"
#include "decHeader.h"
#include "vector"
#include "string"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

vector<Question> makeQuestionObjects(const string& filename){

    ifstream inputFile(filename);

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Failed to open the file: " << filename << endl;
    }

    string line;

    if (inputFile.peek() == ifstream::traits_type::eof()) {
        cerr << "The file is empty/missing: " << filename << endl;
        inputFile.close();
    }

    vector<Question> questionObjects;

    while (getline(inputFile, line)) {
        vector<string> proccessedLine = splitString(line, ';');
        vector<string> proccessedCorrectAnswers = splitString(proccessedLine.at(2), ',');
        vector<string> proccessedWrongAnswers = splitString(proccessedLine.at(3), ',');

        questionObjects.push_back(Question(proccessedLine.at(0), proccessedLine.at(1), proccessedCorrectAnswers, proccessedWrongAnswers));
    }

    // Close the file
    inputFile.close();
    return questionObjects;
}



vector<string> splitString(string& str, char delimiter) {
    vector<string> tokens;
    istringstream iss(str);
    string words;

    while (getline(iss, words, delimiter)) {
        if (words[0] == ' '){
            tokens.push_back(words.substr(1));
        }
        else{
            tokens.push_back(words);
        }
    }

    return tokens;
}
