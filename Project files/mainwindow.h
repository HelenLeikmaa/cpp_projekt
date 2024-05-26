#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
#include <QDir>
#include <QPixmap>
#include <QSpacerItem>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class Tartu2024;
}
QT_END_NAMESPACE
#include "question.h"
#include "results.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CheckAnswer_clicked();
    void on_StartGame_clicked();

private:
    Ui::Tartu2024 *ui;
    QVBoxLayout *layout;
    QPixmap *startpic;
    QPixmap *endpic;
    QLabel *question_label;
    vector<QCheckBox*> *checkboxes;
    QSpacerItem *spacer0; // for a nicer layout
    QSpacerItem *spacer1;
    QSpacerItem *spacer2;
    QPushButton *check_answers_btn;   
    QPushButton *start_game_btn;
    QMessageBox *m_box;

    vector<Question> all_questions;

    void opening_window_ui();
    void create_grid(size_t); // according to the q index in all_question;
    void cleanup();
    void game_start();
    void game_end();
    void populate_checkboxes(Question*);

};
#endif // MAINWINDOW_H
