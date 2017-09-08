#include "lecture13_demo.h"
#include <QMessageBox>
#include "task.h"
#include <sstream>

Lecture13_demo::Lecture13_demo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->asyncTask = nullptr;
	this->cancellableAsyncTask = nullptr;
	this->computing = false;

	QObject::connect(this->ui.computeButton1, &QPushButton::clicked, this, &Lecture13_demo::computeFibo1);
	QObject::connect(this->ui.computeButton2, &QPushButton::clicked, this, &Lecture13_demo::computeFibo2);
	QObject::connect(this->ui.computeButton3, &QPushButton::clicked, this, &Lecture13_demo::computeFibo3);
}

Lecture13_demo::~Lecture13_demo()
{
	this->clearPreviousAsyncTask();
	this->clearPreviousCancellableAsyncTask();
}

void Lecture13_demo::computeFibo1()
{
	long n = this->ui.numberLineEdit1->text().toLong();
	if (n <= 0) 
	{
		QMessageBox::critical(this, "Error", "Enter a number greater than 0");
		return;
	}
	this->ui.labelResult1->setText("Processing...");
	this->repaint();
	long result = Task::fibonacci(n);
	this->ui.labelResult1->setText(QString::number(result));
}

void Lecture13_demo::computeFibo2()
{
	long n = this->ui.numberLineEdit2->text().toLong();
	if (n <= 0)
	{
		QMessageBox::critical(this, "Error", "Enter a number greater than 0");
		return;
	}
	this->ui.labelResult2->setText("Processing...");
	this->repaint();
	this->clearPreviousAsyncTask();
	this->asyncTask = new AsyncTask(n);
	
	connect(this->asyncTask, &AsyncTask::onCompleted, this, &Lecture13_demo::onCompletedAsyncTask);
}

void Lecture13_demo::clearPreviousAsyncTask()
{
	if (this->asyncTask != nullptr) 
	{
		disconnect(this->asyncTask, &AsyncTask::onCompleted, this, &Lecture13_demo::onCompletedAsyncTask);
		delete this->asyncTask;
	}
}

void Lecture13_demo::onCompletedAsyncTask(long result) 
{
	this->ui.labelResult2->setText(QString::number(result));
}

void Lecture13_demo::computeFibo3()
{
	if (this->computing) 
	{
		this->ui.numberLineEdit3->setEnabled(true);
		this->ui.computeButton3->setText("Compute");
		this->ui.labelResult3->setText("Cancelled");
		this->cancellableAsyncTask->cancel();
	}
	else 
	{
		long n = this->ui.numberLineEdit3->text().toLong();
		if (n <= 0) 
		{
			QMessageBox::critical(this, "Error", "Enter a number greater than 0");
			return;
		}
		this->ui.numberLineEdit3->setEnabled(false);
		this->ui.computeButton3->setText("Cancel");
		this->ui.labelResult3->setText("Processing...");
		this->repaint();
		this->clearPreviousCancellableAsyncTask();
		this->ui.fiboWidget->reset(n);
		this->cancellableAsyncTask = new CancellableAsyncTask(n);
		
		connect(this->cancellableAsyncTask, &CancellableAsyncTask::onProgress, this->ui.fiboWidget, &FiboWidget::onProgress);
		connect(this->cancellableAsyncTask, &CancellableAsyncTask::onCompleted, this, &Lecture13_demo::onCompletedCancellableAsyncTask);
	}

	this->computing = !this->computing;
}

void Lecture13_demo::clearPreviousCancellableAsyncTask()
{
	if (this->cancellableAsyncTask != nullptr)
	{
		disconnect(this->cancellableAsyncTask, &CancellableAsyncTask::onProgress, this->ui.fiboWidget, &FiboWidget::onProgress);
		disconnect(this->cancellableAsyncTask, &CancellableAsyncTask::onCompleted, this, &Lecture13_demo::onCompletedCancellableAsyncTask);

		delete this->cancellableAsyncTask;
	}
}

void Lecture13_demo::onCompletedCancellableAsyncTask(long result)
{
	this->ui.labelResult3->setText(QString::number(result));
	this->ui.numberLineEdit3->setEnabled(true);
	this->ui.computeButton3->setText("Compute");
	computing = false;
}