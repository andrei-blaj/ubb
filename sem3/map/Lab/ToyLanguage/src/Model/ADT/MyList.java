package Model.ADT;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Andrei on 20.10.2017.
 */
public class MyList<T> implements MyIList<T> {
    private List<T> list;

    public MyList() {
        this.list = new ArrayList<T>();
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public void add(T elem) {
        list.add(elem);
    }

    @Override
    public String toString() {
        String str="";
        for(T e : list)
            str = str + e.toString() + "\n";
        str = str + "\n";
        return str;
    }
}
