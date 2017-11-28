package Model.Expressions;

import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;

/**
 * Created by Andrei on 20.10.2017.
 */
public class ArithmeticExpression extends Expression {
    private Expression e1,e2;
    private char op;

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

    public char getOp() {
        return op;
    }

    public void setOp(char op) {
        this.op = op;
    }

    public ArithmeticExpression(char op,Expression e1, Expression e2) {
        this.e1 = e1;
        this.e2 = e2;
        this.op = op;
    }

    @Override
    public int eval(MyIDictionary<String, Integer> tbl,MyIHeap<Integer,Integer> heap) throws MyExpException{
        if (op == '+')
            return e1.eval(tbl,heap)+e2.eval(tbl,heap);
        else if(op == '-')
            return e1.eval(tbl,heap)-e2.eval(tbl,heap);
        else if(op == '*')
            return e1.eval(tbl,heap)*e2.eval(tbl,heap);
        else
            if(e2.eval(tbl,heap) == 0)
                throw new MyExpException("Division by 0 exception");
            return e1.eval(tbl,heap)/e2.eval(tbl,heap);
        }


    @Override
    public String toString() {
        return e1.toString() + op + e2.toString();

    }
}
