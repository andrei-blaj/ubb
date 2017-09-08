class RedoController:

    def __init__(self, repo):
        self.repo = repo

    def redo(self):
        self.repo.redo()
