package Interpreter.Models.Statements;

import Interpreter.Models.IStatement;
import Interpreter.Utils.MyIStack;
import Interpreter.Models.ProgramState.ProgramState;

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

        return null;
    }

    @Override
    public String toString() {
        return firstStatement.toString() + "\n" + secondStatement.toString();
    }
}
