class book:
	def __init__(self, iD, titlu, descriere, autor, pret):
		self.__id = iD
		self.__titlu = titlu
		self.__descriere = descriere
		self.__autor = autor
		self.__pret = pret

	def returnBookId(self):
		return self.__id

	def returnBookTitle(self):
		return self.__titlu

	def returnBookDesc(self):
		return self.__descriere

	def returnBookAuthor(self):
		return self.__autor

	def returnBookPrice(self):
		return self.__pret

	def update(self, newBook):
		self.__titlu = newBook[1]
		self.__descriere = newBook[2]
		self.__autor = newBook[3]
		self.__pret = newBook[4]

	def printObj(self):
		print(str(self.__id) + " " + str(self.__titlu) + " " + str(self.__descriere) + " " + str(self.__autor) + " " + str(self.__pret))
