//
//  main.c
//  Lab3-4
//
//  Created by Tudor Frent on 08/03/17.
//  Copyright © 2017 Tudor Frent. All rights reserved.
//


#include "repository.h"
#include "UI.h"

int main()
{
    //testEstateRepo();
    
    EstateRepo repo = createRepo();
    Controller ctrl = createController(&repo);
    
   
    addEstate(&ctrl, "house", "Becas", 350, 500000);
    addEstate(&ctrl, "apartment", "Manastur", 100, 95000);
    addEstate(&ctrl, "house", "Campului", 230, 300000);
    addEstate(&ctrl, "penthouse", "Tudor Mihaly", 140, 200000);
    addEstate(&ctrl, "apartment", "Traian Mosoiu",75,90000);
    addEstate(&ctrl, "penthouse", "Iris",150,200000);
    addEstate(&ctrl, "house", "Centru",200,850000);
    addEstate(&ctrl, "apartment", "Zorilor",85,95000);
    addEstate(&ctrl, "house", "Buna Ziua",300,600000);
    
    
    
    
    UI ui = createUI(&ctrl);
    
    startUI(&ui);
    
    
    return 0;
}
