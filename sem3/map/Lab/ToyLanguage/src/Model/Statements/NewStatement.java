package Model.Statements;

import Exceptions.MyExceptions;
import Model.Expressions.Expression;
import Model.PrgState;

/**
 * Created by Andrei on 26.11.2017.
 */
public class NewStatement implements IStatement {
    String var_name;
    Expression exp;

    public NewStatement(String var_name, Expression exp) {
        this.var_name = var_name;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) throws MyExceptions {
        int val = this.exp.eval(state.getSymTable(), state.getHeap());
        state.getHeap().put(state.getHeap().getFreeAddress(), val);
        if(state.getSymTable().isDefined(var_name))
            state.getSymTable().update(var_name,state.getHeap().getFreeAddress());
        else
            state.getSymTable().put(var_name,state.getHeap().getFreeAddress());
        state.getHeap().setFreeAddress(state.getHeap().getFreeAddress()+1);
        return state;
    }

    @Override
    public String toString() {
        return "new(" + var_name + "," + exp.toString() + ")";
    }
}
