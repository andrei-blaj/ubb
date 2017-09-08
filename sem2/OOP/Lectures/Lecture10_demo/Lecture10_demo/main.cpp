#include <QtWidgets/QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "GenesGUI.h"

int sliderExample(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	QWidget* w = new QWidget{};
	QHBoxLayout* layout = new QHBoxLayout{w};

	QSpinBox *spinAge = new QSpinBox{};	// spin box for integers
	spinAge->setFixedSize(150, 50);
	QFont* font = new QFont{};
	font->setBold(true);
	font->setPixelSize(30);
	spinAge->setFont(*font);

	QSlider *sliderAge = new QSlider{ Qt::Horizontal };
	sliderAge->setFixedSize(500, 50);

	layout->addWidget(spinAge);
	layout->addWidget(sliderAge);

	//Synchronise the spinner and the slider
	//Connect spin box - valueChanged to slider setValue
	QObject::connect(spinAge, SIGNAL(valueChanged(int)), sliderAge, SLOT(setValue(int)));
	//Connect - slider valueChanged to spin box setValue
	QObject::connect(sliderAge, SIGNAL(valueChanged(int)), spinAge, SLOT(setValue(int)));

	w->show();
	return a.exec();
}

int main(int argc, char *argv[])
{
	//sliderExample(argc, argv);

	QApplication a(argc, argv);
	std::vector<Gene> genes{ Gene{ "yqgE", "E_Coli_K12", "ATGAATTTACAGCAT" }, Gene{ "ppiA", "M_tuberculosis", "TTTTCATCACCGTCGG" }, Gene{ "Col2a1", "Mouse", "TTAAAGCATGGCTCTGTG" } };
	GenesGUI gui{genes};
	gui.show();
	return a.exec();
}
