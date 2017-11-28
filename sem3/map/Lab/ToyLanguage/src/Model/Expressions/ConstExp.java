package Model.Expressions;

import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;

/**
 * Created by Andrei on 20.10.2017.
 */
public class ConstExp extends Expression {
    private int number;

    public ConstExp(int number) {

        this.number = number;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }



    @Override
    public int eval(MyIDictionary<String, Integer> tbl,MyIHeap<Integer,Integer> heap) {
        return number;
    }

    @Override
    public String toString() {
        return "" + number;
    }
}
