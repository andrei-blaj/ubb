"""
A customer has a unique number (id), a name, a CNP, and an address. 

A rental has: <customer>, <book>, <date>, <#days>.


The application allows:

* CRUD Operation (Create, Read, Update, Delete) for books, customers

* Search (books, customers)

* Rental / response

* 2 Sort (eg sorted by name / price / title, ...).

* 3 filters (eg search for authors who has published more than 3 books / searches for customers who has rented books ...)

* Report: Number of active customers sorted by year

	  year number

	  -------------------------------

	   2014 7

	   2015 10

	   2016 5



Remarks:

- the program follows a layer architecture (console, domain, ...)

- tests for each repository, controller,

- Comments, code clear

- Consolle application (Menu);

   Eg 1 - Add book;

         2 - remove book;

	 ...

"""
from bookrepo.bookrepo import *
from book.book import *
from customerrepo.customerrepo import *
from customer.customer import *
from rentalrepo.rentalrepo import *
from rental.rental import *
from menu.menu import UI

bookController = bookRepository()
customerController = customerRepository()
rentalController = rentalRepository()

bookController.addBook(["1","title","description","author","price"])
bookController.addBook(["2","title1","description1","author1","price1"])
bookController.addBook(["3","title2","description2","author2","price2"])
bookController.addBook(["4","title3","description3","author3","price3"])
bookController.addBook(["5","title4","description4","author4","price4"])
bookController.addBook(["6","title5","description5","author5","price5"])
bookController.addBook(["7","title6","description6","author6","price6"])
bookController.addBook(["8","title7","description7","author7","price7"])
bookController.addBook(["9","title8","description8","author8","price8"])
bookController.addBook(["10","title9","description9","author9","price9"])
bookController.addBook(["11","title10","description10","author10","price10"])

customerController.addCustomer(["1","name","cnp","address"])
customerController.addCustomer(["2","name1","cnp1","address1"])
customerController.addCustomer(["3","name2","cnp2","address2"])
customerController.addCustomer(["4","name3","cnp3","address3"])
customerController.addCustomer(["5","name4","cnp4","address4"])
customerController.addCustomer(["6","name5","cnp5","address5"])
customerController.addCustomer(["7","name6","cnp6","address6"])
customerController.addCustomer(["8","name7","cnp7","address7"])
customerController.addCustomer(["9","name8","cnp8","address8"])
customerController.addCustomer(["10","name9","cnp9","address9"])

ui = UI(bookController, customerController, rentalController)

ui.mainMenu()