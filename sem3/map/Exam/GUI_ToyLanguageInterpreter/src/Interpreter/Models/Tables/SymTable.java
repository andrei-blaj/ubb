package Interpreter.Models.Tables;


import Interpreter.Utils.MyDictionary;

import java.util.HashMap;

public class SymTable extends MyDictionary<String, Integer> {

    public SymTable() {
        this.myDictionary = new HashMap<>();
    }

    public SymTable(SymTable symTable) {
        this.myDictionary = (HashMap<String, Integer>) symTable.getMyDictionary().clone();
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