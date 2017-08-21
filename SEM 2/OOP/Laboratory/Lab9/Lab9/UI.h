#pragma once
#include "Controller.h"
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
	void UI::displayAllDogsSortedAscendingByBreedUI();
	void UI::updateDogToRepo();
	void UI::deleteDogToRepo();
	//void UI::showListAdoptedDogs();
	void UI::displayAdoptionlistToFile();



};


