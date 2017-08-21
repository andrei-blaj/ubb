from operations import *

def testCheckCommand():
    assert checkCommand('add') == True
    assert checkCommand('ad') == False
    assert checkCommand('delay') == True
    assert checkCommand('del') == False

def test_checkCode():
    assert checkCode([[1, 2, 3], [3, 4, 5], [5, 6, 7]], 4) == True
    assert checkCode([[1, 2, 3], [3, 4, 5], [5, 6, 7]], 1) == False
    assert checkCode([[1, 2, 3], [3, 4, 5], [5, 6, 7]], 6) == True

def test_checkDuration():
    assert checkDuration(10) == False
    assert checkDuration(15) == False
    assert checkDuration(21) == True

def test_checkLen():
    assert checkLen("12") == True
    assert checkLen("1") == True
    assert checkLen("adsd") == False
    assert checkLen("a") == True

#def test_buildForPrint():
#    assert buildForPrint([["1", "2", "3"], ["2", "2", "3"]]) == "1 2 3\n2 2 3\n"

def testAll():
    testCheckCommand()
    test_checkCode()
    #test_checkLen()
    test_checkDuration()
