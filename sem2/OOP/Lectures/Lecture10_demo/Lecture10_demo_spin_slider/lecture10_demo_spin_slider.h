#ifndef LECTURE10_DEMO_SPIN_SLIDER_H
#define LECTURE10_DEMO_SPIN_SLIDER_H

#include <QtWidgets/QMainWindow>
#include "ui_lecture10_demo_spin_slider.h"

class Lecture10_demo_spin_slider : public QMainWindow
{
	Q_OBJECT

public:
	Lecture10_demo_spin_slider(QWidget *parent = 0);
	~Lecture10_demo_spin_slider();

private:
	Ui::Lecture10_demo_spin_sliderClass ui;
};

#endif // LECTURE10_DEMO_SPIN_SLIDER_H
