class movie:

    def __init__(self, movieId, title, description, genre):
        """
            If the movie is available for rent, the rented variable has the value "False"
        """
        self.__movieId = movieId
        self.__title = title
        self.__description = description
        self.__genre = genre

    def getMovieId(self):
        return self.__movieId

    def getTitle(self):
        return self.__title

    def getDescription(self):
        return self.__description

    def getGenre(self):
        return self.__genre

def testMovie():

    a = movie('1', '1', '1', '1')
    b = movie('1', '1', '1', '1')
    c = movie('1', '1', '1', '1')
    d = movie('1', '1', '1', '1')

    assert a.getMovieId() == '1'
    assert b.getMovieId() == '1'
    assert c.getMovieId() == '1'
    assert d.getMovieId() == '1'

    assert a.getTitle() == '1'
    assert b.getTitle() == '1'
    assert c.getTitle() == '1'
    assert d.getTitle() == '1'

    assert a.getDescription() == '1'
    assert b.getDescription() == '1'
    assert c.getDescription() == '1'
    assert d.getDescription() == '1'

    assert a.getGenre() == '1'
    assert b.getGenre() == '1'
    assert c.getGenre() == '1'
    assert d.getGenre() == '1'
    
    