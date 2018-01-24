package Interpreter.Models.Tables;

import Interpreter.Utils.MyDictionary;

import java.util.HashMap;

public class HeapTable extends MyDictionary<Integer, Integer> {

    private int currentLastAddress = 0;

    public HeapTable() {
        myDictionary = new HashMap<>();
    }

    public int pushValue(int value) {
        this.currentLastAddress++;

        this.myDictionary.put(this.currentLastAddress, value);

        return this.currentLastAddress;
    }

    public HashMap<Integer, Integer> getHashMap() {
        return this.myDictionary;
    }

    public void setHashMap(HashMap<Integer, Integer> newDict) {
        this.myDictionary = newDict;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder("Heap table: \n");

        for(Integer key : this.myDictionary.keySet()) {
            out.append("Address " + key + " holds value " + this.myDictionary.get(key) + "\n");
        }

        if (this.myDictionary.keySet().size() == 0) {
            out.append("dictionary is empty.\n");
        }

        return out.toString();
    }
}
