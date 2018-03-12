package ro.ubb.bookstore.services;

import ro.ubb.bookstore.domain.BookStoreException;
import ro.ubb.bookstore.repository.*;
import ro.ubb.bookstore.domain.models.*;

import java.util.Iterator;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class BooksService {

    private IRepository<Integer, Book> repo;

    public BooksService(IRepository<Integer, Book> repo)
    {
        this.repo=repo;
    }


    /*
     * Adds the given book to the repository.
     * param: Book
     * return: -
     * throws BookStoreException if the book is already in the repo.
     */
    public void createBook(Book book) {
        Iterable<Book> allBooks= this.repo.findAll();

        for(Book currentBook: allBooks) {
            if (currentBook.equals(book)) {
                throw new BookStoreException("Create failed - the book already in the database");
            }
        }
        this.repo.save(book);
    }


    /*
     * Reads all the books from the repository.
     * param: -
     * return: -
     */
    public Iterable<Book> readBooks()
    {
        return this.repo.findAll();
    }


    /*
     * Deletes the given book from the repository.
     * param: Book
     * return: -
     * throws BookStoreException if the book is not in the repo.
     */
    public Optional<Book> deleteBook(Book book) {
        Iterable<Book> allBooks = this.repo.findAll();

        for (Book currentBook: allBooks) {
            if (currentBook.equals(book)) {
                return this.repo.delete(book.getId());
            }

        }

        throw new BookStoreException("Delete failed - the book is not in the database");
    }

    /*
     * Updates a given book from the repository.
     * param: Book
     * return: -
     * throws BookStoreException if the book is not in the repo.
     */
    public void update(Book book)
    {
//        Iterable<Book> allBooks = this.repo.findAll();
//        for(Book currentBook: allBooks) {
//            if (currentBook.getTitle().equals(book.getTitle())) {
//                currentBook.setNoOfPages(book.getNoOfPages());
//                currentBook.setPrice(book.getPrice());
//                return;
//            }
//        }
//        throw new BookStoreException("Update failed - the book is not in the database");
    }


    /*
     * Prints the books from the repository.
     * param: -
     * return: -
     */
    public void printAllBooks() {
        Iterable<Book> allBooks= this.repo.findAll();
        for(Book book: allBooks) {
            System.out.println(book.toString());
        }
    }

    /*
     * Returns all books from the repository containing a given string.
     * param: String
     * return: -
     */
    public Set<Book> filterByName(String bookName) {
        Iterable<Book> allBooks= this.repo.findAll();
        return StreamSupport.stream(allBooks.spliterator(), false)
                .filter(book -> book.getTitle().contains(bookName))
                .collect(Collectors.toSet());
    }
}