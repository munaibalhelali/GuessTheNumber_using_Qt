#include "widget.h"
#include "./ui_widget.h"
#include <ctime>
#include <cstdlib>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initialize the random generator seed
    std::srand(std::time(nullptr));

    //Initialize secret number
    secretNumber = std::rand()%10 + 1;

    //disable start over button
    ui->startOverButton->setDisabled(true);

    //empty the message label
    ui->messageLabel->setText("");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guessNumber = ui->numberSpinBox->value();

    if(guessNumber > secretNumber){
        ui->messageLabel->setText("The number is less than "+ QString::number(guessNumber)+ "!");
    }else if(guessNumber < secretNumber){
        ui->messageLabel->setText("The number is greater than "+ QString::number(guessNumber)+ "!");
    }else{
        ui->messageLabel->setText("Congratulations! You guessed the number.");

    //enable start over button
    ui->startOverButton->setDisabled(false);
    //disable guess button
    ui->guessButton->setDisabled(true);
    }

}

void Widget::on_startOverButton_clicked()
{
    secretNumber = std::rand() % 10 + 1;

    //disable start over button
    ui->startOverButton->setDisabled(true);

    //enable guess button
    ui->guessButton->setDisabled(false);

    //empty message

    ui->messageLabel->setText("");

}
