#pragma once

class Task
{
public:
    ~Task() { }
    static long fibonacci(long n);
private:
    Task() { }
};
