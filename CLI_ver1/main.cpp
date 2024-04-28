#include "mainwindow.h"
#include "DecHeader.h"
#include <QApplication>
#include <iostream>
#include <filesystem>
#include <QDir>
using namespace std;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();

    // ------ Marko Smirnov test algus ------


    // Input file (questions) reading
    // added the next 4 lines for troubleshooting (no luck yet)
    // https://doc.qt.io/qt-6/qdir.html#details
    QDir dir("CLI_ver1");
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        qDebug() << fileInfo.fileName() << '\n'; }

    // Kysimuste fail
    QDir inputFileDirectory(filesystem::current_path());

    QString path = inputFileDirectory.filePath("questions.txt");

    vector<Question> formQuestions = makeQuestionObjects(path.toStdString());


    // CLI start
    QCoreApplication a(argc, argv);
    displayCliTerminal(formQuestions);


    return 0;


    // ------ Marko smirnov test koodi lõpp  ------


}
