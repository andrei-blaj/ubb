#include "lecture11_demo.h"
#include <QtWidgets/QApplication>
#include "GeneRepository.h"
#include <QTreeView>
#include <QDirModel>
#include <QHeaderView>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	// genes
	GeneRepository repo{ "Ecoli_genes.txt" };
	/*Lecture11_demo w{ repo };
	w.show();*/

	// directory tree
	QTreeView *treeView = new QTreeView{};
	treeView->setMinimumSize(1300, 500);
	//treeView->header()->setStretchLastSection(false);
	treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
	QFont font("Courier", 20, 10, true);
	treeView->setFont(font);
	QDirModel *model = new QDirModel();
	treeView->setModel(model);
	treeView->setRootIndex(model->index("D:\\Google Drive\\Universitate\\Teaching"));
	treeView->show();

	return a.exec();
}
