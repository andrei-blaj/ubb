package Interpreter.Utils;

import java.util.HashMap;
import java.util.List;
import java.util.Set;

public interface MyIDictionary<K, V> {

    void add(K key, V value);
    void remove(K key);
    boolean contains(K key);
    void setValue(K key, V value);
    V getValue(K key);
    Set<K> getKeys();
    HashMap<K, V> getMyDictionary();
    List<V> getValues();
}
