#include <vector>
#include <string>
#include "question.h";
using namespace std;

#ifndef DECHEADER_H
#define DECHEADER_H

// Function declaration
vector<string> splitString(string& str, char delimiter);
vector<Question> makeQuestionObjects(const string& filename);
vector<string> splitString(string& str, char delimiter);
void displayCliTerminal(vector<Question> formQuestions);
size_t getVectorMemorySize(const vector<string>& inputVector);
vector<string> shuffleAnswers(vector<string> correctAnswers, vector<string> wrongAnswers);

#endif // DECHEADER_H
