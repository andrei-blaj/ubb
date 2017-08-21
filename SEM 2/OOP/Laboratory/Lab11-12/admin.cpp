#include "admin.h"
#include "ui_admin.h"

#include <QString>
#include <cstring>
#include <ctime>

admin::admin(QWidget *parent) : QWidget(parent), ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_admin_add_clicked()
{
    // Adding a new dog

    QString Qname = ui->admin_name->text();
    QString Qbreed = ui->admin_breed->text();
    QString Qage = ui->admin_age->text();
    QString Qphotograph = ui->admin_photo->text();

    std::string name = Qname.toStdString();
    std::string breed = Qbreed.toStdString();
    std::string age = Qage.toStdString();
    std::string photograph = Qphotograph.toStdString();

    std::string message = this -> controller.addDog(breed, name, age, photograph);

    ui -> admin_message_label -> setText(QString::fromStdString(message));

}

void admin::on_admin_delete_clicked()
{
    // Remove a dog from the repository
    QString Qdog = ui->admin_delete_label->text();
    std::string dog_id = Qdog.toStdString();

    std::string message = this -> controller.removeDog(dog_id);

    ui -> admin_message_label -> setText(QString::fromStdString(message));
}

void admin::on_admin_update_clicked()
{
    // Update a dog

    QString Qname = ui->admin_name->text();
    QString Qbreed = ui->admin_breed->text();
    QString Qage = ui->admin_age->text();
    QString Qphotograph = ui->admin_photo->text();

    std::string name = Qname.toStdString();
    std::string breed = Qbreed.toStdString();
    std::string age = Qage.toStdString();
    std::string photograph = Qphotograph.toStdString();

    QString Qdog = ui->admin_update_label->text();
    std::string dog_id = Qdog.toStdString();

    std::cout << dog_id << " " << age << "\n";

    std::string message = this -> controller.updateDog(dog_id, breed, name, age, photograph);

    ui -> admin_message_label -> setText(QString::fromStdString(message));
}

void admin::on_admin_display_clicked()
{
    // Displays all the dogs from the repository

    const QString content = QString::fromStdString(this->controller.getDogs());

    ui->textEdit->setPlainText(content);
}

void admin::on_radioButton1_clicked()
{
    // Sorted
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

void admin::on_radioButton_clicked()
{

    // Shuffled

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
