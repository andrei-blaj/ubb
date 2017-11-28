package Model.Statements;

import Model.Expressions.Expression;
import Model.Pair;
import Model.PrgState;

import java.io.BufferedReader;
import java.io.IOException;

/**
 * Created by Andrei on 09.11.2017.
 */
public class closeRFile implements IStatement {
    Expression exp_file_id;

    public closeRFile(Expression exp_file_id) {
        this.exp_file_id = exp_file_id;
    }

    @Override
    public PrgState execute(PrgState state) throws MyStmtException {
        BufferedReader buffer;
        int val = exp_file_id.eval(state.getSymTable(),state.getHeap());
        if(state.getFileTable().containsKey(val)) {
            Pair<String, BufferedReader> pair = state.getFileTable().get(val);
            buffer = pair.getSecond();
        }
        else
            throw new MyStmtException("Close File Exception - The key doesn't exists in the file table");
        try{
            buffer.close();
            state.getFileTable().remove(val);
        }catch(IOException e){
            throw new MyStmtException("Buffer can not be closed");
        }
        return state;
    }

    @Override
    public String toString() {
        return "closeRFile(" + exp_file_id.toString() + ")";
    }
}
