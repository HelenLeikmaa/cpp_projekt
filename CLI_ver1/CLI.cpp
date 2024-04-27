#include "decHeader.h"
#include "question.h"
#include <iostream>
#include <random>
#include <string>
#include <QCoreApplication>
#include <QInputDialog>
using namespace std;

void displayCliTerminal(vector<Question> formQuestions){
    cout << " ****************************************************************** " << endl;
    cout << " *******         Tere vastaja! CLI juhend & käsud:         ******* " << endl;
    cout << " *******                       START : s                    ******* " << endl;
    cout << " *******         SISESTA KÜSIMUSE VASTUSE NUMBRID: 1-9     ******* " << endl;
    cout << " *******          EEMALDA VASTUSE VALIK/LINNUKE: e 1-9      ******* " << endl;
    cout << " *******              KINNITA VALIKD & LIIGU EDASI: x       ******* " << endl;
    cout << " *******                   LÕPETA KÜSITLUS: x 0           ******* " << endl;
    cout << " ****************************************************************** " << endl;

    string input;
    char letter;
    int number;
    int index = 0;
    bool startedSession = false;
    vector<string> shuffledAnswers;
    vector<string> userQuestionAnswers;

    while(true){
        if (startedSession == true & !shuffledAnswers.empty()){
            cout << " ****************************************************************** " << endl;
            cout << " *******                  CLI juhend & käsud:              ******* " << endl;
            cout << " *******         SISESTA KÜSIMUSE VASTUSE NUMBRID: 1-9     ******* " << endl;
            cout << " *******          EEMALDA VASTUSE VALIK/LINNUKE: e 1-9      ******* " << endl;
            cout << " *******           KONTROLLI VASTUSEID & LIIGU EDASI: x       ******* " << endl;
            cout << " *******                   LÕPETA KÜSITLUS: x 0           ******* " << endl;
            cout << " ****************************************************************** " << endl << endl;

            cout << endl << "[ Küsimus nr. " << index + 1 << " ]:" << endl;

            cout << formQuestions.at(index).getQuestionMessage() << endl;

            cout << endl << "[ Valikvastused ]: " << endl;

            for (int i = 0; i < shuffledAnswers.size(); ++i) {
                cout << i + 1 << ". " << shuffledAnswers.at(i) << endl;
            }

            cout << endl << "[ Minu selekteeritud vastused ]: " << endl;

            for (int i = 0; i < userQuestionAnswers.size(); ++i) {
                cout << i + 1 << ". " << userQuestionAnswers.at(i) << endl;
            }
        }

        if (shuffledAnswers.empty()){
            shuffledAnswers = shuffleAnswers(formQuestions.at(index).getCorrectAnswers(), formQuestions.at(index).getWrongAnswers());
            continue;
        }

        cout << endl << "KÄSK: ";
        getline(cin, input);


        // 1 symbol terminal input
        if (input.length() == 1) {

            // Answer number selected
            if (isdigit(input[0])) {
                int inputInt = input[0] - '0';
                if (inputInt <= shuffledAnswers.size()){
                    userQuestionAnswers.push_back(shuffledAnswers.at(inputInt - 1));
                    shuffledAnswers.erase(shuffledAnswers.begin() + inputInt - 1);
                }
            }

            // Other commands
            else{
                char letter = tolower(input[0]);

                if (letter == 's' && startedSession == false){
                    startedSession = true;
                    continue;
                }

                else if (letter == 'x'){
                    // Kontrolli vasuseid ja vota uus kysimus.
                    vector<string> userCorrectAnswers;
                    vector<string> userWrongAnswers;

                    // Valikvastused, mis on õigesti ja valesti märgitud.
                    for (string userAnswer : userQuestionAnswers) {
                        bool correct = false;
                        for (string correctAnswer : formQuestions.at(index).getCorrectAnswers()) {
                            if (userAnswer == correctAnswer){
                                userCorrectAnswers.push_back(userAnswer);
                                correct = true;
                                break;
                            }
                        }
                        if (correct == false){
                            userWrongAnswers.push_back(userAnswer);
                        }
                    }

                    // Valikvastused, mis on õiged aga pole märgitud õigeks ja vastupidi.
                    for (string correctAnswer : formQuestions.at(index).getCorrectAnswers()) {
                        bool correct = false;
                        for (string userCorrectAnswer : userCorrectAnswers) {
                            if (correctAnswer == userCorrectAnswer){
                                correct = true;
                                break;
                            }
                        }
                        if (correct == false){
                            userWrongAnswers.push_back(correctAnswer);
                        }
                    }

                    cout << endl << endl << "********************" << " [ Küsimus nr. " << index + 1 << " ] TULEMUS" << " *******************" << endl << endl;

                    cout << "[ Õigesti vastatud ]: " << endl;

                    for (string correctAnswer : userCorrectAnswers) {
                        cout << " - " << correctAnswer << endl;
                    }

                    cout << endl << "[ Valesti vastatud ]: " << endl;

                    for (string wrongAnswer : userWrongAnswers) {
                        cout << " - " << wrongAnswer << endl;
                    }

                    if (index < formQuestions.size() - 1){
                        index++; // Suurenda indexit / võta uus küsimus kui neid on.
                        userQuestionAnswers.clear();
                        shuffledAnswers.clear();
                    }

                    else{
                        cout << endl << " ****************************************************************** " << endl;
                        cout << endl << " *******              SEE OLI VIIMANE KÜSIMUS!             ******* " << endl;
                        cout << endl << " *******                    LÕPETAN TÖÖ                  ******* " << endl;
                        cout << endl << " ****************************************************************** " << endl;
                        break;
                    }
                }
            }
        }

        // 2 symbol terminal input
        else if (input.length() == 3 & input[1] == ' ') {
            char letter = tolower(input[0]);
            int number = input[2] - '0'; // Convert char to integer
            if (letter == 'x' & number == 0){
                cout << endl << " ****************************************************************** " << endl;
                cout << endl << " *******                    LÕPETAN TÖÖ                  ******* " << endl;
                cout << endl << " ****************************************************************** " << endl;
                return;
            }

            else if (letter == 'e' & number <= userQuestionAnswers.size()){
                shuffledAnswers.push_back(userQuestionAnswers.at(number - 1));
                userQuestionAnswers.erase(userQuestionAnswers.begin() + number - 1);
            }

            else if (letter == 'x' & number == 0){
                break;
            }

        } else {
            cerr << "ERROR: Argumentide sisendi viga!" << endl;
        }
    }
}

vector<string> shuffleAnswers(vector<string> correctAnswers, vector<string> wrongAnswers){

    vector<string> shuffledAnswers;

    for (string correctAnswer : correctAnswers) {
        shuffledAnswers.push_back(correctAnswer);
    }
    for (string wrongAnswer : wrongAnswers) {
        shuffledAnswers.push_back(wrongAnswer);
    }

    random_device random_seed;
    mt19937 engine(random_seed());
    shuffle(shuffledAnswers.begin(), shuffledAnswers.end(), engine);

    return shuffledAnswers;
}
