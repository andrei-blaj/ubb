package model;

import java.util.List;

public interface MyIList <T> {
    void add(T el);
    T get(int index);
    boolean remove(T el);
    T remove(int index);
    int size();
    List <T> toList();
}