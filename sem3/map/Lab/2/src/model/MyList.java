package model;

import java.util.List;

public class MyList <T> implements MyIList<T> {
    private List <T> _list;

    // Constructor
    public MyList (List <T> _list) {
        this._list = _list;
    }

    @Override
    public void add(T el) {
        this._list.add(el);
    }

    @Override
    public T get(int index) {
        return this._list.get(index);
    }

    @Override
    public boolean remove(T el) {
        return this._list.remove(el);
    }

    @Override
    public T remove(int index) {
        return this._list.remove(index);
    }

    @Override
    public int size() {
        return this._list.size();
    }

    @Override
    public List <T> toList() {
        return this._list;
    }

    @Override
    public String toString() {
        String ret = "";
        boolean ok = false;
        for(T el : this._list) {
            if(ok)
                ret = ret + "\n";
            ret += el.toString();
            ok = true;
        }
        return ret;
    }
}
