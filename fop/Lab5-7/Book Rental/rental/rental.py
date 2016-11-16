class rental:
	def __init__(self, customerId, book, date, days):
		self.__customer = customerId 
		self.__book = book # bookId
		self.__date = date # The date it was rented
		self.__days = days # the number of days it has been rented for

	def returnCustomerId(self):
		return self.__customer

	def returnBookId(self):
		return self.__book

	def returnDate(self):
		return self.__date

	def returnDays(self):
		return self.__days

	def returnDateYear(self):
		return self.__date[0:4]

	def printObj(self):
		print(str(self.__customer) + " " + str(self.__book) + " " + str(self.__date) + " " + str(self.__days))
