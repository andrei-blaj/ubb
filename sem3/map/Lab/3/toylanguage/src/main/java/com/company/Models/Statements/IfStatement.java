package com.company.Models.Statements;

import com.company.Models.*;
import com.company.Models.ProgramState.ProgramState;
import com.company.Utils.MyIDictionary;
import com.company.Utils.MyIStack;

public class IfStatement implements IStatement {

    private Expression expression;
    private IStatement thenStatement;
    private IStatement elseStatement;

    public IfStatement(Expression expression, IStatement thenStatement, IStatement elseStatement) {

        this.expression = expression;
        this.thenStatement = thenStatement;
        this.elseStatement = elseStatement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIStack<IStatement> stack = state.getExeStack();
        MyIDictionary<String, Integer> symTable = state.getSymTable();

        int expressionValue = this.expression.eval(symTable);

        if (expressionValue != 0) {
            stack.push(this.thenStatement);
        } else {
            stack.push(this.elseStatement);
        }

        return state;
    }

    @Override
    public String toString() {

        return "if (" + this.expression.toString() + ") {\n" +
                "\t" + this.thenStatement.toString() +
                "\nelse {\n" +
                "\t" + this.elseStatement.toString() +
                "\n}";
    }
}
