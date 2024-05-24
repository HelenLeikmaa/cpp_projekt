#include "results.h"
#include <iostream>

int UserAnswer::assessAnswer(vector<QString>& actually_correct, vector<QString>& user_selected){
    int nr{0};
    for (const auto& element : user_selected) {
        std::cout << "........" << element.toStdString();
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

    return nr;
};




