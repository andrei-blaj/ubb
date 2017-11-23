package model;

import java.util.Stack;

public interface MyIStack <T> {
    void push(T el);
    T pop();
    boolean isEmpty();
    Stack <T> toStack();
}
