package Model.Statements;

import Model.ADT.MyIDictionary;
import Model.ADT.MyIStack;
import Model.Expressions.Expression;
import Model.Expressions.MyExpException;
import Model.PrgState;

/**
 * Created by Andrei on 21.10.2017.
 */
public class IfStmt implements IStatement {
    private Expression exp;
    private IStatement thenS,elseS;

    public IfStmt(Expression exp, IStatement thenS, IStatement elseS) {
        this.exp = exp;
        this.thenS = thenS;
        this.elseS = elseS;
    }

    @Override
    public PrgState execute(PrgState state) {
        MyIStack<IStatement> stack = state.getExeStack();
        MyIDictionary<String, Integer> tbl = state.getSymTable();
        try {
            if (exp.eval(tbl,state.getHeap()) != 0)
                stack.push(thenS);
            else
                stack.push(elseS);

        }catch(MyExpException e){
            throw new MyStmtException(e.toString());
        }
        return state;
    }

    @Override
    public String toString() {
        return "if(" + exp.toString() + ")" + " THEN " + thenS.toString() + " ELSE "  + elseS.toString();
    }
}
