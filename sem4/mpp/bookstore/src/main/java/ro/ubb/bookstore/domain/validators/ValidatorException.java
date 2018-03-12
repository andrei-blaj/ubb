package ro.ubb.bookstore.domain.validators;

import ro.ubb.bookstore.domain.BookStoreException;

public class ValidatorException extends BookStoreException {
    public ValidatorException(String message) {
        super(message);
    }

    public ValidatorException(String message, Throwable cause) {
        super(message, cause);
    }

    public ValidatorException(Throwable cause) {
        super(cause);
    }
}
