package com.company.Models.Statements;

import com.company.Models.*;
import com.company.Models.ProgramState.ProgramState;
import com.company.Utils.MyIDictionary;
import com.company.Utils.Pair;

import java.io.*;

public class OpenFileStatement implements IStatement {
    private String variableFileID;
    private String filePath;

    public OpenFileStatement(String variableFileID, String filePath) {
        this.variableFileID = variableFileID;
        this.filePath = filePath;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = state.getFileTable();
        MyIDictionary<String, Integer> symbolTable = state.getSymTable();

        for(Integer key: fileTable.getKeys()) {
            if (fileTable.getValue(key).getFirst().equals(this.filePath)) {
                throw ExceptionFactory.create("file", "File is already open!");
            }
        }

        BufferedReader reader;

        try {
            reader = new BufferedReader(new FileReader(this.filePath));
        } catch (FileNotFoundException e) {
            throw ExceptionFactory.create("file", "Couldn't open file!");
        }

        int fileID = reader.hashCode();

        fileTable.add(fileID, new Pair<>(this.filePath, reader));
        symbolTable.add(this.variableFileID, fileID);

        return state;
    }

    @Override
    public String toString() {
        return "OpenFile(" + this.variableFileID + ", \"" + this.filePath + "\")";
    }
}
