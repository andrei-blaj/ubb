package com.company.Models.Tables;

import com.company.Utils.MyDictionary;
import com.company.Utils.Pair;

import java.io.BufferedReader;
import java.util.HashMap;

public class FileTable extends MyDictionary<Integer, Pair<String, BufferedReader>> {

    public FileTable() {
        this.myDictionary = new HashMap<>();
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder("File table: \n");

        for(Integer key : this.myDictionary.keySet()) {
            out.append(key + " --> " + this.myDictionary.get(key).getFirst() + "\n");
        }

        if (this.myDictionary.keySet().size() == 0) {
            out.append("dictionary is empty.\n");
        }

        return out.toString();
    }
}
