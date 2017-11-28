package Model.Statements;

import Exceptions.MyExceptions;
import Model.Expressions.Expression;
import Model.PrgState;

/**
 * Created by Andrei on 26.11.2017.
 */
public class wHStmt implements IStatement {
    String var_name;
    Expression exp;

    public wHStmt(String var_name, Expression exp) {
        this.var_name = var_name;
        this.exp = exp;
    }


    @Override
    public PrgState execute(PrgState state) throws MyExceptions {
        int address;
        if(state.getSymTable().isDefined(var_name))
            address = state.getSymTable().get(var_name);
        else
            throw new MyStmtException("Variable not found in SymTable");

        int val = exp.eval(state.getSymTable(),state.getHeap());

        if(state.getHeap().containsKey(address))
            state.getHeap().update(address,val);
        else
            throw new MyStmtException("Address not found in heap");

        return state;
    }

    @Override
    public String toString() {
        return "wH(" + var_name + "," + exp.toString() + ")";
    }
}
