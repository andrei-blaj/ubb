package com.company.Models.ProgramState;

import com.company.Models.IStatement;
import com.company.Utils.MyIDictionary;
import com.company.Utils.MyIList;
import com.company.Utils.MyIStack;
import com.company.Utils.Pair;

import java.io.BufferedReader;
import java.time.LocalTime;

public class ProgramState {

    private MyIDictionary<String, Integer> symTable;
    private MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable;
    private MyIStack<IStatement> exeStack;
    private MyIList<Integer> output;

    public ProgramState(
            MyIDictionary<String, Integer> symTable,
            MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable,
            MyIStack<IStatement> exeStack,
            MyIList<Integer> output) {

        this.symTable = symTable;
        this.fileTable = fileTable;
        this.exeStack = exeStack;
        this.output = output;
    }

    public MyIDictionary<String, Integer> getSymTable() {
        return this.symTable;
    }

    public MyIDictionary<Integer, Pair<String, BufferedReader>> getFileTable() {
        return this.fileTable;
    }

    public MyIStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public MyIList<Integer> getOutput() {
        return this.output;
    }

    @Override
    public String toString() {

        return "Date: "+ LocalTime.now() + "\n\n" +
                this.symTable.toString() + "\n" +
                this. exeStack.toString() + "\n" +
                this.output.toString() + "\n";
    }
}
