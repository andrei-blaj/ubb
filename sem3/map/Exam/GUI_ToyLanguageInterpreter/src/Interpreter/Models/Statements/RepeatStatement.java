package Interpreter.Models.Statements;

import Interpreter.Models.Expression;
import Interpreter.Models.Expressions.BooleanExpression;
import Interpreter.Models.Expressions.ConstantExpression;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIStack;

public class RepeatStatement implements IStatement {
    private Expression expression;
    private IStatement statement;

    public RepeatStatement(IStatement statement, Expression expression) {

        this.expression = expression;
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIStack<IStatement> stack = state.getExeStack();

        stack.push(
                new CompoundStatement(this.statement,
                        new WhileStatement(
                                new BooleanExpression(this.expression,"==", new ConstantExpression(0)), this.statement)
                )
        );

        return null;
    }

    @Override
    public String toString() {
        return "repeat {\n" + this.statement.toString() +" \n} until(" + this.expression.toString() + ")";
    }

}
