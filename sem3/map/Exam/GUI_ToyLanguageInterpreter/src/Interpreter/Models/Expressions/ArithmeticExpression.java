package Interpreter.Models.Expressions;

import Interpreter.Models.ExceptionFactory;
import Interpreter.Models.Expression;
import Interpreter.Models.ProgramState.ProgramState;

public class ArithmeticExpression extends Expression {
    private Expression rightSide;
    private String operator;
    private Expression leftSide;

    public ArithmeticExpression(Expression leftSide, String operator, Expression rightSide) {
        this.leftSide = leftSide;
        this.operator = operator;
        this.rightSide = rightSide;
    }

    public int eval(ProgramState state) throws Exception {

        int rightSideValue = rightSide.eval(state);
        int leftSideValue = leftSide.eval(state);

        if (operator.equals("+")) {
            return leftSideValue + rightSideValue;
        }

        if (operator.equals("-")) {
            return leftSideValue - rightSideValue;
        }

        if (operator.equals("/")) {
            if (rightSideValue == 0) {
                throw ExceptionFactory.create("expression", "division by 0!");
            }
            return leftSideValue / rightSideValue;
        }

        if (operator.equals("*")) {
            return leftSideValue * rightSideValue;
        }

        if (operator.equals("%")) {
            if (rightSideValue == 0) {
                throw ExceptionFactory.create("expression", "division by 0!");
            }
            return leftSideValue % rightSideValue;
        }

        return 0;
    }

    @Override
    public String toString() {
        return leftSide.toString() + " " + this.operator + " " + rightSide.toString();
    }
}
