#include "lab11activity.h"
#include "ui_lab11activity.h"

#include "controller.h"

#include <iostream>
#include <vector>
#include <cstring>

Lab11Activity::Lab11Activity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab11Activity)
{
    ui->setupUi(this);
    on_radioButton_clicked();
}

Lab11Activity::~Lab11Activity()
{
    delete ui;
}

void Lab11Activity::on_radioButton_clicked()
{
    // SORTED
    std::vector <Dog> d = this -> controller.getDogList();

    for (int i = 0; i < d.size(); i++) {
        for (int j = i + 1; j < d.size() - 1; j++) {
            if (d[i].getName() > d[j].getName()) {
                Dog aux = d[i];
                d[i] = d[j];
                d[j] = aux;
            }
        }
    }

    std::string allDogs;

    for (int i = 0; i < d.size(); i++)
        allDogs += std::to_string(i+1) + ". " + d[i].getName() + " | " + d[i].getBreed() + " | " + std::to_string(d[i].getAge()) + " years old.\n";

    ui->textEdit->setPlainText(QString::fromStdString(allDogs));
}

void Lab11Activity::on_radioButton_2_clicked()
{
    // SHUFFLED

    std::vector <Dog> d = this -> controller.getDogList();

    srand(time(0));

    for (int i = 0; i < d.size(); i++) {
        int k = rand() % d.size();
        int l = rand() % d.size();
        Dog aux = d[k];
        d[k] = d[l];
        d[l] = aux;
    }

    std::string allDogs;

    for (int i = 0; i < d.size(); i++)
        allDogs += std::to_string(i+1) + ". " + d[i].getName() + " | " + d[i].getBreed() + " | " + std::to_string(d[i].getAge()) + " years old.\n";

    ui->textEdit->setPlainText(QString::fromStdString(allDogs));

}
