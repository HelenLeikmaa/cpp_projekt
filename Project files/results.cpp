#include "results.h"

pair<int, QString> UserAnswer::assessAnswer(vector<QString>& actually_correct, vector<QString>& user_selected){
    if (user_selected.size() == 0) { return {0, "Vali midagi ;)"}; }

    int nr{0};
    QString feedback{};

    for (const auto& element : user_selected) {
        auto iter = find_if(actually_correct.begin(), actually_correct.end(), [&](const auto& el) {
            return element == el;
        });
        if (iter!= actually_correct.end()) {
            correct.push_back(element);
            nr++;
        }
        else {
            incorrect.push_back(element);
        }
    }
    if (nr == actually_correct.size()  && nr == user_selected.size()) {
        feedback += "Kaunis! Vastasid õigesti:)";
    }
    else if (nr == actually_correct.size() && actually_correct.size() < user_selected.size()) {
        size_t erinevus = user_selected.size() - actually_correct.size();
        erinevus == 1 ? feedback += "Üks valitud variant on üleliia. " :
            feedback += "Mõned valitud variandid on üleliia. ";
    }
    else if (nr < actually_correct.size()){
        nr == 0 ? feedback += "Vali midagi õiget ka:D" : feedback += "Midagi on puudu..";
        if (user_selected.size() >= actually_correct.size()) {
            feedback += "\n..ja midagi on üle.";
        }
    }
    return {nr, feedback};
};




