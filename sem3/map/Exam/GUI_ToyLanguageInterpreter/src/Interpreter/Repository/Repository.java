package Interpreter.Repository;

import Interpreter.Models.ExceptionFactory;
import Interpreter.Models.ProgramState.ProgramState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.ArrayList;


public class Repository implements IRepository {
    private List<ProgramState> data;
    private String logFilePath;

    public Repository(String logFilePath) {
        this.data = new ArrayList<>();
        this.logFilePath = logFilePath;
    }

    public Repository(List<ProgramState> data, String logFilePath) {
        this.data = data;
        this.logFilePath = logFilePath;
    }

    @Override
    public List<ProgramState> getData() {
        return new ArrayList<>(this.data);
    }

    public void setData(List<ProgramState> l) {
        this.data = l;
    }

    @Override
    public void add(ProgramState element) {
        this.data.add(element);
    }

    @Override
    public void remove(ProgramState element) {
        //TODO implement this
    }

    @Override
    public void logProgramState(ProgramState program) throws Exception {
        PrintWriter logger;

        try {
            logger = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));
        } catch (IOException e) {
            throw ExceptionFactory.create("repository", "Couldn't open log file!");
        }

        logger.println("\n-----------------------------------------------\n" + program);

        logger.close();
    }

}
