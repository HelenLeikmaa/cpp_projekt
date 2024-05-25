#include "question.h"
// modified version of cpp_projekt/CLI_ver1/question.cpp


Question::Question(QString q, QString type, vector<QString> correct, vector<QString> incorrect):
    m_question{q}, m_type{type}, m_correct_answers{correct}, m_incorrect_answers{incorrect}{};


QString Question::getQuestionText(){
    return m_question;
}

vector<QString> Question::get_correct_answers(){
    return m_correct_answers;
};

vector<QString> Question::get_incorrect_answers(){
    return m_incorrect_answers;
};

vector<Question> Question::read_questions_from_file(const string& filename){
    ifstream input_file(filename);
    if (!input_file.is_open()) {qDebug() << "Failed to open file";}
    vector<Question> all_questions;
    vector<string> parts_of_one_question;
    string line;
    while (getline(input_file, line)) {
        stringstream ss(line);
        string q_info;
        while (getline(ss, q_info, ';')){
            parts_of_one_question.push_back(q_info);
        }
        Question question(parts_of_one_question);
        all_questions.push_back(question);
        parts_of_one_question.clear();
    }
    for (auto& element : all_questions) {
        std::cout << "Küsimus: " << element.getQuestionText().toStdString() << ' ';
    }
    input_file.close();
    return all_questions;
}

Question::Question(const vector<string>& parts_of_one_question){
    QString question_text = QString::fromStdString(parts_of_one_question[0]); // TODO: acceptable line width about 51 char
    QString question_type = QString::fromStdString(parts_of_one_question[1]);
    vector<QString> correct;
    stringstream ss1(parts_of_one_question[2]);
    string answer1;
    while (getline(ss1, answer1, ',')) { correct.push_back(QString::fromStdString(answer1));};

    vector<QString> incorrect;
    stringstream ss2(parts_of_one_question[3]);
    string answer2;
    while (getline(ss2, answer2, ',')) { incorrect.push_back(QString::fromStdString(answer2));};

    m_question = question_text;
    m_type = question_type;
    m_correct_answers = correct;
    m_incorrect_answers = incorrect;
}


vector<QString> Question::combined_answers(const vector<QString>& correct, const vector<QString>& incorrect){
    vector<QString> all_answers;

    all_answers.insert(all_answers.end(), correct.begin(), correct.end());
    all_answers.insert(all_answers.end(),incorrect.begin(), incorrect.end());
    random_shuffle(all_answers.begin(), all_answers.end());

    return all_answers;
}

