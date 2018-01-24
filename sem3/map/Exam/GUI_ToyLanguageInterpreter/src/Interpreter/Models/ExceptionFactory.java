package Interpreter.Models;

import Interpreter.Models.Exceptions.*;

public class ExceptionFactory {
    public static Exception create(String type, String message) {
        if (type == null) {
            return null;
        }

        if (type.equalsIgnoreCase("expression")) {
            return new ExpressionException(message);
        }

        if (type.equalsIgnoreCase("variable")) {
            return new VariableException(message);
        }

        if (type.equalsIgnoreCase("stack")) {
            return new StackException(message);
        }

        if (type.equalsIgnoreCase("repository")) {
            return new RepositoryException(message);
        }

        if (type.equalsIgnoreCase("file")) {
            return new FileException(message);
        }

        if (type.equalsIgnoreCase("heap")) {
            return new HeapException(message);
        }

        return null;
    }
}
