#ifndef LAB11ACTIVITY_H
#define LAB11ACTIVITY_H

#include <QWidget>

#include "controller.h"
#include "dog.h"

#include <iostream>
#include <cstring>
#include <vector>

namespace Ui {
class Lab11Activity;
}

class Lab11Activity : public QWidget
{
    Q_OBJECT

public:
    explicit Lab11Activity(QWidget *parent = 0);
    ~Lab11Activity();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::Lab11Activity *ui;
    Controller controller;
};

#endif // LAB11ACTIVITY_H
