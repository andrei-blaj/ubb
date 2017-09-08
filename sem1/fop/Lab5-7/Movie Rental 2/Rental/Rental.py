class rental:

    def __init__(self, id, mid, cid, rentalDate, dueDate, returnDate):
        self.__id = id
        self.__mid = mid # Movie ID
        self.__cid = cid # Client ID
        self.__rentalDate = rentalDate # date obj aka date(y, m, d)
        self.__dueDate = dueDate # date obj aka date(y, m, d)
        self.__returnDate = returnDate # date obj aka date(y, m, d)

    def get_id(self):
        return self.__id

    def get_mid(self):
        return self.__mid

    def get_cid(self):
        return self.__cid

    def get_rentalDate(self):
        return self.__rentalDate

    def get_dueDate(self):
        return self.__dueDate

    def get_returnDate(self):
        return self.__returnDate

    def set_returnDate(self, return_date):
        self.__returnDate = return_date