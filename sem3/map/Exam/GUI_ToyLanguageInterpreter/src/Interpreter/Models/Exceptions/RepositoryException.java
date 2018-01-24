package Interpreter.Models.Exceptions;

public class RepositoryException extends Exception {
    public RepositoryException(String message) {
        super("Toy language, repository exception: " + message);
    }
}
