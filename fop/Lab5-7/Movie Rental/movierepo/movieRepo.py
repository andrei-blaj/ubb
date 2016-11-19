from movie.movie import movie

class movieRepository:

    def __init__(self):
        """
            List of movies
        """
        self._movieList = []

    def add(self, li):
        self._movieList.append(movie(li[0], li[1], li[2], li[3]))

    def remove(self, title):
        v = self._movieList
        i = -1
        j = len(v) - 1
        ok = False

        for obj in v:
            i += 1
            if obj.getTitle() == title:
                ok = True

        if ok == False:
            return "No such book!"

        self._movieList[i], self._movieList[j] == self._movieList[j], self._movieList[i]
        self._movieList.pop()

        return "Removal successful!"

