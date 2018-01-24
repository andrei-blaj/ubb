package Interpreter.Models.Statements;

import Interpreter.Models.*;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIDictionary;
import Interpreter.Utils.Pair;

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

        int fileID = this.expressionFileID.eval(state);

        Pair<String, BufferedReader> fileHandler = fileTable.getValue(fileID);

        BufferedReader reader = fileHandler.getSecond();

        try {
            reader.close();
        } catch(IOException e) {
            throw ExceptionFactory.create("file", "Couldn't close the file!");
        }

        fileTable.remove(fileID);

        return null;
    }

    @Override
    public String toString() {
        return "CloseFile(" + this.expressionFileID + ")";
    }
}
