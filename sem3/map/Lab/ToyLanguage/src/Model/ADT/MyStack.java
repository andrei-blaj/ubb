package Model.ADT;

import Exceptions.MyExceptions;

import java.util.Stack;

/**
 * Created by Andrei on 20.10.2017.
 */
public class MyStack<T> implements MyIStack<T> {
    private Stack<T> stack;

    public MyStack() {
        this.stack = new Stack<T>();
    }

   @Override
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    @Override
    public void push(T v) {
        stack.push(v);
    }

    @Override
    public T pop() throws MyExceptions{
        if(stack.isEmpty() == true)
            throw new MyExceptions("Stack is empty");
        return stack.pop();
    }

    @Override
    public String toString() {
        String str="";
        for(T e: stack)
        {
            str=str + e.toString() + "\n";

        }
        str = str + "\n";
        return str;
    }
}
