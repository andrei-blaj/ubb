package Model.Statements;

import Model.ADT.MyIStack;
import Model.PrgState;

/**
 * Created by Andrei on 20.10.2017.
 */
public class CompStmt implements IStatement {
    private IStatement first;
    private IStatement second;

    public CompStmt(IStatement first, IStatement second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public PrgState execute(PrgState state) {
        MyIStack<IStatement> stack = state.getExeStack();
        stack.push(second);
        stack.push(first);
        return state;
    }

    @Override
    public String toString() {
        return first.toString() + "; " + second.toString();
    }
}
