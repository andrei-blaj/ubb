package Interpreter.Models.Exceptions;

public class StackException extends Exception {
    public StackException(String message) {
        super("Toy language, stack exception: " + message);
    }
}
