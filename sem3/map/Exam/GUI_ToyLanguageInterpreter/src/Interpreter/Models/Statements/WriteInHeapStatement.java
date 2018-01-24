package Interpreter.Models.Statements;

import Interpreter.Models.ExceptionFactory;
import Interpreter.Models.Expression;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Models.Tables.HeapTable;
import Interpreter.Utils.MyIDictionary;

public class WriteInHeapStatement implements IStatement {
    private String variableName;
    private Expression expression;

    public WriteInHeapStatement(String variableName, Expression expression) {
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIDictionary<String, Integer> symTable = state.getSymTable();
        HeapTable heapTable = state.getHeapTable();

        int address = symTable.getValue(this.variableName);
        if (!heapTable.contains(address)) {
            throw ExceptionFactory.create("heap", "invalid address location!");
        }

        int value = expression.eval(state);
        heapTable.setValue(address, value);

        return null;
    }

    @Override
    public String toString() {
        return "WriteInHeap(" + variableName + ", " + expression + ")";
    }
}
