//
//  Iterator.hpp
//  ADTSortedBagBST
//
//  Created by Andrei-Sorin Blaj on 12/06/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//
#pragma once
#ifndef Iterator_hpp
#define Iterator_hpp

#include <iostream>
#include "bst.hpp"

class IteratorBST{
    Node* root = NULL;
    bool goDeeper(Node* here){
        if(here == NULL){
            return false;
        }
        if(!goDeeper(here->left)){
            root = here;
        }
        return true;
    }
public:
    IteratorBST(Node* root):root{root}{};
    bool isValid();
    int getValue();
    void next();
};

#endif /* Iterator_hpp */
