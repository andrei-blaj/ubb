package com.company.Models.Expressions;

import com.company.Models.Expression;
import com.company.Utils.MyIDictionary;

public class ConstantExpression extends Expression {
    private int value;

    public ConstantExpression(int value) {
        this.value = value;
    }

    @Override
    public int eval(MyIDictionary<String, Integer> symTable) {
        return this.value;
    }

    @Override
    public String toString() {
        return ""+this.value;
    }
}
