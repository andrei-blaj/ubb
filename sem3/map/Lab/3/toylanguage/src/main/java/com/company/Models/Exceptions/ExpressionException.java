package com.company.Models.Exceptions;

import com.company.Models.Expression;

public class ExpressionException extends Exception {
    public ExpressionException(String message) {
        super("Toy language, expression exception: " + message);
    }
}
