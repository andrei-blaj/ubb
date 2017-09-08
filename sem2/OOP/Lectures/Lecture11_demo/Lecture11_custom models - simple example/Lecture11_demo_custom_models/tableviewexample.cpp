#include "tableviewexample.h"
#include "MyTableModel.h"

TableViewExample::TableViewExample(GeneRepository& r, QWidget *parent)
	: repo{ r }, QWidget(parent)
{
	ui.setupUi(this);

	MyTableModel* myModel = new MyTableModel{this->repo};
	ui.genesTableView->setModel(myModel);
}

TableViewExample::~TableViewExample()
{

}
