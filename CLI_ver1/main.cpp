#include "mainwindow.h"
#include "DecHeader.h"
#include <QApplication>
#include <iostream>
#include <filesystem>
using namespace std;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();

    // ------ Marko Smirnov test algus ------


    // Input file (questions) reading
    string filename = "questions.txt";
    string inputFileDirectory = "C:/Users/smirn/Desktop/Qt 3/Kysitlus_Tartu2024/" + filename; // kuidas muuta project et uuriks project kausta?
    vector<Question> formQuestions = makeQuestionObjects(inputFileDirectory);




    // CLI start
    QCoreApplication a(argc, argv);
    displayCliTerminal(formQuestions);


    return 0;


    // ------ Marko smirnov test koodi lõpp  ------


}
