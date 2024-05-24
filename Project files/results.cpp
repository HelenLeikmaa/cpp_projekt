#include "gatheringResults.h"



bool answered_correctly(std::vector<int> correct_answer_indexes, std::vector<int> user_answer_indexes){
    if (correct_answer_indexes.size() != user_answer_indexes.size()) return false;
    for (std::size_t i = 0; correct_answer_indexes.size(); ++i) {
        if (correct_answer_indexes[i] != user_answer_indexes[i]) return false;
    }
    return true;
}


