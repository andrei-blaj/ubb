package Model.Expressions;

import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;

/**
 * Created by Andrei on 20.11.2017.
 */
public class RelationExp extends Expression {
    String op;
    Expression e1,e2;

    public RelationExp(String op, Expression e1, Expression e2) {
        this.op = op;
        this.e1 = e1;
        this.e2 = e2;
    }

    public String getOp() {
        return op;
    }

    public void setOp(String op) {
        this.op = op;
    }

    public Expression getE1() {
        return e1;
    }

    public void setE1(Expression e1) {
        this.e1 = e1;
    }

    public Expression getE2() {
        return e2;
    }

    public void setE2(Expression e2) {
        this.e2 = e2;
    }

    @Override
    public int eval(MyIDictionary<String, Integer> tbl, MyIHeap<Integer, Integer> heap) throws MyExpException {
        if(op == ">")
            if(e1.eval(tbl,heap) > e2.eval(tbl,heap))
                return 1;
            else return 0;
        else if(op == ">=")
            if(e1.eval(tbl,heap) >= e2.eval(tbl,heap))
                return 1;
            else return 0;
        else if(op == "<")
            if(e1.eval(tbl,heap) < e2.eval(tbl,heap))
                return 1;
            else return 0;
        else if(op == "<=")
            if(e1.eval(tbl,heap) <= e2.eval(tbl,heap))
                return 1;
            else return 0;
        else if(op == "==")
            if(e1.eval(tbl,heap) == e2.eval(tbl,heap))
                return 1;
            else return 0;
        else
            if(e1.eval(tbl,heap) != e2.eval(tbl,heap))
                return 1;
            else return 0;
    }

    @Override
    public String toString() {
        return "(" + e1.toString() + op + e2.toString() + ")";
    }
}
