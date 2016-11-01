import cmd
import files

#TESTS#####################################################################################################

def test_getCategoryAndValueFromFile():
    '''
        This function is mainly used for extracting the category and value from a line in a file and returning them
        The function also checks if all the data is valid such as if the category extracted from the file is in fact a
        valid category or it the value is actually a number.
    '''
    assert files.getCategoryAndValueFromFile("food 10", cmd.buildCategList(), 1) == ("food", 10, 1)
    assert files.getCategoryAndValueFromFile("foodd 10", cmd.buildCategList(), 1) == ("foodd", 10, 0)
    assert files.getCategoryAndValueFromFile("food 10a", cmd.buildCategList(), 1) == ("food", "10a", 0)

def test_getCommand(): # This function returns the COMMAND (add, insert, ...) inserted by the user.
    assert cmd.getCommand("add asdf ") == "add"
    assert cmd.getCommand("insert fd a dfa ") == "insert"
    assert cmd.getCommand("remove asdf as12 123 ") == "remove"

def test_passSpaces():
    assert cmd.passSpaces("  asd", 0, 5) == 2
    assert cmd.passSpaces("   sd", 0, 5) == 3
    assert cmd.passSpaces(" dasd", 0, 5) == 1

def test_getText():
    assert cmd.getText("and ", 0, 4) == (3, "and")

def test_getCategAndValue():
    assert cmd.getCategAndValue("add 10 food asdf") == ("food", "10", "asdf")
    assert cmd.getCategAndValue("add 10 others as") == ("others", "10", "as")
    assert cmd.getCategAndValue("add 10 transport") == ("transport", "10", "")

def test_getDayCategAndValue():
    assert cmd.getDayCategAndValue("insert 26 10 food asd") == ("26", "food", "10", "asd")
    assert cmd.getDayCategAndValue("insert 27 10 others") == ("27", "others", "10", "")
    assert cmd.getDayCategAndValue("insert 28 10 internet a") == ("28", "internet", "10", "a")

def test_getRemainder():
    assert cmd.getRemainder("food asdf fd fdsasss") == "asdf fd fdsasss"
    assert cmd.getRemainder("internet sasss") == "sasss"
    assert cmd.getRemainder("food as d f ds a d fa") == "as d f ds a d fa"

def test_passText():
    assert cmd.passText("add ", 0, 4) == 3
    assert cmd.passText("asdf as", 0, 7) == 4
    assert cmd.passText("as a", 0, 4) == 2

def test_removeTo():
    assert cmd.removeTo("10 to 15 asd") == ("10", "15", "asd")
    assert cmd.removeTo("10 to 15") == ("10", "15", "")
    assert cmd.removeTo("1 to 15 a") == ("1", "15", "a")

def test_removeDayOrCateg():
    assert cmd.removeDayOrCateg("transport asdf asd fd") == ("transport", "asdf asd fd")
    assert cmd.removeDayOrCateg("internet a") == ("internet", "a")
    assert cmd.removeDayOrCateg("food ") == ("food", "")

def test_getExpensesForDay():
    assert cmd.getExpensesForDay({"a" : 5, "b" : 4}) == 9
    assert cmd.getExpensesForDay({"a" : 1, "b" : 2}) == 3
    assert cmd.getExpensesForDay({"a" : 3, "b" : 3}) == 6

def test_updateMax():
    assert cmd.updateMax(5, 7, 1, 2) == (7, 1)
    assert cmd.updateMax(3, 3, 1, 2) == (3, 2)
    assert cmd.updateMax(7, 5, 1, 2) == (7, 2)

def test_getSumForDay():
    assert cmd.getSumForDay({"a" : 5, "b" : 4}) == 9
    assert cmd.getSumForDay({"a" : 1, "b" : 2}) == 3
    assert cmd.getSumForDay({"a" : 3, "b" : 3}) == 6

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
