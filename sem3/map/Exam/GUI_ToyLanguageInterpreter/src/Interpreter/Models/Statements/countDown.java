package Interpreter.Models.Statements;

import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;

public class countDown implements IStatement {

    private String var;

    public countDown(String var){this.var = var;}

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        if(state.getSymTable().getValue(var) == null){
            throw new Exception("Unknown variable!\n");
        }

        Integer number = state.getSymTable().getValue(var);

        synchronized (state.getLatchTable()){
            if(state.getLatchTable().getValue(number) != null){

                int count = state.getLatchTable().getValue(number);

                if(count > 0){
                    state.getLatchTable().setValue(number, count - 1);
                    state.getOutput().add(state.getID());
                }

            }

        }

        return null;
    }

    @Override
    public String toString(){
        return "countDown(" + var + ")";
    }
}