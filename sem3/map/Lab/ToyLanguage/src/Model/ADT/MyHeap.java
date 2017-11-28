package Model.ADT;

import java.util.HashMap;

/**
 * Created by Andrei on 26.11.2017.
 */
public class MyHeap<K,V> implements MyIHeap<K,V> {
    private HashMap<K,V> heap;
    private int freeAddress;

    public MyHeap() {
        this.heap = new HashMap<K,V>();
        this.freeAddress = 1;
    }

    public HashMap<K, V> getHeap() {
        return heap;
    }

    public void setHeap(HashMap<K, V> heap) {
        this.heap = heap;
    }

    public int getFreeAddress() {
        return freeAddress;
    }

    @Override
    public void update(K key, V value) {
        this.heap.replace(key,value);
    }

    public void setFreeAddress(int freeAddress) {
        this.freeAddress = freeAddress;
    }

    @Override
    public void put(K key, V value) {
        this.heap.put(key,value);
    }

    @Override
    public V get(K key) {
        return this.heap.get(key);
    }

    @Override
    public boolean containsKey(K key) {
        return this.heap.containsKey(key);
    }

    @Override
    public String toString() {
        String str="";
        for(K key : this.heap.keySet())
        {
            str = str + key.toString() + "->" + this.heap.get(key).toString() + "\n";
        }
        str = str + "\n";
        return str;
    }
}
