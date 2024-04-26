#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Tartu2024;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CheckAnswer_clicked();

    //void on_checkBox_stateChanged(int arg1);

private:
    Ui::Tartu2024 *ui;
    void setVisibility(QWidget); // ei ole veel kasutuses
};
#endif // MAINWINDOW_H
