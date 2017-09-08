//
//  tests.cpp
//  ADTSortedBagBST
//
//  Created by Andrei-Sorin Blaj on 12/06/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "tests.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void Tests::testSearch() {
    SortedBag BST;
    
    BST.Insert(5);
    BST.Insert(10);
    BST.Insert(3);
    BST.Insert(4);
    BST.Insert(1);
    BST.Insert(11);
    //cout << BST.count() << "\n";
    
    assert(BST.Search(5) == 0);
    assert(BST.Search(4) == 0);
    assert(BST.Search(2) == -1);
    assert(BST.Search(1) == 0);
    assert(BST.Search(12) == -1);
    
    BST.Destroy();
    
}

void Tests::testRemove() {
    
    SortedBag BST;
    
    BST.Insert(5);
    BST.Insert(10);
    BST.Insert(3);
    BST.Insert(4);
    BST.Insert(1);
    BST.Insert(11);
    //cout << BST.count() << "\n";

    assert(BST.Delete(5) == 0);
    assert(BST.Delete(123) == -1);
    assert(BST.Delete(12) == -1);
    assert(BST.Delete(1) == 0);
    assert(BST.Delete(11) == 0);
    
    BST.Destroy();
    
}

void Tests::testNumberOfElements() {
    
    SortedBag BST;
    
    BST.Insert(5);
    BST.Insert(10);
    BST.Insert(3);
    BST.Insert(4);
    BST.Insert(1);
    BST.Insert(11);
    
    assert(BST.count() == 6);
    
    assert(BST.Delete(5) == 0);
    //cout << BST.count() << "\n";
    
    assert(BST.count() == 5);
    
    assert(BST.Delete(10) == 0);
    assert(BST.Delete(3) == 0);
    assert(BST.Delete(4) == 0);
    
    assert(BST.count() == 2);
    
    BST.Destroy();
    
}

void Tests::testIsEmpty() {
    
    SortedBag BST;
    
    BST.Insert(5);
    BST.Insert(10);
    BST.Insert(3);
    BST.Insert(4);
    BST.Insert(1);
    BST.Insert(11);
    
    assert(BST.isEmpty() == 0);
    
    assert(BST.Delete(10) == 0);
    assert(BST.Delete(3) == 0);
    assert(BST.Delete(4) == 0);
    
    assert(BST.isEmpty() == 0);
    
    assert(BST.Delete(1) == 0);
    assert(BST.Delete(5) == 0);
    assert(BST.Delete(11) == 0);
    
    assert(BST.isEmpty() == 1);
    
    BST.Destroy();

}

void Tests::testAll() {
    testSearch();
    testRemove();
    testNumberOfElements();
    testIsEmpty();
}

