#pragma once
#include <thread>
#include <QObject>

class CancellableAsyncTask: public QObject
{
    Q_OBJECT
private:
	long n;
	long totalCalculatedNumbers;
	bool cancelled;
	void doInBackground();
	long fibonacci(long n);

public:
	CancellableAsyncTask(long n);
    ~CancellableAsyncTask();
    void cancel();

signals:
    void onCompleted(long result);
    void onProgress(long nthCalculated);
};
