package Model.Statements;

import Exceptions.MyExceptions;
import Model.ADT.MyIStack;
import Model.Expressions.Expression;
import Model.PrgState;

/**
 * Created by Andrei on 20.11.2017.
 */
public class whileStmt implements IStatement {
    Expression exp;
    IStatement stmt;

    public whileStmt(Expression exp, IStatement stmt) {
        this.exp = exp;
        this.stmt = stmt;
    }

    @Override
    public PrgState execute(PrgState state) throws MyExceptions {
        MyIStack<IStatement> stack = state.getExeStack();
        if(exp.eval(state.getSymTable(),state.getHeap()) != 0) {
            IStatement w = new whileStmt(exp,stmt);
            stack.push(w);
            stack.push(stmt);
        }

        return state;
    }

    @Override
    public String toString() {
        return "while (" + exp.toString() + ")" + " {" + stmt.toString() + "}";
    }
}
