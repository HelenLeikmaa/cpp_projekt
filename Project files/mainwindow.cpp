#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "question.h"
#include "results.h"


static size_t current_q_index = 0; // this will increase each time a new question is selected
static int score = 0; // TODO

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
    create_grid(current_q_index); // call after showing an img and a hello
    this->centralWidget()->setLayout(layout);
};

void MainWindow::create_grid(size_t current_q_index){
    cleanup();
    Question &q = all_questions.at(current_q_index);
    QString question = q.getQuestionText();
    question_label->setText(question);
    layout->addWidget(question_label);
    populate_checkboxes(&q);
    check_answers_btn->setText("Kontrolli!");
    layout->addWidget(check_answers_btn);
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

void MainWindow::cleanup() {
    layout->destroyed(question_label);
    for (auto& element : *checkboxes) {
        delete element;
    }
}

void MainWindow::game_end(){
    question_label->hide();
    check_answers_btn->hide();
    tartu24 = new QPixmap(":/image/marek-lumi-2024.jpg");
    int img_w = ui->img2024->width();
    int img_h = ui->img2024->height();
    ui->img2024->setPixmap(tartu24->scaled(img_w, img_h, Qt::KeepAspectRatioByExpanding));
    ui->ending->setText("Hea töö! Oled kultuuriaasta tšempion!");
}

void MainWindow::on_CheckAnswer_clicked(){ // the button "Kontrolli" was clicked

    vector<QString> correct = all_questions[current_q_index].get_correct_answers();
    vector<QString> selected{}; // here be the answers the user selected
    for (const auto& element : *checkboxes) {
        if (element->isChecked()) {
            selected.push_back(element->text());
        }
    }   
    UserAnswer answer;
    auto [result,feedback] = answer.assessAnswer(correct, selected);
    if (result == selected.size() && result == correct.size()){
        current_q_index++;
        }
    QMessageBox::about(this, "Tagasiside", feedback);

    if (current_q_index < all_questions.size()) {
        create_grid(current_q_index);
    }
    else {
        cleanup();
        game_end();
    }


}

