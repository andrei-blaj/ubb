from rental.rental import *
from customer.customer import *
from book.book import *

def testRentals():
    rental1 = rental("1","12","date","10")
    rental2 = rental("2","31","date1","11")
    rental3 = rental("3","32","date2","14")
    rental4 = rental("4","41","date3","100")

    assert rental1.returnCustomerId() == "1"
    assert rental2.returnCustomerId() == "2"
    assert rental3.returnCustomerId() == "3"
    assert rental4.returnCustomerId() == "4"

    assert rental1.returnBookId() == "12"
    assert rental2.returnBookId() == "31"
    assert rental3.returnBookId() == "32"
    assert rental4.returnBookId() == "41"

    assert rental1.returnDate() == "date"
    assert rental2.returnDate() == "date1"
    assert rental3.returnDate() == "date2"
    assert rental4.returnDate() == "date3"

    assert rental1.returnDays() == "10"
    assert rental2.returnDays() == "11"
    assert rental3.returnDays() == "14"
    assert rental4.returnDays() == "100"

    assert rental1.returnDateYear() == "date"
    assert rental2.returnDateYear() == "date"
    assert rental3.returnDateYear() == "date"
    assert rental4.returnDateYear() == "date"

def testCustomer():
    customer1 = customer("1","12","date","10")
    customer2 = customer("2","31","date1","11")
    customer3 = customer("3","32","date2","14")
    customer4 = customer("4","41","date3","100")

    assert customer1.returnCustomerId() == "1"
    assert customer2.returnCustomerId() == "2"
    assert customer3.returnCustomerId() == "3"
    assert customer4.returnCustomerId() == "4"

    assert customer1.returnCustomerName() == "12"
    assert customer2.returnCustomerName() == "31"
    assert customer3.returnCustomerName() == "32"
    assert customer4.returnCustomerName() == "41"

    assert customer1.returnCustomerCnp() == "date"
    assert customer2.returnCustomerCnp() == "date1"
    assert customer3.returnCustomerCnp() == "date2"
    assert customer4.returnCustomerCnp() == "date3"

    assert customer1.returnCustomerAdd() == "10"
    assert customer2.returnCustomerAdd() == "11"
    assert customer3.returnCustomerAdd() == "14"
    assert customer4.returnCustomerAdd() == "100"

def testBooks():
    book1 = book("1","12","date","10","12")
    book2 = book("2","31","date1","11","13")
    book3 = book("3","32","date2","14","14")
    book4 = book("4","41","date3","100","15")

    assert book1.returnBookId() == "1"
    assert book2.returnBookId() == "2"
    assert book3.returnBookId() == "3"
    assert book4.returnBookId() == "4"

    assert book1.returnBookTitle() == "12"
    assert book2.returnBookTitle() == "31"
    assert book3.returnBookTitle() == "32"
    assert book4.returnBookTitle() == "41"

    assert book1.returnBookDesc() == "date"
    assert book2.returnBookDesc() == "date1"
    assert book3.returnBookDesc() == "date2"
    assert book4.returnBookDesc() == "date3"

    assert book1.returnBookAuthor() == "10"
    assert book2.returnBookAuthor() == "11"
    assert book3.returnBookAuthor() == "14"
    assert book4.returnBookAuthor() == "100"

    assert book1.returnBookPrice() == "12"
    assert book2.returnBookPrice() == "13"
    assert book3.returnBookPrice() == "14"
    assert book4.returnBookPrice() == "15"

def testAll():
    testRentals()
    testCustomer()
    testBooks()
