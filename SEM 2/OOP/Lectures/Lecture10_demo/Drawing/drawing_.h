#ifndef DRAWING_H
#define DRAWING_H

#include <QtWidgets/QMainWindow>
#include "ui_drawing.h"

class Drawing : public QWidget
{
	Q_OBJECT

public:
	Drawing(QWidget *parent = 0);
	~Drawing();

private:
};

#endif // DRAWING_H
