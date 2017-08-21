#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) : QWidget(parent), ui(new Ui::User)
{
    ui->setupUi(this);

    this -> current = 0;

    std::vector <Dog> d = this -> controller.getDogList();

    if (d.size() == 0) {
        ui -> textEdit -> setText(QString::fromStdString("No more dogs."));
        return;
    }

    ui->textEdit->setText(QString::fromStdString(d[this -> current].convert()));

    std::string command = "open " + d[this -> current].getPhotograph();
    system(command.c_str());

}

User::~User()
{
    delete ui;
}

void User::on_user_adopt_clicked()
{
    std::vector <Dog> d = this -> controller.getDogList();

    if (d.size() == 0) {
        ui -> textEdit -> setText(QString::fromStdString("No more dogs!"));
        return;
    }

    this -> current = (this -> current + 1) % d.size();

    std::string message = this -> controller.addToAdoptionList(d[this->current]);
    std::string message_aux = this -> controller.removeDog(std::to_string(this -> current));

    ui -> textEdit -> setText(QString::fromStdString(message));

}

void User::on_user_next_clicked()
{
    // next dog

    std::vector <Dog> d = this -> controller.getDogList();

    if (d.size() == 0) {
        ui -> textEdit -> setText(QString::fromStdString("No more dogs."));
        return;
    }

    this -> current = (this -> current + 1) % d.size();

    ui->textEdit->setText(QString::fromStdString(d[this -> current].convert()));

    std::string command = "open " + d[this -> current].getPhotograph();
    system(command.c_str());

}

void User::on_user_see_adoption_list_clicked()
{
    // CSV
    std::ofstream f("adoptionlist.csv");

    std::vector <Dog> list = this -> controller.getAdoptionList();

    for (int i = 0; i < (int) list.size(); i++)
        f << std::to_string(i+1) << ". " << list[i].getBreed() << ", " << list[i].getName() << ", " << list[i].getPhotograph() << "\n";

    f.close();

    std::string command = "open adoptionlist.csv";
    system(command.c_str());
}

void User::on_user_filter_clicked()
{

    QString Qbreed = ui->user_breed->text();
    QString Qage = ui->user_age->text();

    std::string breed = Qbreed.toStdString();
    std::string age = Qage.toStdString();

    std::string message = this -> controller.filter(breed, age);

    ui -> textEdit -> setText(QString::fromStdString(message));

}

void User::on_see_adoption_list_html_clicked()
{
    // HTML

    std::vector <Dog> list = this -> controller.getAdoptionList();

    std::ofstream f("adoptionlist.html");

    f << "<!DOCTYPE html><html><head><title>AdoptionList</title></head><body><table border=1>";

    for (int i = 0; i < (int) list.size(); i++)
        f<< "<tr>" << "<td>" << list[i].getBreed() << "</td>" << "<td>" << list[i].getName() << "</td>" << "<td><a href =" << list[i].getPhotograph() << ">Link</a></td>" << "</tr>";

    f << "</table></body></html>";

    f.close();

    std::string command = "open adoptionlist.html";
    system(command.c_str());

}
