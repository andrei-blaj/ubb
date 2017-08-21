#include "CancellableAsyncTask.h"
#include <exception>

CancellableAsyncTask::CancellableAsyncTask(long n) 
{
    this->n = n;
    cancelled = false;
	std::thread t{ &CancellableAsyncTask::doInBackground, this };
    t.detach();
}

CancellableAsyncTask::~CancellableAsyncTask() 
{
}

void CancellableAsyncTask::doInBackground() 
{
	try
	{
		long result = fibonacci(n);
		if (!cancelled)
			emit onCompleted(result);
	}
	catch (std::exception&) {}
}

void CancellableAsyncTask::cancel() 
{
    cancelled = true;
}

long CancellableAsyncTask::fibonacci(long n) 
{
    if (cancelled) 
		throw std::exception(); // exit immediately

    std::this_thread::sleep_for(std::chrono::milliseconds(25));	// Blocks the execution of the current thread for at least 25 milliseconds
    if (n == 0 || n == 1) 
	{
        emit onProgress(n);
        return 1;
    }
	else 
	{
        long result = fibonacci(n - 2) + fibonacci(n - 1);
        emit onProgress(n);
        return result;
    }
}
