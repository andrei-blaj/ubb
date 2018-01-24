package Interpreter.Models.Statements;

import Interpreter.Models.*;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIDictionary;
import Interpreter.Utils.MyIList;

public class PrintStatement implements IStatement {
    private Expression expression;

    public PrintStatement(Expression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIList<Integer> output = state.getOutput();
        MyIDictionary<String, Integer> symTable = state.getSymTable();

        int expressionOutput = this.expression.eval(state);

        System.out.println(expressionOutput);
        output.add(expressionOutput);

        return null;
    }

    @Override
    public String toString() {
        return "print (" + this.expression.toString() + ")";
    }
}
