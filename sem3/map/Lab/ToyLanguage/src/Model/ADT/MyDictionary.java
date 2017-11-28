package Model.ADT;

import java.util.Collection;
import java.util.HashMap;

/**
 * Created by Andrei on 20.10.2017.
 */
public class MyDictionary<K,V> implements MyIDictionary<K,V> {

    private HashMap<K,V> dictionary;

    public MyDictionary() {
        this.dictionary = new HashMap<K,V>();
    }

    public HashMap<K, V> getDictionary() {
        return dictionary;
    }

    @Override
    public Collection<V> values() {
        return dictionary.values();
    }

    @Override
    public boolean isEmpty() {
        return dictionary.isEmpty();
    }

    @Override
    public void put(K key, V value) {
        dictionary.put(key,value);

    }


    @Override
    public V get(K key) {
        return dictionary.get(key);


    }

    @Override
    public void update(K key, V value) {
        dictionary.remove(key);
        dictionary.put(key,value);
    }

    @Override
    public boolean isDefined(K key) {
        for(K k : dictionary.keySet())
        {
            if(key == k)
                return true;
        }
        return false;
    }

    @Override
    public String toString() {
        String str="";
        for(K key : dictionary.keySet())
        {
            str = str + key + "->" + dictionary.get(key) + "\n";
        }
        return str;
    }
}
