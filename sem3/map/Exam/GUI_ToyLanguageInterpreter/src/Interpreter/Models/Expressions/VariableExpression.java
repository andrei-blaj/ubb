package Interpreter.Models.Expressions;

import Interpreter.Models.ExceptionFactory;
import Interpreter.Models.Expression;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIDictionary;

public class VariableExpression extends Expression {
    private String variableName;

    public VariableExpression(String variableName) {
        this.variableName = variableName;
    }

    @Override
    public int eval(ProgramState state) throws Exception {
        MyIDictionary<String, Integer> symTable = state.getSymTable();

        if (!symTable.contains(this.variableName)) {
            throw ExceptionFactory.create("variable", "variable not declared!");
        }

        return symTable.getValue(this.variableName);
    }

    @Override
    public String toString() {
        return variableName;
    }
}
