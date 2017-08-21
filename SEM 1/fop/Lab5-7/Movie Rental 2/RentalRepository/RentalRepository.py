import datetime
from datetime import date

class RentalRepository:

    def __init__(self):
        self.__data = []

    def add(self, new_rental):
        self.__data.append(new_rental)

    def remove(self, id):
        i = 0
        for rental in self.__data:
            if rental.get_id() == id:
                break
            i += 1
        self.__data.pop(i)

    def checkAvailability(self, movie_id):
        index = self._findMovie(movie_id)
        if index == -1 or self.__data[index].get_returnDate() is not None:
            return True

        return False

    def checkExistance(self, movie_id):
        index = self._findMovie(movie_id)
        if index == -1:
            return False
        return True

    def checkClientPermissions(self, client_id):
        for r in self.__data:
            id = r.get_cid()
            returnDate = r.get_returnDate()
            if id == client_id and returnDate is None:
                due_date = r.get_dueDate()
                todaysDate = self.todaysDate()
                if due_date < todaysDate:
                    return False

        return True

    def _findMovie(self, id):
        for i in range(0, len(self.__data)):
            if self.__data[i].get_mid() == id:
                return i
        return -1

    def _findClient(self, id):
        for i in range(0, len(self.__data)):
            if self.__data[i].get_cid() == id:
                return i
        return -1

    def updateReturnDate(self, movie_id):
        index = self._findMovie(movie_id)
        return_date = datetime.datetime.today()
        self.__data[index].set_returnDate(return_date)

    def mostRented(self):
        mostRentedDict = []
        mostRentedByNumberOfDays = []

        for r in self.__data:
            mid = r.get_mid()

            d1 = r.get_rentalDate()
            d2 = r.get_returnDate()

            if d2 is None:
                d2 = self.todaysDate()

            delta = d1 - d2
            number_of_days = delta.days

            ok = True

            for l in mostRentedDict:
                if l[0] == mid:
                    l[1] += number_of_days
                    ok = False

            if ok:
                mostRentedDict.append([mid, number_of_days])

            ok = True

            for l in mostRentedByNumberOfDays:
                if l[0] == mid:
                    l[1] += number_of_days
                    ok = False

            if ok:
                mostRentedByNumberOfDays.append([mid, number_of_days])

        for i in range(0, len(mostRentedDict) - 1):
            for j in range(i + 1, len(mostRentedDict) - 1):
                a = mostRentedDict[i][1]
                b = mostRentedDict[j][1]
                if a < b:
                    mostRentedDict[i], mostRentedDict[j] = mostRentedDict[j], mostRentedDict[i]

        for i in range(0, len(mostRentedByNumberOfDays) - 1):
            for j in range(i + 1, len(mostRentedByNumberOfDays) - 1):
                a = mostRentedByNumberOfDays[i][1]
                b = mostRentedByNumberOfDays[j][1]
                if a < b:
                    mostRentedByNumberOfDays[i], mostRentedByNumberOfDays[j] = mostRentedByNumberOfDays[j], mostRentedByNumberOfDays[i]

        return mostRentedDict, mostRentedByNumberOfDays

    def todaysDate(self):
        today = datetime.datetime.now()

        year = today.year
        month = today.month
        day = today.day

        return date(year, month, day)

    def getSortedClients(self):
        sorted_clients = []

        for rental in self.__data:
            client_id = rental.get_cid()
            rental_date = rental.get_rentalDate()
            return_date = rental.get_returnDate()

            if return_date is None:
                return_date = self.todaysDate()

            delta = rental_date - return_date
            number_of_days = delta.days

            ok = True

            for l in sorted_clients:
                if l[0] == client_id:
                    l[1] += number_of_days
                    ok = False

            if ok:
                sorted_clients.append([client_id, number_of_days])

        for i in range(0, len(sorted_clients)):
            for j in range(i + 1, len(sorted_clients)):
                if sorted_clients[i][1] > sorted_clients[j][1]:
                    sorted_clients[i], sorted_clients[j] = sorted_clients[j], sorted_clients[i]

        return sorted_clients

    def getRentals(self):
        movie_list = []
        for rental in self.__data:
            movie_id = rental.get_mid()
            return_date = rental.get_returnDate()

            if return_date is None:
                movie_list.append(movie_id)

        return movie_list

    def getLateRentals(self):
        late_rentals = []

        for rental in self.__data:
            id = rental.get_id()
            due_date = rental.get_dueDate()
            return_date = rental.get_returnDate()

            todaysDate = self.todaysDate()

            if return_date is None and due_date < todaysDate:
                number_of_days = due_date - todaysDate

                ok = True

                for l in late_rentals:
                    if l[0] == id:
                        l[1] += number_of_days
                        ok = False

                if ok:
                    late_rentals.append([id, number_of_days])

        for i in range(0, len(late_rentals)):
            for j in range(i + 1, len(late_rentals)):
                if late_rentals[i][1] > late_rentals[j][1]:
                    late_rentals[i], late_rentals[j] = late_rentals[j], late_rentals[i]

        return late_rentals

    def getRentalInformation(self, id):
        s = ''
        for rental in self.__data:
            if rental.get_id() == id:
                movie_id = rental.get_mid()
                client_id = rental.get_cid()
                rental_date = rental.get_rentalDate()
                due_date = rental.get_dueDate()

                s += str(id) + ' ' + str(movie_id) + ' ' + str(client_id) + ' ' + str(rental_date) + ' ' + str(due_date)

        return s




















