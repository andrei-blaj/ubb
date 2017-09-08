//
//  main.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 17/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "UI.hpp"
//#include "Tests.h"
#include "RepositoryException.hpp"
#include "CSVAdoptionList.hpp"
#include "HTMLAdoptionList.hpp"

using namespace std;

int main()
{
    //Tests::testAll();
    try
    {
        printf("Give the type of the AdoptionList file: CSV or HTML\n");
        printf("> ");
        std::string type;
        cin >> type;
        if (type == "CSV")
        {
            Repository repo("load.txt");
            FileAdoptionList* a = new CSVAdoptionList{};
            
            Controller ctrl(repo, a, DogValidator{});
            UI ui(ctrl);
            ui.run();
            delete a;
        }
        else
        {
            Repository repo("load.txt");
            FileAdoptionList* a = new HTMLAdoptionList{};
            
            Controller ctrl(repo, a, DogValidator{});
            UI ui(ctrl);
            ui.run();
            delete a;
        }
    }
    catch (FileException& e)
    {
        cout << "Repository file could not be opened! The application will terminate!" << endl;
        return 1;
    }
    
    return 0;
}
