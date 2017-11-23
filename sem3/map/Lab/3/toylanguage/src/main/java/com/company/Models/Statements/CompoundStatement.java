package com.company.Models.Statements;

import com.company.Models.IStatement;
import com.company.Utils.MyIStack;
import com.company.Models.ProgramState.ProgramState;

public class CompoundStatement implements IStatement {
    private IStatement firstStatement;
    private IStatement secondStatement;

    public CompoundStatement(IStatement firstStatement, IStatement secondStatement) {
        this.firstStatement = firstStatement;
        this.secondStatement = secondStatement;
    }


    @Override
    public ProgramState execute(ProgramState state) {
        MyIStack<IStatement> stack = state.getExeStack();

        stack.push(secondStatement);
        stack.push(firstStatement);

        return state;
    }

    @Override
    public String toString() {
        return firstStatement.toString() + ";" + secondStatement.toString();
    }
}
