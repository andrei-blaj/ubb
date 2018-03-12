package ro.ubb.bookstore.domain.models;

public class Book extends ModelBase<Integer> {

    private final String title;
    private final Integer noOfPages;
    private final Integer authorId;
    private final Double price;

    public Book(String title, Integer noOfPages, Double price, Integer authorId) {
        this.title = title;
        this.noOfPages = noOfPages;
        this.authorId = authorId;
        this.price = price;
    }


    public String getTitle() {
        return title;
    }

    public Integer getNoOfPages() {
        return noOfPages;
    }

    public Double getPrice() {
        return price;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }

        Book book = (Book)obj;

        return this.title.equalsIgnoreCase(book.title)
                && this.price.equals(book.price)
                && this.noOfPages.equals(book.noOfPages);
    }


    public Integer getAuthorId() {
        return authorId;
    }

    @Override
    public int hashCode() {
        int result = title.hashCode();
        result = 101 * result + price.hashCode();
        result = 101 * result + noOfPages.hashCode();

        return result;
    }

    @Override
    public String toString() {
        return "Book {" + "\n"
                + "Title = " + title + "\n"
                + "Number of pages = " + noOfPages + "\n"
                + "Price = " + price + "\n"
                + super.toString() + "\n"
                + "}\n";
    }
}
