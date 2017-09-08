#pragma once
#include <thread>
#include <QObject>

class AsyncTask: public QObject
{
    Q_OBJECT
private:
	long n;
	void doInBackground();
	static long fibonacci(long n);

public:
    AsyncTask(long n);
    ~AsyncTask();

signals:
    void onCompleted(long result);
};
