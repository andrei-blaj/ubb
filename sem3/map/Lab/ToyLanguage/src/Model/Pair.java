package Model;

/**
 * Created by Andrei on 08.11.2017.
 */
public class Pair<T,V> {
    private T first;
    private V second;

    public Pair(T first, V second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public void setFirst(T first) {
        this.first = first;
    }

    public V getSecond() {
        return second;
    }

    public void setSecond(V second) {
        this.second = second;
    }

    @Override
    public String toString() {
        String str="";
        str = str + this.first.toString();
        return str;
    }
}
