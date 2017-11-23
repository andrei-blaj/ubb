package com.company.Utils;

public interface MyIStack<T> {

    void push(T element);
    T top();
    T pop();
    boolean isEmpty();
    int size();

}
