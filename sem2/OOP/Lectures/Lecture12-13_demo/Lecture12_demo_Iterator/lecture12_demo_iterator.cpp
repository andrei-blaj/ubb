#include "lecture12_demo_iterator.h"
#include <QMessageBox>

Lecture12_demo_Iterator::Lecture12_demo_Iterator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//this->castles = new LinkedListMultimap{};

	// the other representation for the multimap is used => no changes in the client code that uses the iterator
	this->castles = new BinarySearchTreeMultimap{};

	this->castles->add("England", Castle{ "Highclere Castle", "highclere.jpg", "England", 4000, 4000 });
	this->castles->add("France", Castle{ "Chambord Castle", "chambord.jpg", "France", 3200, 3200 });
	this->castles->add("Germany", Castle{ "Neuschwanstein Castle", "neuschwanstein.jpg", "Germany", 4000, 4000 });
	this->castles->add("Italy", Castle{ "Scalinger Castle", "scaliger.jpg", "Italy", 4000, 4000 });
	this->castles->add("England", Castle{ "Windsor Castle", "windsor.jpg", "England", 4000, 4000 });

	// initialiaze the iterator
	this->iterator = this->castles->createIterator();

	// set the first castle
	this->showCurrentCastle();

	// connnect the signals and slots
	QObject::connect(this->ui.nextButton, SIGNAL(clicked()), this, SLOT(next()));
	QObject::connect(this->ui.slideShowButton, SIGNAL(clicked()), this, SLOT(slideShow()));
}

Lecture12_demo_Iterator::~Lecture12_demo_Iterator()
{
	delete this->castles;
}

void Lecture12_demo_Iterator::showCurrentCastle()
{
	const Castle& c = this->iterator->currentItem().second;
	this->ui.castleLabel->setText(QString::fromStdString(c.getDescription() + ", " + c.getLocation()));
	QPixmap pixmap(QString::fromStdString(c.getPhoto()));
	this->ui.photoLabel->setPixmap(pixmap);
}

void Lecture12_demo_Iterator::next()
{
	this->iterator->next();
	if (this->iterator->isDone())
		QMessageBox::information(NULL, "Information", "<font size = 18 > " + QString{"The iteration is done!"});
	else
		this->showCurrentCastle();
}

void Lecture12_demo_Iterator::slideShow()
{
	this->iterator->first();

	while (!this->iterator->isDone())
	{
		this->showCurrentCastle();
		this->repaint();
		this->iterator->next();
		_sleep(1500);
	}

	QMessageBox::information(NULL, "Information", "<font size = 18 > " + QString{ "The iteration is done!" });
}