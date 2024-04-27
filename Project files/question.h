#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <QString>
#include <vector>
#include <random>
#include <tuple>
using namespace std;

// võtame küsimuse objekti Marko meetodiga
// edastada mainwindow labelile ja checkboxidele

class Question{
private:
    string m_question;
    vector<string> m_correct_answers;
    vector<string> m_incorrect_answers;
public:
    QString getQuestion();
    vector<QString> get_correct_answers();
    vector<QString> get_incorrect_answers();
    pair<vector<QString>, vector<int>> all_answers_correct_indexes(const vector<QString>&, const vector<QString>&);


};















#endif // QUESTION_H
