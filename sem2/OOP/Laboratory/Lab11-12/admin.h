#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "controller.h"

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

private slots:
    void on_admin_add_clicked();
    void on_admin_delete_clicked();
    void on_admin_update_clicked();
    void on_admin_display_clicked();

    void on_radioButton1_clicked();

    void on_radioButton_clicked();

private:
    Ui::admin *ui;
    Controller controller;
};

#endif // ADMIN_H
