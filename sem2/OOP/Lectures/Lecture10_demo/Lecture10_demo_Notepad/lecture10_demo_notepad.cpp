#include "lecture10_demo_notepad.h"
#include <QFileDialog>
#include <fstream>
#include <QMessageBox>
#include <sstream>

Lecture10_demo_Notepad::Lecture10_demo_Notepad(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->buildWindow();
	this->connectSignalsAndSlots();
}

Lecture10_demo_Notepad::~Lecture10_demo_Notepad()
{

}

void Lecture10_demo_Notepad::buildWindow()
{
	// add the menu "File" to the menu bar
	this->fileMenu = this->menuBar()->addMenu("&File");

	// create open, save and exit actions
	this->openAction = new QAction("&Open", this);
	this->saveAction = new QAction("&Save", this);
	this->exitAction = new QAction("&Exit", this);

	// add the actions to the menu "File"
	this->fileMenu->addAction(this->openAction);
	this->fileMenu->addAction(this->saveAction);
	this->fileMenu->addSeparator();
	this->fileMenu->addAction(this->exitAction);

	// central widget
	this->textEdit = new QTextEdit{};
	this->setCentralWidget(this->textEdit);

	// we can also create a file tool bar
	QToolBar* fileToolBar = addToolBar("&File");
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);

	statusBar()->showMessage("Status Message");
}

void Lecture10_demo_Notepad::connectSignalsAndSlots()
{
	QObject::connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
	QObject::connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
	QObject::connect(exitAction, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
}

void Lecture10_demo_Notepad::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;C++ Files (*.cpp *.h)");
	if (fileName != "") 
	{
		this->filename = fileName.toStdString();

		std::ifstream f{ this->filename };
		if (!f.is_open())
		{
			QMessageBox::critical(0, "Error", "File could not be opened!");
			return;
		}

		std::stringstream s;
		s << f.rdbuf();
		this->textEdit->setText(QString::fromStdString(s.str()));
		f.close();
	}
}

void Lecture10_demo_Notepad::save()
{
	std::ofstream f{ this->filename };
	if (!f.is_open())
	{
		QMessageBox::critical(0, "Error", "File could not be opened!");
		return;
	}

	f << this->textEdit->toPlainText().toStdString();
	f.close();
}