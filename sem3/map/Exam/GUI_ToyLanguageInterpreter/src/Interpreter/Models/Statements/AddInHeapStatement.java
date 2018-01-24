package Interpreter.Models.Statements;

import Interpreter.Models.Expression;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Models.Tables.HeapTable;
import Interpreter.Utils.MyIDictionary;

public class AddInHeapStatement implements IStatement {
    private String variableName;
    private Expression expression;

    public AddInHeapStatement(String variableName, Expression expression) {
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {

        HeapTable heapTable = state.getHeapTable();
        MyIDictionary<String, Integer> symTable = state.getSymTable();

        int value = this.expression.eval(state);

        int address = heapTable.pushValue(value);

        symTable.add(variableName, address);

        return null;
    }

    @Override
    public String toString() {
        return "AddInHeap(" + variableName + ", " + expression + ")";
    }
}
