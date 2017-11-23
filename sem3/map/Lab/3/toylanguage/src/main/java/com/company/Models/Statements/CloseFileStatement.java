package com.company.Models.Statements;

import com.company.Models.*;
import com.company.Models.ProgramState.ProgramState;
import com.company.Utils.MyIDictionary;
import com.company.Utils.Pair;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseFileStatement implements IStatement {

    private Expression expressionFileID;

    public CloseFileStatement(Expression expressionFileID) {
        this.expressionFileID = expressionFileID;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIDictionary<String, Integer> symbolTable = state.getSymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = state.getFileTable();

        int fileID = this.expressionFileID.eval(symbolTable);

        Pair<String, BufferedReader> fileHandler = fileTable.getValue(fileID);

        BufferedReader reader = fileHandler.getSecond();

        try {
            reader.close();
        } catch(IOException e) {
            throw ExceptionFactory.create("file", "Couldn't close the file!");
        }

        fileTable.remove(fileID);

        return state;
    }

    @Override
    public String toString() {
        return "CloseFile(" + this.expressionFileID + ")";
    }
}
