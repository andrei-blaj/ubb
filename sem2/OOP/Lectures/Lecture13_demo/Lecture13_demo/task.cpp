#include "task.h"

long Task::fibonacci(long n) 
{
	if (n == 0 || n == 1)
		return 1;
	else
		return fibonacci(n - 2) + fibonacci(n - 1);
}
