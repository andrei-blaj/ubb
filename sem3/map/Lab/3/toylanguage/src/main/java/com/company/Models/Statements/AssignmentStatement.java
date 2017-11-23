package com.company.Models.Statements;

import com.company.Models.Expression;
import com.company.Models.IStatement;
import com.company.Utils.MyIDictionary;
import com.company.Models.ProgramState.ProgramState;

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

        int expressionValue = this.expression.eval(symTable);

        if (symTable.contains(this.variableName)) {
            symTable.setValue(this.variableName, expressionValue);
        } else {
            symTable.add(this.variableName, expressionValue);
        }

        return state;
    }

    @Override
    public String toString() {
        return this.variableName + " = " + this.expression.toString();
    }
}
