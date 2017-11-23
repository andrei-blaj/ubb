package com.company.Utils;

public interface MyIList<T> {
    void add(T element);
    void remove(T element);
    void pop_back();
    void remove(int position);
    int size();
    T get(int position);
}
