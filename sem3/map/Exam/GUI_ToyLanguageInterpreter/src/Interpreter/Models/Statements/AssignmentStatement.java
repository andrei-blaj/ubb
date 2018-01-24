package Interpreter.Models.Statements;

import Interpreter.Models.Expression;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIDictionary;

public class AssignmentStatement implements IStatement {
    private String variableName;
    private Expression expression;

    public AssignmentStatement(String variableName, Expression expression) {
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIDictionary<String, Integer> symTable = state.getSymTable();

        int expressionValue = this.expression.eval(state);

        if (symTable.contains(this.variableName)) {
            symTable.setValue(this.variableName, expressionValue);
        } else {
            symTable.add(this.variableName, expressionValue);
        }

        return null;
    }

    @Override
    public String toString() {
        return this.variableName + " = " + this.expression.toString();
    }
}
