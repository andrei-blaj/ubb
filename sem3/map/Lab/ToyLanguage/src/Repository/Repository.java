package Repository;

import Exceptions.MyExceptions;
import Model.PrgState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by Andrei on 21.10.2017.
 */
public class Repository implements IRepository {
    private PrgState[] states;
    private String logFilePath;
    private int currentState;

    public Repository() {
        states = new PrgState[10];
        this.currentState =0;
    }

    public Repository(String logFilePath) {
        this.logFilePath = logFilePath;
        states = new PrgState[10];
        this.currentState =0;

    }

    public PrgState[] getStates() {
        return states;
    }

    public void setStates(PrgState[] states) {
        this.states = states;
    }

    public int getCurrentState() {
        return currentState;
    }

    public void setCurrentState(int currentState) {
        this.currentState = currentState;
    }

    public void add(PrgState state){
        states[currentState++] = state;
    }

    @Override
    public void logPrgStateExec() throws MyExceptions {
        PrintWriter logFile;
        try {
            logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
        }catch(IOException e){
            throw new MyExceptions("Log file can not be opened");
        }
        logFile.append(states[currentState-1].toString());
        logFile.close();

    }

    @Override
    public PrgState getCrtPrg() {
        return states[currentState-1];

    }

    @Override
    public String toString() {
        String str = "";

        for(PrgState state : states)
        {
            str = str + state.toString();
        }
        str = str + "\n\n";
        return str;
    }
}
