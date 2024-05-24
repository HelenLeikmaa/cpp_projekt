#ifndef RESULTS_H
#define RESULTS_H
#include <vector>
#include <QString>
using namespace std;


struct UserAnswer{ // possibly to be used for a more detailed feedback

    vector<QString> correct{};
    vector <QString> incorrect{};
    int assessAnswer(vector<QString>&, vector<QString>&);
        // calculate number of correctly selected answers for one question
};

#endif // RESULTS_H
