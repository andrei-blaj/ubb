package com.company.Utils;

public class MyStack<T> implements MyIStack<T> {

    MyList<T> stack;

    public MyStack() {
        stack = new MyList<T>();
    }

    @Override
    public void push(T element) {
        stack.add(element);
    }

    @Override
    public T top() {
        return stack.get(stack.size() - 1);
    }

    @Override
    public T pop() {
        T element = stack.get(stack.size() - 1);
        stack.remove(stack.size() - 1);

        return element;
    }

    @Override
    public boolean isEmpty() {
        return stack.size() == 0;
    }

    @Override
    public int size() {
        return stack.size();
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder("\nStack: \n");

        for(int i = this.stack.size() - 1; i >= 0; i--) {
            out.append(this.stack.get(i).toString() + "\n");
        }

        if (this.stack.size() == 0) {
            out.append("list is empty");
        }

        return out.toString();
    }
}
