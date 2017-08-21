#include "ui.h"
#include "ui_ui.h"

UI::UI(QWidget *parent) : QWidget(parent), ui(new Ui::UI)
{
    ui->setupUi(this);
}

UI::~UI()
{
    delete ui;
}

void UI::on_pushButton_clicked()
{
    // Admin button
    adm.show();
    user.hide();
}

void UI::on_pushButton_2_clicked()
{
    // User button
    user.show();
    adm.hide();
}

void UI::on_pushButton_3_clicked()
{
    // Quit
    QCoreApplication::quit();
}

void UI::on_lab11Activity_clicked()
{
    l11a.show();
}
