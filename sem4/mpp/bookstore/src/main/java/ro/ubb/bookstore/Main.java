package ro.ubb.bookstore;

import ro.ubb.bookstore.UI.ConsoleBasedUI;
import ro.ubb.bookstore.domain.models.Book;
import ro.ubb.bookstore.domain.validators.Validator;
import ro.ubb.bookstore.domain.validators.ValidatorException;
import ro.ubb.bookstore.repository.MemoryRepository;
import ro.ubb.bookstore.services.BooksService;

import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        MemoryRepository<Integer, Book> repo = new MemoryRepository<>(new Validator<Book>() {
            @Override
            public void validate(Book entity) throws ValidatorException {

            }
        });

        BooksService booksService = new BooksService(repo);

        ConsoleBasedUI consoleBasedUI = new ConsoleBasedUI(booksService);

        try {
            consoleBasedUI.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
