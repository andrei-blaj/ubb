#ifndef LECTURE13_DEMO_H
#define LECTURE13_DEMO_H

#include <QtWidgets/QMainWindow>
#include "ui_lecture13_demo.h"
#include "asynctask.h"
#include "CancellableAsyncTask.h"

class Lecture13_demo : public QMainWindow
{
	Q_OBJECT

private:
	Ui::Lecture13_demoClass ui;
	AsyncTask* asyncTask;
	CancellableAsyncTask* cancellableAsyncTask;
	bool computing;

public:
	Lecture13_demo(QWidget *parent = 0);
	~Lecture13_demo();

private:
	void computeFibo1();
	void computeFibo2();
	void computeFibo3();

	void clearPreviousAsyncTask();
	void clearPreviousCancellableAsyncTask();

public:
	void onCompletedAsyncTask(long result);

	// cancellable async task
	void onCompletedCancellableAsyncTask(long result);
};

#endif // LECTURE13_DEMO_H
