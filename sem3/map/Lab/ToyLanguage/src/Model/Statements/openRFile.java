package Model.Statements;

import Model.PrgState;
import Model.Pair;
import java.io.*;

/**
 * Created by Andrei on 08.11.2017.
 */
public class openRFile implements IStatement {
    String var_file_id;
    String filename;
    static int id=0;

    public openRFile(String var_file_id, String filename) {
        this.var_file_id = var_file_id;
        this.filename = filename;
    }

    @Override
    public PrgState execute(PrgState state) {
        if(state.getFileTable().containsKey(this.id) == true)
            throw new MyStmtException("File already exists");
        try{
            FileInputStream in = new FileInputStream(this.filename);
            BufferedReader buffer = new BufferedReader(new InputStreamReader(in));
            state.getFileTable().put(id,new Pair(var_file_id,buffer));
            state.getSymTable().put(var_file_id,id);
            this.id = id++;
        }catch(FileNotFoundException e){
            throw new MyStmtException("File " + filename + " not found");
        }

        return state;
    }

    @Override
    public String toString() {
        return "openRFile("  + var_file_id + "," + filename + ")";
    }
}
