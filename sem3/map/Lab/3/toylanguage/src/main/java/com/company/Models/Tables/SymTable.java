package com.company.Models.Tables;

import com.company.Utils.MyDictionary;

import java.util.HashMap;

public class SymTable extends MyDictionary<String, Integer> {

    public SymTable() {
        this.myDictionary = new HashMap<>();
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder("Symbol table: \n");

        for(String key : this.myDictionary.keySet()) {
            out.append(key + " = " + this.myDictionary.get(key) + "\n");
        }

        if (this.myDictionary.keySet().size() == 0) {
            out.append("dictionary is empty.\n");
        }

        return out.toString();
    }
}