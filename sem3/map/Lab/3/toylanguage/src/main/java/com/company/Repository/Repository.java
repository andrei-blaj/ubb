package com.company.Repository;

import com.company.Models.ExceptionFactory;
import com.company.Utils.MyIList;
import com.company.Utils.MyList;
import com.company.Models.ProgramState.ProgramState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Repository implements IRepository {
    private MyIList<ProgramState> data;
    private String logFilePath;

    public Repository(String logFilePath) {
        this.data = new MyList<>();
        this.logFilePath = logFilePath;
    }

    public Repository(MyIList<ProgramState> data, String logFilePath) {
        this.data = data;
        this.logFilePath = logFilePath;
    }

    @Override
    public MyIList<ProgramState> getData() {
        return this.data;
    }

    @Override
    public void add(ProgramState element) {
        this.data.add(element);
    }

    @Override
    public void remove(ProgramState element) {

    }

    @Override
    public void logProgramState() throws Exception {
        PrintWriter logger;

        try {
            logger = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));
        } catch (IOException e) {
            throw ExceptionFactory.create("repository", "Couldn't open log file!");
        }

        for(int i = 0; i < this.data.size(); i++) {
            logger.println("\n-----------------------------------------------\n"
                    + this.data.get(i));
        }

        logger.close();
    }

}
