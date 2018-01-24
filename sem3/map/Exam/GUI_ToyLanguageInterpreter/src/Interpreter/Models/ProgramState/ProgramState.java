package Interpreter.Models.ProgramState;

import Interpreter.Models.ExceptionFactory;
import Interpreter.Models.IStatement;
import Interpreter.Models.Tables.HeapTable;
import Interpreter.Utils.MyIDictionary;
import Interpreter.Utils.MyIList;
import Interpreter.Utils.MyIStack;
import Interpreter.Utils.Pair;

import java.io.BufferedReader;

public class ProgramState implements Cloneable {

    private MyIDictionary<String, Integer> symTable;
    private MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable;
    private HeapTable heapTable;
    private MyIStack<IStatement> exeStack;
    private MyIList<Integer> output;
    // Defined the Latch Table
    private MyIDictionary<Integer, Integer> LatchTable;

    private static Integer countInstances = 0;
    private Integer ID;

    public Integer getID() { return ID; };

    public ProgramState(
            MyIDictionary<String, Integer> symTable,
            MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable,
            HeapTable heapTable,
            MyIStack<IStatement> exeStack,
            MyIList<Integer> output,
            MyIDictionary<Integer, Integer> latchTable) {

        this.symTable = symTable;
        this.fileTable = fileTable;
        this.heapTable = heapTable;
        this.exeStack = exeStack;
        this.output = output;
        this.ID = ++this.countInstances;
        this.LatchTable = latchTable;

    }

    public boolean isNotCompleted() {
        return (this.exeStack.size() > 0);
    }

    public ProgramState executeOneInstruction() throws Exception {

        if (this.exeStack.isEmpty()) {
            throw ExceptionFactory.create("stack", "stack is empty!");
        }

        IStatement statement = this.exeStack.pop();

        return statement.execute(this);
    }

    public MyIDictionary<String, Integer> getSymTable() {
        return this.symTable;
    }

    public MyIDictionary<Integer, Pair<String, BufferedReader>> getFileTable() {
        return this.fileTable;
    }

    public HeapTable getHeapTable() {
        return this.heapTable;
    }

    public MyIStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public MyIList<Integer> getOutput() {
        return this.output;
    }

    public MyIDictionary<Integer, Integer> getLatchTable() { return LatchTable; }

    @Override
    public String toString() {

        return "PROGRAM ID " + this.ID + "\n" +
                this.symTable.toString() + "\n" +
                this.fileTable.toString() + "\n" +
                this.heapTable.toString() + "\n" +
                this.exeStack.toString() + "\n" +
                this.output.toString() + "\n";
    }
}
