#include "question.h"
// ikka Markolt need:)
// vajadusel esimeseks tähtajaks hardcode'ida

QString Question::getQuestion(){
    return "placeholder q";
}

vector<QString> Question::get_correct_answers(){
    return {"correct1", "correct2", "correct3"};
};

vector<QString> Question::get_incorrect_answers(){
    return {"incorrect1", "incorrect2", "incorrect3"};
};

pair<vector<QString>, vector<int>> Question::all_answers_correct_indexes(const vector<QString>& correct, const vector<QString>& incorrect){
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
