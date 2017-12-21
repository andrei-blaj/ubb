package Model.ADT;

import java.util.Collection;
import java.util.HashMap;
import java.util.Set;

/**
 * Created by Andrei on 31.10.2017.
 */
public class MyFileTable<K,V> implements MyIFileTable<K,V> {
    private HashMap<K,V> dict;

    public MyFileTable() {
        this.dict = new HashMap<K,V>();
    }

    public HashMap<K, V> getDict() {
        return dict;
    }

    @Override
    public void remove(K key) {
        dict.remove(key);
    }

    @Override
    public Set<K> keySet() {
        return dict.keySet();
    }

    @Override
    public Collection<V> getValues() {
        return dict.values();
    }


    @Override
    public boolean isEmpty() {
        return dict.isEmpty();
    }

    @Override
    public void put(K key, V value) {
        dict.put(key,value);
    }

    @Override
    public V get(K key) {
        return dict.get(key);
    }

    @Override
    public boolean containsKey(K key) {
        return dict.containsKey(key);
    }

    @Override
    public String toString() {
        String str="";
        for(K key : dict.keySet())
        {
            str = str + key.toString() + "->" + dict.get(key).toString() + "\n";
        }
        str = str + "\n";
        return str;
    }
}
