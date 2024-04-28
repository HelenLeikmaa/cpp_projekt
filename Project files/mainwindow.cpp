#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "question.h"
#include "gatheringResults.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tartu2024)
{
    ui->setupUi(this);    
    layout = new QGridLayout();
    question_label = new QLabel();
    checkboxes = new vector<QCheckBox*>;
    check_answers_btn = new QPushButton();
    create_grid();
    this->centralWidget()->setLayout(layout);

    QObject::connect(check_answers_btn, &QPushButton::clicked,
                     this, &MainWindow::on_CheckAnswer_clicked); // clicking on "Kontrolli" sends out a signal to a slot
}

MainWindow::~MainWindow() {delete ui; }


void MainWindow::create_grid(){
    Question *q = new Question();

    QString question = q->getQuestionText();
    question_label->setText(question);
    layout->addWidget(question_label, 0, 0);

    populate_checkboxes(q);
    check_answers_btn->setText("Kontrolli!");
    layout->addWidget(check_answers_btn, 7, 0);
}


void MainWindow::populate_checkboxes(Question* q){
    auto [all_answers, correct_indexes] = q->combined_answers_and_indexes_of_correct_answers(q->get_correct_answers(), q->get_incorrect_answers());
    for (size_t i = 0; i < all_answers.size(); ++i) {
        QCheckBox *box = new QCheckBox();
        qDebug() << all_answers[i] << '\n';
        box->setText(all_answers[i]);
        layout->addWidget(box);
        checkboxes->push_back(box);} // to be used in assessing user answers
};


void MainWindow::on_CheckAnswer_clicked() // the button "Kontrolli" was clicked
{
    QString feedback = "Tubli, sa oskad imehästi kastikesi linnutada!"; // TODO
    QMessageBox::about(this, "Tagasiside", feedback);

}

