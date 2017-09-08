//
//  Repository.h
//  Real Estate Agency
//
//  Created by Andrei-Sorin Blaj on 25/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Repository_h
#define Repository_h

#include <stdio.h>
#include <stdlib.h>

#include "../model/DynamicArray.h"

typedef struct {
    DynamicArray* estates; //estates is a dynamic array with elems=estates of diff types such as houses, appartments, villas, penthouses
} EstateRepository;
/*
 This function creates a repository by allocating it memory.
 */
EstateRepository* create_allocate_repository();
/*
 destroy_repository desrroys a repository by deallocating the memory already allocated
 */
void destroy_repository(EstateRepository* repo);


/*
 
 */
int add_repository(EstateRepository* repo, TElement t);
int get_repo_length(EstateRepository* repo);

Estate* delete_repository(EstateRepository* repo, char* address);
Estate* update_repository(EstateRepository* repo, TElement t);
#endif /* Repository_h */
