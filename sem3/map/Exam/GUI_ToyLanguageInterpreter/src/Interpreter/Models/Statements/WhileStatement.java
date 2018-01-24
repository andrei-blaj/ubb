package Interpreter.Models.Statements;

import Interpreter.Models.Expression;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIStack;

public class WhileStatement implements IStatement {

    private Expression expression;
    private IStatement statement;

    public WhileStatement(Expression expression, IStatement statement) {

        this.expression = expression;
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIStack<IStatement> stack = state.getExeStack();

        int expressionValue = this.expression.eval(state);

        if (expressionValue != 0) {
            stack.push(this);
            stack.push(statement);
        }

        return null;
    }

    @Override
    public String toString() {

        return "while (" + this.expression.toString() + ") {\n" +
                this.statement.toString() + "\n}\n";
    }
}
