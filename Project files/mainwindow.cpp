#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "question.h"
#include "gatheringResults.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tartu2024)
{
    ui->setupUi(this);
    const string& file_name = "QA_attempt_3.txt";
    all_questions = Question::read_questions_from_file(file_name);
    opening_window_ui();

    QObject::connect(check_answers_btn, &QPushButton::clicked,
                     this, &MainWindow::on_CheckAnswer_clicked); // clicking on "Kontrolli" sends out a signal to a slot
}

MainWindow::~MainWindow() {delete ui; }

void MainWindow::opening_window_ui(){
    layout = new QGridLayout();
    question_label = new QLabel();
    checkboxes = new vector<QCheckBox*>;
    check_answers_btn = new QPushButton();
    create_grid();
    this->centralWidget()->setLayout(layout);
};
void MainWindow::create_grid(){
    Question &q = all_questions.at(0);
    QString question = q.getQuestionText();
    question_label->setText(question);
    layout->addWidget(question_label, 0, 0);

    populate_checkboxes(&q);
    check_answers_btn->setText("Kontrolli!");
    layout->addWidget(check_answers_btn, 7, 0);
}


void MainWindow::populate_checkboxes(Question* q){
    auto [answers, correct_indexes] = q->combined_answers_and_indexes_of_correct_answers(q->get_correct_answers(), q->get_incorrect_answers());
    for (size_t i = 0; i < answers.size(); ++i) {
        QCheckBox *box = new QCheckBox();
        box->setText(answers[i]);
        layout->addWidget(box);
        checkboxes->push_back(box);} // to be used in assessing user answers
};


void MainWindow::on_CheckAnswer_clicked(){ // the button "Kontrolli" was clicked
    vector<int> checked_boxes;
    QString checked_indexes_as_string{""};
    for (size_t i = 0; i < checkboxes->size(); ++i){
        if ((checkboxes->at(i))->isChecked()) {
            checked_boxes.push_back(i);
            checked_indexes_as_string += (' ' + QString::number(i));}
    }
    QString feedback = checked_indexes_as_string.length() > 0 ?
        "Linnutasid kastikese(d)" + checked_indexes_as_string + "\nVastuste kontroll on lisandumas <3" :
            "Sa ei linnutanudki miskit:(";
    QMessageBox::about(this, "Tagasiside", feedback);

}

