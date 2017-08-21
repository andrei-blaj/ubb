from models.number import *
from utils.random import *
from ui.console import Console


def main():
    """
    The main method of the application.
    It instantiates a console and runs it.
    """
    app = Console()
    app.run()

if __name__ == '__main__':
    main()
