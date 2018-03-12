package ro.ubb.bookstore.UI;

import ro.ubb.bookstore.domain.models.Book;
import ro.ubb.bookstore.repository.IRepository;
import ro.ubb.bookstore.services.BooksService;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class ConsoleBasedUI {

    private BooksService booksService;
    private Scanner scanner;
    private BufferedReader bufferedReader;

    public ConsoleBasedUI(BooksService booksService) {
        this.booksService = booksService;
        scanner = new Scanner(System.in);
        bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    }

    public void start() throws IOException {
        while(true) {

            System.out.println("Press 1 to add a book.");
            System.out.println("Press 2 to see all the books.");
            System.out.println("Your command:");

            int cmd = Integer.parseInt(bufferedReader.readLine());

            if (cmd == 1) {
                System.out.println("Title: ");
                String title = bufferedReader.readLine();

                System.out.println("No. of pages: ");
                Integer noOfPages = Integer.parseInt(bufferedReader.readLine());
                System.out.println("Price: ");
                Double price = Double.parseDouble(bufferedReader.readLine());
                System.out.println("Author ID: ");
                Integer authorId = Integer.parseInt(bufferedReader.readLine());

                booksService.createBook(new Book(title, noOfPages, price, authorId));
                continue;
            }

            if (cmd == 2) {
                booksService.printAllBooks();
                continue;
            }

            System.out.println("Invalid command!");
        }
    }


}
