from main import *

#TESTS#####################################################################################################

def test_getCategoryAndValueFromFile():
    '''
        This function is mainly used for extracting the category and value from a line in a file and returning them
        The function also checks if all the data is valid such as if the category extracted from the file is in fact a
        valid category or it the value is actually a number.
    '''
    assert getCategoryAndValueFromFile("food 10", buildCategList(), 1) == ("food", 10, 1)
    assert getCategoryAndValueFromFile("foodd 10", buildCategList(), 1) == ("foodd", 10, 0)
    assert getCategoryAndValueFromFile("food 10a", buildCategList(), 1) == ("food", "10a", 0)

def test_getCommand(): # This function returns the COMMAND (add, insert, ...) inserted by the user.
    assert getCommand("add asdf ") == "add"
    assert getCommand("insert fd a dfa ") == "insert"
    assert getCommand("remove asdf as12 123 ") == "remove"

def test_passSpaces():
    assert passSpaces("  asd", 0, 5) == 2
    assert passSpaces("   sd", 0, 5) == 3
    assert passSpaces(" dasd", 0, 5) == 1

def test_getText():
    assert getText("and ", 0, 4) == (3, "and")

def test_getCategAndValue():
    assert getCategAndValue("add 10 food asdf") == ("food", "10", "asdf")
    assert getCategAndValue("add 10 others as") == ("others", "10", "as")
    assert getCategAndValue("add 10 transport") == ("transport", "10", "")

def test_getDayCategAndValue():
    assert getDayCategAndValue("insert 26 10 food asd") == ("26", "food", "10", "asd")
    assert getDayCategAndValue("insert 27 10 others") == ("27", "others", "10", "")
    assert getDayCategAndValue("insert 28 10 internet a") == ("28", "internet", "10", "a")

def test_getRemainder():
    assert getRemainder("food asdf fd fdsasss") == "asdf fd fdsasss"
    assert getRemainder("internet sasss") == "sasss"
    assert getRemainder("food as d f ds a d fa") == "as d f ds a d fa"

def test_passText():
    assert passText("add ", 0, 4) == 3
    assert passText("asdf as", 0, 7) == 4
    assert passText("as a", 0, 4) == 2

def test_removeTo():
    assert removeTo("10 to 15 asd") == ("10", "15", "asd")
    assert removeTo("10 to 15") == ("10", "15", "")
    assert removeTo("1 to 15 a") == ("1", "15", "a")

def test_removeDayOrCateg():
    assert removeDayOrCateg("transport asdf asd fd") == ("transport", "asdf asd fd")
    assert removeDayOrCateg("internet a") == ("internet", "a")
    assert removeDayOrCateg("food ") == ("food", "")

def test_getExpensesForDay():
    assert getExpensesForDay({"a" : 5, "b" : 4}) == 9
    assert getExpensesForDay({"a" : 1, "b" : 2}) == 3
    assert getExpensesForDay({"a" : 3, "b" : 3}) == 6

def test_updateMax():
    assert updateMax(5, 7, 1, 2) == (7, 1)
    assert updateMax(3, 3, 1, 2) == (3, 2)
    assert updateMax(7, 5, 1, 2) == (7, 2)

def test_getSumForDay():
    assert getSumForDay({"a" : 5, "b" : 4}) == 9
    assert getSumForDay({"a" : 1, "b" : 2}) == 3
    assert getSumForDay({"a" : 3, "b" : 3}) == 6

def testEverything():

    assertionError = None

    try:
        test_getSumForDay()
    except:
        print("<getSumForDay> failed some tests.")
        assertionError = True

    try:
        test_updateMax()
    except:
        print("<updateMax> failed some tests.")
        assertionError = True

    try:
        test_getExpensesForDay()
    except:
        print("<getExpensesForDay> failed some tests.")
        assertionError = True

    try:
        test_removeDayOrCateg()
    except:
        print("<removeDayOrCateg> failed some tests.")
        assertionError = True

    try:
        test_removeTo()
    except:
        print("<removeTo> failed some tests.")
        assertionError = True

    try:
        test_passText()
    except:
        print("<passText> failed some tests.")
        assertionError = True

    try:
        test_getRemainder()
    except:
        print("<getRemainder> failed some tests.")
        assertionError = True

    try:
        test_getDayCategAndValue()
    except:
        print("<getDayCategAndValue> failed some tests.")
        assertionError = True

    try:
        test_getCategAndValue()
    except:
        print("<getCategAndValue> failed some tests.")
        assertionError = True

    try:
        test_getText()
    except:
        print("<getText> failed some tests.")
        assertionError = True

    try:
        test_getCategoryAndValueFromFile()
    except:
        print("<getCategoryAndValueFromFile> failed some tests.")
        assertionError = True

    try:
        test_getCommand()
    except:
        print("<getCommand> failed some tests.")
        assertionError = True

    try:
        test_passSpaces()
    except:
        print("<passSpaces> failed some tests.")
        assertionError = True

    if assertionError is not None:
        raise(Exception("Some tests failed!"))
