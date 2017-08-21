from rental.rental import *
import copy

class rentalRepository:
	def __init__(self):
		self._rentalRepo = []

	def add(self, rentData):
		self._rentalRepo.append(rental(rentData[0], rentData[1], rentData[2], rentData[3]))

	def returns(self, bookId):
		i = -1
		j = len(self._rentalRepo) - 1
		ok = False

		for obj in self._rentalRepo:
			i += 1
			if obj.returnBookId() == bookId:
				ok = True
				break

		if ok == True:
			self._rentalRepo[i], self._rentalRepo[j] = self._rentalRepo[j], self._rentalRepo[i]
			self._rentalRepo.pop()
			print "Return successful!"
		else:
			print "No results!"

	def getReport(self):
		v = copy.deepcopy(self._rentalRepo)
		reportDict = {}

		for obj in v:
			year = obj.returnDateYear()
			if year in reportDict:
				reportDict[year] += 1
			else:
				reportDict[year] = 1

		return reportDict

	def printAll(self):
		for obj in self._rentalRepo:
			obj.printObj()

	def getCustomerReport(self):
		l = []
		for obj in self._rentalRepo:
			l.append(obj.returnCustomerId())
		
		return l

	def getBookReport(self):
		l = []
		for obj in self._rentalRepo:
			l.append(obj.returnBookId)

		return l
