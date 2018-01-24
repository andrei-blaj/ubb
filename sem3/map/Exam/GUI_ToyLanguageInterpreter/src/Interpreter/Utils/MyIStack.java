package Interpreter.Utils;

import java.util.List;

public interface MyIStack<T> {

    void push(T element);
    T top();
    T pop();
    boolean isEmpty();
    int size();
    List<T> getData();

}
