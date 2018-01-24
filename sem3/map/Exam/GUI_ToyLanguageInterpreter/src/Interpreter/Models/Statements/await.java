package Interpreter.Models.Statements;

import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;

public class await implements IStatement {

    private String var;

    public await(String var){this.var = var;}


    @Override
    public ProgramState execute(ProgramState state) throws Exception {

        if(state.getSymTable().getValue(var) == null){
            throw new Exception("Unknown Variable!\n");
        }

        int number = state.getSymTable().getValue(var);
        Integer count;

        synchronized (state.getLatchTable()){
            if(null == state.getLatchTable().getValue(number)){
                throw new Exception("Variable not in Latch Table");
            }

            count = state.getLatchTable().getValue(number);

            if(count > 0){
                state.getExeStack().push(this);
            }
        }
        return null;

    }

    @Override
    public String toString(){
        return "aWait(" + this.var + ")";
    }
}
