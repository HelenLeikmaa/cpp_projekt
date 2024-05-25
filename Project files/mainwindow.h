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

private:
    Ui::Tartu2024 *ui;
    QGridLayout *layout;
    QLabel *question_label;
    vector<QCheckBox*> *checkboxes;
    QPushButton *check_answers_btn;

    vector<Question> all_questions;

    void opening_window_ui();
    void create_grid(size_t); // according to the q index in all_question;
    void cleanup();
    void populate_checkboxes(Question*);

};
#endif // MAINWINDOW_H
