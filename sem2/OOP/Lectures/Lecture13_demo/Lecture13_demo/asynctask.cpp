#include "asynctask.h"
#include <thread>

AsyncTask::AsyncTask(long n) 
{
    this->n = n;
	std::thread t{ &AsyncTask::doInBackground, this };
    t.detach();	// Detaches the thread represented by the object from the calling thread, allowing them to execute independently 
				// from each other.
}

AsyncTask::~AsyncTask() 
{
}

void AsyncTask::doInBackground() 
{
    long result = fibonacci(n);
    emit onCompleted(result);
}

long AsyncTask::fibonacci(long n) 
{
    if (n == 0 || n == 1) 
		return 1;
    else 
		return fibonacci(n - 2) + fibonacci(n - 1);
}
