package com.company.Utils;

import java.util.HashMap;
import java.util.Set;

public class MyDictionary<K, V> implements MyIDictionary<K, V> {

    protected HashMap<K, V> myDictionary;

    public MyDictionary() {
        this.myDictionary = new HashMap<>();
    }

    @Override
    public void add(K key, V value) {
        this.myDictionary.put(key, value);
    }

    @Override
    public void remove(K key) {
        this.myDictionary.remove(key);
    }

    @Override
    public boolean contains(K key) {
        return this.myDictionary.containsKey(key);
    }

    @Override
    public void setValue(K key, V value) {
        this.add(key, value);
    }

    @Override
    public V getValue(K key) {
        return this.myDictionary.get(key);
    }

    @Override
    public Set<K> getKeys() {
        return this.myDictionary.keySet();
    }
}
