#ifndef QUESTION_H
#define QUESTION_H
#include <QDebug>
#include <string>
#include <QString>
#include <vector>
#include <sstream>
#include <fstream>
#include <random>
#include <tuple>
using namespace std;

// modified version of cpp_projekt/CLI_ver1/question.h


class Question{
private:
    QString m_question;
    QString m_type;
    vector<QString> m_correct_answers;
    vector<QString> m_incorrect_answers;
public:
    Question() = default;
    Question(QString, QString, vector<QString>, vector<QString>); // constructing Q from private members
    Question(const vector<string>&); // constructing Q from a vector containing 4 strings to be converted to private members
    static vector<Question> read_questions_from_file(const string&); // uses the constructor Question(vector<string>)
    QString getQuestionText();
    vector<QString> get_correct_answers();
    vector<QString> get_incorrect_answers();
    pair<vector<QString>, vector<int>> combined_answers_and_indexes_of_correct_answers(const vector<QString>&, const vector<QString>&);

};


#endif // QUESTION_H
