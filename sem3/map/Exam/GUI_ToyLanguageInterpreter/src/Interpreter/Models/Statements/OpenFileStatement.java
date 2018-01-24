package Interpreter.Models.Statements;

import Interpreter.Models.*;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIDictionary;
import Interpreter.Utils.Pair;

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

        return null;
    }

    @Override
    public String toString() {
        return "OpenFile(" + this.variableFileID + ", \"" + this.filePath + "\")";
    }
}
