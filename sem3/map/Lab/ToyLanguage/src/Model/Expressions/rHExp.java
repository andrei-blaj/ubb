package Model.Expressions;

import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;

/**
 * Created by Andrei on 26.11.2017.
 */
public class rHExp extends Expression {
    private String var_name;

    public rHExp(String var_name) {
        this.var_name = var_name;
    }


    @Override
    public int eval(MyIDictionary<String, Integer> tbl, MyIHeap<Integer,Integer> heap) throws MyExpException {
        int address;
        if(tbl.isDefined(var_name))
            address = tbl.get(var_name);
        else
            throw new MyExpException("Variable not found in SymTable");

        if(heap.containsKey(address))
            return heap.get(address);
        else
            throw new MyExpException("Address not found in heap");

    }

    @Override
    public String toString() {
        return "rH(" + var_name + ")";
    }
}
