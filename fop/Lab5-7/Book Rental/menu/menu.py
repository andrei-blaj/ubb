import os
from bookrepo.bookrepo import *
from customerrepo.customerrepo import *
from rentalrepo.rentalrepo import *
import datetime

class UI:
	def __init__(self, bookController, customerController, rentalController):
		self._bookController = bookController
		self._customerController = customerController
		self._rentalController = rentalController

	@staticmethod 
	def printMenu():
		s = 'Available commands:\n'
		s += '   1. Add (books or customers)\n'
		s += '   2. Remove (books or customers)\n'
		s += '   3. Update (books or customers)\n'
		s += '   4. Search (books or customers)\n'
		s += '   5. Rent a book\n'
		s += '   6. Return a book\n'
		s += '   7. Sort (Books by name, price, title, autor, Customers by name)\n'
		s += '   8. Filter data\n'
		s += '   9. Report (Number of active customers sorted by year)\n'
		s += '   10. Exit\n'
		print(s)

	@staticmethod
	def userInput(s):
		"""
			This method returns what the user has inserted into the program
		"""
		userInput = raw_input("%s" % s)
		return userInput

	@staticmethod
	def isNotValid(s):
		l = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]
		if s in l:
			return False
		return True

	### ADD ###########################################################################################

	def add(self):
		os.system('clear')

		opType = ''
		while opType not in ['1', '2']:
			opType = self.userInput("What would you like to add?\n   1. Book\n   2. Customer\n ~: ")

		if opType == '1':
			"""
				The user has selected to add a book
			"""
			book = self.getDataForBook('')
			self.addNewBook(book)
		else:
			"""
				The user has selected to add a customer
			"""
			customer = self.getDataForCustomer('')
			self.addNewCustomer(customer)

		os.system('clear')
		print("Addition successful!")

	def getDataForBook(self, aux):
		iD = self.userInput("Insert the book ID: ")
		title = self.userInput("Insert the%s book title: " % aux)
		desc = self.userInput("Insert the%s book description: " % aux)
		author = self.userInput("Insert the%s book author: " % aux)
		price = self.userInput("Insert the%s book price: " % aux)

		return [iD, title, desc, author, price]

	def addNewBook(self, book):
		self._bookController.addBook(book)

	def getDataForCustomer(self, aux):
		iD = self.userInput("Insert the customer ID: ")
		name = self.userInput("Insert the%s customer name: " % aux)
		cnp = self.userInput("Insert the%s customer CNP: " % aux)
		address = self.userInput("Insert the%s customer address: " % aux)

		return [iD, name, cnp, address]

	def addNewCustomer(self, customer):
		self._customerController.addCustomer(customer)

	### REMOVE ########################################################################################

	def remove(self):
		os.system('clear')
		
		opType = ''
		while opType not in ['1', '2']:
			opType = self.userInput("What would you like to remove?\n   1. Book\n   2. Customer\n ~: ")

		if opType == '1':
			"""
				The user has selected to add a book
			"""
			bookId = self.getBookId()
			message = self.removeBook(bookId)
		else:
			"""
				The user has selected to add a customer
			"""
			customerId = self.getCustomerId()
			message = self.removeCustomer(customerId)

		os.system('clear')
		print("%s" % message)

	def getBookId(self):
		bookId = self.userInput("Insert the book ID: ")
		return bookId

	def removeBook(self, bookId):
		return self._bookController.removeBook(bookId)

	def getCustomerId(self):
		customerId = self.userInput("Insert the customer ID: ")
		return customerId

	def removeCustomer(self, customerId):
		return self._customerController.removeCustomer(customerId)

	### UPDATE ########################################################################################

	def update(self):
		os.system('clear')
		
		opType = ''
		while opType not in ['1', '2']:
			opType = self.userInput("What would you like to update?\n   1. Book\n   2. Customer\n ~: ")

		if opType == '1':
			"""
				The user has selected to add a book
			"""
			book = self.getDataForBook(' new')
			message = self.updateBook(book)
		else:
			"""
				The user has selected to add a customer
			"""
			customer = self.getDataForCustomer(' new')
			message = self.updateCustomer(customer)

		os.system('clear')
		print("%s" % message)

	def updateBook(self, book):
		return self._bookController.update(book)

	def updateCustomer(self, customer):
		return self._customerController.update(customer)

	### SEARCH ########################################################################################

	def search(self):
		os.system('clear')
		
		opType = ''
		while opType not in ['1', '2']:
			opType = self.userInput("What would you like to search for?\n   1. Book\n   2. Customer\n ~: ")

		if opType == '1':
			"""
				The user has selected to add a book
			"""
			book = self.userInput("Book title: ")
			message = self.searchForBook(book)
		else:
			"""
				The user has selected to add a customer
			"""
			customer = self.userInput("Customer name: ")
			message = self.searchForCustomer(customer)

		os.system('clear')
		print("%s" % message)

	def searchForBook(self, bookTitle):
		return self._bookController.getBook(bookTitle)

	def searchForCustomer(self, customerName):
		return self._customerController.getCustomer(customerName)

	### RENT ##########################################################################################

	def rent(self):
		os.system('clear')

		rentData = self.getRentData()
		self._rentalController.add(rentData)

		return "Rental successful!"

	def getRentData(self):
		customerId = self.userInput("Insert the customer id: ")
		bookId = self.userInput("Insert the bookId: ")
		
		opType = ''
		while opType not in ['1', '2']:
			opType = self.userInput("What would you like to us?\n   1. Today's date\n   2. Custom date\n ~: ")

		if opType == '1':
			today = datetime.datetime.now()
			day = today.day
			month = today.month
			year = today.year
			date = str(year) + '.' + str(month) + '.' + str(day) 
		else:
			day = self.userInput("Insert the day: ")
			month = self.userInput("Insert the month: ")
			year = self.userInput("Insert the year: ")
			date = str(year) + '.' + str(month) + '.' + str(day) 

		numberOfDays = self.userInput("Insert the number of days you want to rent it for: ")

		return [customerId, bookId, date, numberOfDays]


	### RETURN ########################################################################################

	def returns(self):
		os.system('clear')

		bookId = self.userInput("Insert the book ID: ")

		return self._rentalController.returns(bookId)

	### SORT ##########################################################################################

	def sort(self):
		os.system('clear')

		opType = ''
		while opType not in ['1', '2']:
			opType = self.userInput("What would you like to sort?\n   1. Book\n   2. Customer\n ~: ")

		if opType == '1':
			"""
				The user has selected to add a book
			"""
			sortingCateg = self.getSortingCateg('book')
			s = self._bookController.sortBy(sortingCateg)

			print s

		else:
			"""
				The user has selected to add a customer
			"""
			sortingCateg = self.getSortingCateg('cust')
			s = self._customerController.sortBy(sortingCateg)

			print s

	def	getSortingCateg(self, t):
		if t == 'book':
			opType = ''
			while opType not in ['1', '2', '3', '4']:
				opType = self.userInput("What would you like to sort the books by?\n   1. Title\n   2. Description\n   3. Author\n   4. Price\n ~: ")
			return opType
		else:
			opType = ''
			while opType not in ['1', '2', '3']:
				opType = self.userInput("What would you like to sort the books by?\n   1. Name\n   2. CNP\n   3. Address\n ~: ")
			return opType

	### FILTER ########################################################################################

	### REPORT ########################################################################################

	def report(self):
		os.system('clear')

		reportDict = self._rentalController.getReport()
		s = self.printReport(reportDict)

		if s == '':
			s = 'No results!'

		print s

	def printReport(self, v):
		s = ''
		for obj in v:
			s += str(obj) + " " + str(obj[0]) + "\n"

		return s

	###################################################################################################

	def mainMenu(self):

		#self._bookController.printAll()

		unicornsExist = True
		os.system('clear')
			
		while unicornsExist:

			self.printMenu()
			userInput = self.userInput("Insert a command: ")

			if self.isNotValid(userInput):
				os.system('clear')
				print("Command '%s' not recognized" % userInput)
				continue

			if userInput == "1":
				"""
					Add a book or a customer
				"""
				self.add()
				#self._bookController.printAll()

			elif userInput == "2":
				"""
					Remove a book or a customer
				"""
				self.remove()
				#self._bookController.printAll()	

			elif userInput == "3":
				"""
					Update a book or a customer
				"""
				self.update()
				#self._bookController.printAll()
				
			elif userInput == "4":
				"""
					Search for a book or a customer
				"""
				self.search()
				
			elif userInput == "5":
				"""
					Rent a book or a customer
				"""
				self.rent()
				#self._rentalController.printAll()
				
			elif userInput == "6":
				"""
					Return a book or a customer
				"""
				self.returns()
				#self._rentalController.printAll()
				
			elif userInput == "7":
				"""
					Sort books or customers
				"""
				self.sort()
				
			elif userInput == "8":
				"""
					Filter books or customers
				"""
				#self.filter()
				pass
				
			elif userInput == "9":
				"""
					Report: Number of active customers sorted by year
				"""
				self.report()

			elif userInput == "10":
				unicornsExist = False






