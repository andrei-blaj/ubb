package Interpreter.Models.Exceptions;

public class ExpressionException extends Exception {
    public ExpressionException(String message) {
        super("Toy language, expression exception: " + message);
    }
}
