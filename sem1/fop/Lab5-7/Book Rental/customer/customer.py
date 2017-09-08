class customer:
	def __init__(self, iD, name, cnp, address):
		self.__id = iD
		self.__name = name
		self.__cnp = cnp
		self.__address = address

	def returnCustomerId(self):
		return self.__id

	def returnCustomerName(self):
		return self.__name

	def returnCustomerCnp(self):
		return self.__cnp

	def returnCustomerAdd(self):
		return self.__address

	def update(self, newCustomer):
		self.__name = newCustomer[1]
		self.__cnp = newCustomer[2]
		self.__address = newCustomer[3]

	def printObj(self):
		print (str(self.__id) + " " + str(self.__name) + " " + str(self.__cnp) + " " + str(self.__address))
