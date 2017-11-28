package Model.Expressions;

import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;

/**
 * Created by Andrei on 20.10.2017.
 */
public abstract class Expression{
    abstract public int eval(MyIDictionary<String,Integer> tbl,MyIHeap<Integer,Integer> heap) throws MyExpException;
}
