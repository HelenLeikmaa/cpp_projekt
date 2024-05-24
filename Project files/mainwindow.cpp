#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "question.h"
#include "results.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tartu2024)
{
    ui->setupUi(this);
    const string& file_name = "QA_attempt_3.txt";

    all_questions = Question::read_questions_from_file(file_name);
    current_q_index = 0; // this will increase each time a new question is selected
    score = 0; // TODO
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
    Question &q = all_questions.at(current_q_index);
    QString question = q.getQuestionText();
    question_label->setText(question);
    layout->addWidget(question_label, 0, 0);

    populate_checkboxes(&q);
    check_answers_btn->setText("Kontrolli!");
    layout->addWidget(check_answers_btn, 7, 0);
}


void MainWindow::populate_checkboxes(Question* q){
    checkboxes->clear(); // to be reused for each q
    auto all_answers = q->combined_answers(q->get_correct_answers(), q->get_incorrect_answers());
    for (size_t i = 0; i < all_answers.size(); ++i) {
        QCheckBox *box = new QCheckBox();
        checkboxes->push_back(box);
        box->setText(all_answers[i]);
        layout->addWidget(box);
    }
};


void MainWindow::on_CheckAnswer_clicked(){ // the button "Kontrolli" was clicked
    vector<QString> correct = all_questions[current_q_index].get_correct_answers();
    vector<QString> selected{}; // here be the answers the user selected
    for (const auto& element : *checkboxes) {
        if (element->isChecked()) {
            selected.push_back(element->text());
        }
    }
    UserAnswer answer;
    QString feedback = "\nÕigesti valitud: " + QString::number(answer.assessAnswer(correct, selected));
    QMessageBox::about(this, "Tagasiside", feedback);

}

