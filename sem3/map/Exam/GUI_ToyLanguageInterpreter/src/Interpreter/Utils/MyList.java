package Interpreter.Utils;

import java.util.ArrayList;
import java.util.List;

public class MyList<T> implements MyIList<T> {
    private List<T> list;

    public MyList() {
        list = new ArrayList<>();
    }

    @Override
    public List<T> getData() { return list; }

    @Override
    public void add(T element) {
        list.add(element);
    }

    @Override
    public void remove(T element) {
        list.remove(element);
    }

    @Override
    public void pop_back() {
        if (list.size() > 0) {
            list.remove(list.size() - 1);
        }
    }

    @Override
    public void remove(int position) {
        list.remove(position);
    }

    @Override
    public int size() {
        return list.size();
    }

    public T get(int position) {
        return list.get(position);
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder("\nList: \n");

        for(T value: list) {
            out.append(value.toString() + "\n");
        }

        if (list.size() == 0) {
            out.append("list is empty");
        }

        out.append("\n");

        return out.toString();
    }
}
