package Model.Statements;

import Model.ADT.MyIDictionary;
import Model.ADT.MyIList;
import Model.ADT.MyIStack;
import Model.Expressions.Expression;
import Model.Expressions.MyExpException;
import Model.PrgState;

/**
 * Created by Andrei on 20.10.2017.
 */
public class PrintStmt implements IStatement {

    private Expression exp;

    public PrintStmt(Expression exp) {
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {
        MyIStack<IStatement> stack = state.getExeStack();
        MyIList<Integer> list = state.getOut();
        MyIDictionary<String,Integer> symTbl = state.getSymTable();
        try {
            list.add(exp.eval(symTbl,state.getHeap()));
        }catch(MyExpException e){
            throw new MyStmtException(e.toString());
        }
        return state;
    }

    @Override
    public String toString() {
        return "print(" + exp.toString() + ")";
    }
}
