#pragma once
#include "Controller.hpp"
//#include <vector>

class UI
{
private:
    Controller ctrl;
    
public:
    UI(const Controller& c) : ctrl(c) {}
    
    void run();
    
private:
    static void printMenu();
    static void printRepositoryMenu();
    static void printMyDogListMenu();
    static void printCase4Menu();
    
    void addDogToRepo();
    void displayAllDogsRepo();
    //modif
    void displayAllDogsSortedAscendingByBreedUI();
    void updateDogToRepo();
    void deleteDogToRepo();
    //void UI::showListAdoptedDogs();
    void displayAdoptionlistToFile();
    
    
    
};


