class driver:

    def __init__(self, id, distance):
        self.__id = id
        self.__distance = distance

    def getId(self):
        '''
            This method the id attribute
        '''
        return self.__id

    def getDistance(self):
        '''
            This method returns the distance attribute
        '''
        return self.__distance

    def setDistance(self, new_distance):
        '''
            This method sets the distance attribute to a given distance
        '''
        self.__distance = new_distance
