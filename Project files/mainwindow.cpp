#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "sendingQuestions.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tartu2024)
{
    ui->setupUi(this);    
    QGridLayout *layout = new QGridLayout();

    // allolev hiljem teha tsükliga ja eraldi meetodis + tekstid tulevad sendingQuestions failist TODO
    QLabel *Question = new QLabel();
    Question->setText("Küsimuse tekst");
    QCheckBox *Check1 = new QCheckBox();
    Check1->setText("Variant 1");
    QCheckBox *Check2 = new QCheckBox();
    Check2->setText("Variant 2");
    QCheckBox *Check3 = new QCheckBox();
    Check3->setText("Variant 3");
    QCheckBox *Check4 = new QCheckBox();
    Check4->setText("Variant 4");
    QCheckBox *Check5 = new QCheckBox();
    Check5->setText("Variant 5");
    QCheckBox *Check6 = new QCheckBox();
    Check6->setText("Variant 6");
    QPushButton *CheckAnswer = new QPushButton();
    CheckAnswer->setText("Kontrolli!");

    layout->addWidget(Question, 0, 0);
    layout->addWidget(Check1, 1, 0);
    layout->addWidget(Check2, 2, 0);
    layout->addWidget(Check3, 3, 0);
    layout->addWidget(Check4, 4, 0);
    layout->addWidget(Check5, 5, 0);
    layout->addWidget(Check6, 6, 0);
    layout->addWidget(CheckAnswer, 7, 0);

    Question->setVisible(true);
    Check1->setVisible(true);
    Check2->setVisible(true);
    Check3->setVisible(true);
    Check4->setVisible(true);
    Check5->setVisible(true);
    Check6->setVisible(true);
    CheckAnswer->setVisible(true);

    this->centralWidget()->setLayout(layout);

    QObject::connect(CheckAnswer, &QPushButton::clicked,
                     this, &MainWindow::on_CheckAnswer_clicked); // kui vajutada "Kontrolli", siis see saadab signaali välja

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setVisibility(QWidget widget) { // võib osutuda vajalikuks, et elemente peita/näidata
    bool visibility = !widget.isVisible();
    widget.setVisible(visibility);
}


void MainWindow::on_CheckAnswer_clicked() // vajutati nuppu "Kontrolli"
{
    QString feedback = "Tubli, sa oskad imehästi kastikesi linnutada!"; // vajab täpsustamist
    QMessageBox::about(this, "Tagasiside", feedback);

    /*if (ui->checkBox-> isChecked()){ // see on kõige ülemise kastikese kohta praegu hard code'itud
        qDebug() << "linnutati kastike (siia võiks tulla kastikese sisu, aga ma praegu ei oska seda küsida veel)"  << '\n';
        QMessageBox::information(this, "title", "You checked a box!");
    }
    else {
         QMessageBox::information(this, "title", "You didn't check a box!");
    } */
}


/*void MainWindow::on_checkBox_stateChanged(int arg1){
 // seda võib kasutada selleks, et jooksvalt jälgida, kas on linnuke või ei; selle kasutamisvajadus on selgumisel:D
    if (arg1 == 2) qDebug() << "linnuke on lisatud" << '\n';
    if (arg1 == 0) qDebug() << "linnuke on eemaldatud" << '\n';
}*/

