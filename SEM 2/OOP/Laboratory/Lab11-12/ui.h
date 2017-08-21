#ifndef UI_H
#define UI_H

#include <QWidget>

#include "admin.h"
#include "user.h"
#include "lab11activity.h"

namespace Ui {
class UI;
}

class UI : public QWidget
{
    Q_OBJECT

public:
    explicit UI(QWidget *parent = 0);
    ~UI();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_lab11Activity_clicked();

private:
    Ui::UI *ui;
    admin adm;
    User user;
    Lab11Activity l11a;
};

#endif // UI_H
