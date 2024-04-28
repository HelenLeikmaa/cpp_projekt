#include "question.h"
// modified version of cpp_projekt/CLI_ver1/question.cpp
// possibly hardcode the questions for 1st deadline


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
    if (!input_file.is_open()) {qDebug() << "Failed to open file";};
    vector<Question> all_questions;
    vector<string> parts_of_one_question;
    string line;
    while (getline(input_file, line)) {
        stringstream ss(line);
        string q_info;
        while (getline(ss, q_info, ';')){
            parts_of_one_question.push_back(q_info);
        }
        Question question = *new Question(parts_of_one_question);
        all_questions.push_back(question);
    }
    input_file.close();
    return all_questions;
}

Question::Question(vector<string> parts_of_one_question){
    QString question_text = QString::fromStdString(parts_of_one_question[0]);
    QString question_type = QString::fromStdString(parts_of_one_question[1]);

    vector<QString> correct;
    stringstream ss1(parts_of_one_question[2]);
    string answer1;
    while (getline(ss1, answer1)) {correct.push_back(QString::fromStdString(answer1));};

    vector<QString> incorrect;
    stringstream ss2(parts_of_one_question[3]);
    string answer2;
    while (getline(ss2, answer2)) {incorrect.push_back(QString::fromStdString(answer2));};
}


pair<vector<QString>, vector<int>> Question::combined_answers_and_indexes_of_correct_answers(const vector<QString>& correct, const vector<QString>& incorrect){
    // for checking user answer
    vector<QString> all_answers;
    vector<int> correct_indexes;

    all_answers.insert(all_answers.end(), correct.begin(), correct.end());
    all_answers.insert(all_answers.end(),incorrect.begin(), incorrect.end());
    random_shuffle(all_answers.begin(), all_answers.end());

    size_t current_index = 0;
    for (const QString& answer : all_answers) {
        if (find(correct.begin(), correct.end(), answer)!= correct.end()) { // the string comes from the original vector correct<>
            correct_indexes.push_back(current_index);                       // the index of a correct answer in the vector all_answers
        }
        ++current_index;
    }
    return {all_answers, correct_indexes};
}

