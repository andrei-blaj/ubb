//
//  Iterator.cpp
//  ADTSortedBagBST
//
//  Created by Andrei-Sorin Blaj on 12/06/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "IteratorBST.hpp"

bool IteratorBST::isValid(){
    return root != NULL;
}

int IteratorBST::getValue(){
    return root->data;
}

void IteratorBST::next(){
    if(!goDeeper(root->left)){
        if(!goDeeper(root->right)){
            root = root->parent;
        }
    }
}
