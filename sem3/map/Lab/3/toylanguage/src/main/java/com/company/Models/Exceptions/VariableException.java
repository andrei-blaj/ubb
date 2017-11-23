package com.company.Models.Exceptions;

public class VariableException extends Exception {

    public VariableException(String message) {
        super("Toy language, variable exception: " + message);
    }
}
