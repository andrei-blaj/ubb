package Model.ADT;

import java.util.HashMap;

/**
 * Created by Andrei on 14.11.2017.
 */
public interface MyIHeap<K,V> {
    void put(K key,V value);
    public V get(K key);
    public boolean containsKey(K key);
    public int getFreeAddress();
    public void update(K key,V value);
    public void setFreeAddress(int freeAddress);
    HashMap<K, V> getHeap();
    void setHeap(HashMap<K, V> heap);
}
