package com.company.Models.Statements;

import com.company.Models.*;
import com.company.Models.ProgramState.ProgramState;
import com.company.Utils.MyIDictionary;
import com.company.Utils.Pair;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFileStatement implements IStatement {
    private String variableName;
    private Expression expressionFileID;

    public ReadFileStatement(String variableName, Expression expressionFileID) {
        this.variableName = variableName;
        this.expressionFileID = expressionFileID;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIDictionary<String, Integer> symbolTable = state.getSymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = state.getFileTable();

        int fileID = this.expressionFileID.eval(symbolTable);

        Pair<String, BufferedReader> fileHandler = fileTable.getValue(fileID);

        BufferedReader reader = fileHandler.getSecond();

        String line;

        try {
            line = reader.readLine();
        } catch(IOException e) {
            throw ExceptionFactory.create("file", "Couldn't read from file!");
        }

        Integer value = line != null ? Integer.parseInt(line) : 0;

        symbolTable.add(this.variableName, value);

        return state;
    }

    @Override
    public String toString() {
        return "ReadFile(" + this.expressionFileID + ")";
    }
}
