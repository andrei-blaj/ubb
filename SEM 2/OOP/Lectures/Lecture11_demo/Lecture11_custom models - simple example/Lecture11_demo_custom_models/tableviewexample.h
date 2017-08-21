#ifndef TABLEVIEWEXAMPLE_H
#define TABLEVIEWEXAMPLE_H

#include <QWidget>
#include "ui_tableviewexample.h"
#include "GeneRepository.h"

class TableViewExample : public QWidget
{
	Q_OBJECT

public:
	TableViewExample(GeneRepository& r, QWidget *parent = 0);
	~TableViewExample();

private:
	Ui::TableViewExample ui;
	GeneRepository& repo;
};

#endif // TABLEVIEWEXAMPLE_H
