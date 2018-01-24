package Interpreter.Models.Expressions;

import Interpreter.Models.Expression;
import Interpreter.Models.ProgramState.ProgramState;

public class ConstantExpression extends Expression {
    private int value;

    public ConstantExpression(int value) {
        this.value = value;
    }

    @Override
    public int eval(ProgramState state) {
        return this.value;
    }

    @Override
    public String toString() {
        return ""+this.value;
    }
}
