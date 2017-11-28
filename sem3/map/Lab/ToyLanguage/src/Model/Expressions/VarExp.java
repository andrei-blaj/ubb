package Model.Expressions;

import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;

/**
 * Created by Andrei on 20.10.2017.
 */
public class VarExp extends Expression {
    private String id;

    public VarExp(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    @Override
    public int eval(MyIDictionary<String, Integer> tbl,MyIHeap<Integer,Integer> heap) throws MyExpException{
        if(tbl.isDefined(id) == false)
            throw new MyExpException("Cannot find key " + id);
        else
            return tbl.get(id);
    }

    @Override
    public String toString() {
        return id;
    }
}
