#ifndef USER_H
#define USER_H

#include <QWidget>

#include "controller.h"

namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = 0);

    ~User();

private slots:

    void on_user_adopt_clicked();

    void on_user_next_clicked();

    void on_user_see_adoption_list_clicked();

    void on_user_filter_clicked();

    void on_see_adoption_list_html_clicked();

private:
    Ui::User *ui;
    Controller controller;
    int current;
};

#endif // USER_H
