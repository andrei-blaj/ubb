package Model.Statements;

import Exceptions.MyExceptions;
import Model.Pair;
import Model.PrgState;
import Model.Expressions.Expression;
import java.io.BufferedReader;
import java.io.IOException;

/**
 * Created by Andrei on 09.11.2017.
 */
public class readFile implements IStatement {
    Expression exp_file_id;
    String var_name;

    public readFile(Expression exp_file_id, String var_name) {
        this.exp_file_id = exp_file_id;
        this.var_name = var_name;
    }

    @Override
    public PrgState execute(PrgState state) throws MyExceptions {
        BufferedReader buffer;
        int val = exp_file_id.eval(state.getSymTable(),state.getHeap());
        if(state.getFileTable().containsKey(val)){
            Pair<String, BufferedReader> pair = state.getFileTable().get(val);
            buffer = pair.getSecond();
            try {
                String line = buffer.readLine();


                int value;
                if (line == null)
                    value = 0;
                else
                    value = Integer.parseInt(line);

                if (state.getSymTable().isDefined(var_name))
                    state.getSymTable().update(var_name, value);
                else
                    state.getSymTable().put(var_name, value);
            }catch(IOException e){
                throw new MyStmtException(e.toString());
            }
        }
        else
            throw new MyStmtException("Read File Exception - The key is no in the file table");


        return state;
    }

    @Override
    public String toString() {
        return "readFile(" + exp_file_id.toString() + ", " + var_name + ")";
    }
}
