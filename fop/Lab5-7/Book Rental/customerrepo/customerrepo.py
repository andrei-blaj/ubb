from customer.customer import *

class customerRepository:
	def __init__(self):
		self._customerRepo = []

	def addCustomer(self, newCustomer):
		self._customerRepo.append(customer(newCustomer[0], newCustomer[1], newCustomer[2], newCustomer[3]))

	def removeCustomer(self, customerId):
		ok = self.checkExistance(customerId)

		if ok == False:
			return "Inexistent ID!"

		i = self.positionOfId(customerId)
		j = len(self._customerRepo) - 1

		self._customerRepo[i], self._customerRepo[j] = self._customerRepo[j], self._customerRepo[i]
		self._customerRepo.pop()

		return "Removal successful!"

	def positionOfId(self, customerId):
		i = -1
		for obj in self._customerRepo:
			i += 1
			if customerId == obj.returnCustomerId():
				return i

	def checkExistance(self, customerId):
		for obj in self._customerRepo:
			if customerId == obj.returnCustomerId():
				return True
		return False

	def update(self, customer):
		ok = False
		for obj in self._customerRepo:
			if obj.returnCustomerId() == customer[0]:
				obj.update(customer)
				ok = True
		if ok == False:
			return "Inexistent ID!"
		else:
			return "Update successful!"

	def getCustomer(self, customerName):
		for obj in self._customerRepo:
			if obj.returnCustomerName() == customerName:
				return str(obj.returnCustomerId()) + " " + str(obj.returnCustomerName()) + " " + str(obj.returnCustomerCnp()) + " " + str(obj.returnCustomerAdd())
		return "No results!"

	def sortBy(self, opType):
		opType = int(opType)
		customerRepoCopy = copy.deepcopy(self._customerRepo)

		sortedList = self.sort(customerRepoCopy, opType)

		return self.printableSortedList(sortedList)

	def printableSortedList(self, v):
		s = ''
		for obj in v:
			s += str(obj.returnCustomerId()) + " " + str(obj.returnCustomerName()) + " " + str(obj.returnCustomerCnp()) + " " + str(obj.returnCustomerAdd())  + "\n"
		
		return s

	def sort(self, v, k):
		n = len(v)
		
		for i in range(n):
			for j in range(i+1, n):
				if k == 1:
					if v[i].returnCustomerName() > v[j].returnCustomerName():
						v[i], v[j] = v[j], v[i]
				elif k == 2:
					if v[i].returnCustomerCnp() > v[j].returnCustomerCnp():
						v[i], v[j] = v[j], v[i]
				else:
					if v[i].returnCustomerAdd() > v[j].returnCustomerAdd():
						v[i], v[j] = v[j], v[i]

		return v


	def printAll(self):
		for obj in self._customerRepo:
			obj.printObj()

	def printCustomer(self, iD):
		for obj in self._customerRepo:
			if obj.returnCustomerId == iD:
				obj.printObj()


