package Interpreter.Models.Statements;

import Interpreter.Models.Expression;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;

public class newLatch implements IStatement{

    private String var;
    private Expression exp;
    private static int newFreeLocation = -1;

    public newLatch(String var, Expression exp) {
        this.var = var;
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        int number = this.exp.eval(state);

        synchronized (state.getLatchTable()){
            newFreeLocation += 1;

            state.getLatchTable().add(newFreeLocation, number);
            state.getSymTable().add(this.var, newFreeLocation);
        }

        return null;
    }

    @Override
    public String toString()
    {
        return "latch(" + this.var + ',' + this.exp.toString() + ")";
    }
}