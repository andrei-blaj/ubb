package Interpreter.Models.Statements;

import Interpreter.Models.*;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIStack;

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

        int expressionValue = this.expression.eval(state);

        if (expressionValue != 0) {
            stack.push(this.thenStatement);
        } else {
            stack.push(this.elseStatement);
        }

        return null;
    }

    @Override
    public String toString() {

        return "if (" + this.expression.toString() + ") {\n" +
                this.thenStatement.toString() +
                "\nelse {\n" +
                this.elseStatement.toString() +
                "\n}\n";
    }
}
