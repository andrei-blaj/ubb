package model;

import java.util.Map;
import java.util.Collection;

public interface MyIDictionary <K, V> {
    V put(K key, V value);
    V get(K key) ;

    Collection <V> values();
    Collection <K> keys();

    V remove(K fd);

    Map <K, V> toMap();
}
