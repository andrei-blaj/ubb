#ifndef LECTURE10_DEMO_H
#define LECTURE10_DEMO_H

#include <QtWidgets/QMainWindow>
#include "ui_lecture10_demo.h"

class Lecture10_demo : public QMainWindow
{
	Q_OBJECT

public:
	Lecture10_demo(QWidget *parent = 0);
	~Lecture10_demo();

private:
	Ui::Lecture10_demoClass ui;
};

#endif // LECTURE10_DEMO_H
