#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "question.h"
#include "results.h"


static size_t current_q_index = 0; // increases each time a new question is selected
static float score = 0; // correct answer: += 1; incorrect answer: -= 0.1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tartu2024)
{
    ui->setupUi(this);
    const string& file_name = "QA_attempt_3.txt";
    all_questions = Question::read_questions_from_file(file_name);
    opening_window_ui();
    QObject::connect(start_game_btn, &QPushButton::clicked,
        this, &MainWindow::on_StartGame_clicked); // clicking on "Alusta Mängu" sends out a signal to a slot
    QObject::connect(check_answers_btn, &QPushButton::clicked,
        this, &MainWindow::on_CheckAnswer_clicked); // clicking on "Kontrolli" sends out a signal to a slot
}


MainWindow::~MainWindow() {delete ui; }


void MainWindow::opening_window_ui(){
    layout = new QVBoxLayout();
    question_label = new QLabel();
    checkboxes = new vector<QCheckBox*>;
    start_game_btn = new QPushButton();
    check_answers_btn = new QPushButton();
    spacer0 = new QSpacerItem(500, 425, QSizePolicy::Fixed, QSizePolicy::Fixed);
    spacer1 = new QSpacerItem(500, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    spacer2 = new QSpacerItem(500, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_box = new QMessageBox();
    game_start();
    this->centralWidget()->setLayout(layout);
};


void MainWindow::game_start() {
    ui->message->setText("<3 Tartu 2024 teadmiste kontroll <3\n"
                           "Iga küsimuse eest saad kuni ühe punkti.\n"
                           "Iga vale vastus vähendab skoori 0.1 punkti võrra.");
    startpic = new QPixmap(":/image/marek-lumi-2024.jpg");
    int img_w = ui->img2024->width();
    int img_h = ui->img2024->height();
    ui->img2024->setPixmap(startpic->scaled(img_w, img_h, Qt::KeepAspectRatioByExpanding));
    start_game_btn->setText("Alusta mängu!");
    layout->addWidget(start_game_btn);
    layout->insertSpacerItem(0, spacer0);
}


void MainWindow::on_StartGame_clicked(){
    ui->message->hide();
    ui->img2024 ->hide();
    start_game_btn->hide();
    layout->removeItem(spacer0);
    create_grid(current_q_index);
}

void MainWindow::create_grid(size_t current_q_index){
    cleanup();
    Question &q = all_questions.at(current_q_index);
    QString question = q.getQuestionText();
    question_label->setText(question);
    layout->addWidget(question_label);
    populate_checkboxes(&q);
    check_answers_btn->setText("Kontrolli!");
    layout->addWidget(check_answers_btn, 9);
    layout->insertSpacerItem(8, spacer1);
    layout->insertSpacerItem(10, spacer2);
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
    layout->removeItem(spacer1);
    layout->removeItem(spacer2);
    for (auto& element : *checkboxes) {
        delete element;
    }
}

void MainWindow::game_end(){
    question_label->hide();
    check_answers_btn->hide();
    endpic = new QPixmap(":/image/anna-auza-seelik.jpg");
    int img_w = ui->img2024->width();
    int img_h = ui->img2024->height();
    ui->img2024->setPixmap(endpic->scaled(img_w, img_h, Qt::KeepAspectRatioByExpanding));
    ui->img2024->show();
    ui->message->setText("Hea töö! \nSaid kokku " + QString::number(score) + " punkti.\nOled kultuuriaasta tšempion!");
    ui->message->show();
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
        score++;
        current_q_index++;
        }
    else {
        score -= 0.1;
    }

    m_box->about(this, "Tagasiside", feedback); // super-small, not the best option

    if (current_q_index < all_questions.size()) {
        create_grid(current_q_index);
    }
    else {
        cleanup();
        game_end();
    }


}

