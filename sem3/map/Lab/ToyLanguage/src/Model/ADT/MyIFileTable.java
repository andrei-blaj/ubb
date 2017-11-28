package Model.ADT;

import java.util.HashMap;
import java.util.Set;

/**
 * Created by Andrei on 07.11.2017.
 */
public interface MyIFileTable<K,V>{
    public boolean isEmpty();
    public void put(K key,V value);
    public V get(K key);
    public boolean containsKey(K key);
    HashMap<K, V> getDict();
    void remove(K key);
    Set<K> keySet();
}
