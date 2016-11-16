from book import *
import copy

class bookRepository:
	def __init__(self):
		self._bookRepo = []

	def addBook(self, newBook):
		self._bookRepo.append(book(newBook[0], newBook[1], newBook[2], newBook[3], newBook[4]))

	def removeBook(self, bookId):
		ok = self.checkExistance(bookId)

		if ok == False:
			return "Inexistent ID!"

		i = self.positionOfId(bookId)
		j = len(self._bookRepo) - 1

		self._bookRepo[i], self._bookRepo[j] = self._bookRepo[j], self._bookRepo[i]
		self._bookRepo.pop() 

		return "Removal successful!"

	def positionOfId(self, bookId):
		i = -1
		for obj in self._bookRepo:
			i += 1
			if bookId == obj.returnBookId():
				return i

	def checkExistance(self, bookId):
		for obj in self._bookRepo:
			if bookId == obj.returnBookId():
				return True
		return False

	def update(self, book):
		ok = False
		for obj in self._bookRepo:
			if obj.returnBookId() == book[0]:
				obj.update(book)
				ok = True
		if ok == False:
			return "Inexistent ID!"
		else:
			return "Update successful!"

	def getBook(self, bookTitle):
		for obj in self._bookRepo:
			if obj.returnBookTitle() == bookTitle:
				return str(obj.returnBookId()) + " " + str(obj.returnBookTitle()) + " " + str(obj.returnBookDesc()) + " " + str(obj.returnBookAuthor()) + " " + str(obj.returnBookPrice())
		return "No results!"

	def sortBy(self, opType):
		opType = int(opType)
		bookRepoCopy = copy.deepcopy(self._bookRepo)

		sortedList = self.sort(bookRepoCopy, opType)

		return self.printableSortedList(sortedList)

	def printableSortedList(self, v):
		s = ''
		for obj in v:
			s += str(obj.returnBookId()) + " " + str(obj.returnBookTitle()) + " " + str(obj.returnBookDesc()) + " " + str(obj.returnBookAuthor()) + " " + str(obj.returnBookPrice()) + "\n"
		
		return s

	def sort(self, v, k):
		n = len(v)
		
		for i in range(n):
			for j in range(i+1, n):
				if k == 1:
					if v[i].returnBookTitle() > v[j].returnBookTitle():
						v[i], v[j] = v[j], v[i]
				elif k == 2:
					if v[i].returnBookDesc() > v[j].returnBookDesc():
						v[i], v[j] = v[j], v[i]
				elif k == 3:
					if v[i].returnBookAuthor() > v[j].returnBookAuthor():
						v[i], v[j] = v[j], v[i]
				else:
					if v[i].returnBookPrice() > v[j].returnBookPrice():
						v[i], v[j] = v[j], v[i]

		return v

	def printAll(self):
		for obj in self._bookRepo:
			obj.printObj()








