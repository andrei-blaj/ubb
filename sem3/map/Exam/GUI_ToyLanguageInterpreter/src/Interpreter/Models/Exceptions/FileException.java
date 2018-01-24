package Interpreter.Models.Exceptions;

public class FileException extends Exception {
    public FileException(String message) {
        super("Toy language, file exception: " + message);
    }
}
