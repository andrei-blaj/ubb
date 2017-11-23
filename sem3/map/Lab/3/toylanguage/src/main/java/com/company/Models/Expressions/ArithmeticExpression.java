package com.company.Models.Expressions;

import com.company.Models.ExceptionFactory;
import com.company.Models.Expression;
import com.company.Utils.MyIDictionary;

public class ArithmeticExpression extends Expression {
    private Expression rightSide;
    private String operator;
    private Expression leftSide;

    public ArithmeticExpression(Expression rightSide, String operator, Expression leftSide) {
        this.rightSide = rightSide;
        this.operator = operator;
        this.leftSide = leftSide;
    }

    public int eval(MyIDictionary<String, Integer> symTable) throws Exception {

        int rightSideValue = rightSide.eval(symTable);
        int leftSideValue = leftSide.eval(symTable);

        if (operator.equals("+")) {
            return rightSideValue + leftSideValue;
        }

        if (operator.equals("-")) {
            return rightSideValue - leftSideValue;
        }

        if (operator.equals("/")) {
            if (leftSideValue == 0) {
                throw ExceptionFactory.create("expression", "division by 0!");
            }
            return rightSideValue / leftSideValue;
        }

        if (operator.equals("*")) {
            return rightSideValue * leftSideValue;
        }

        if (operator.equals("%")) {
            if (leftSideValue == 0) {
                throw ExceptionFactory.create("expression", "division by 0!");
            }
            return rightSideValue % leftSideValue;
        }

        return 0;
    }

    @Override
    public String toString() {
        return rightSide.toString() + " " + this.operator + " " + leftSide.toString();
    }
}
