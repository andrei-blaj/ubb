#include "UI.h"
#include <string>
#include <iterator>
#include <algorithm>
#include "RepositoryException.h"
#include "DogValidator.h"

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Manage dog repository (Administrator mode)." << endl;
	cout << "2 - Manage my dog list (User mode)." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add dog." << endl;
	cout << "\t 2 - Display all." << endl;
	cout << "\t 3 - Update dog." << endl;
	cout << "\t 4 - Delete dog." << endl;
	cout << "\t 5 - Lab Activity:Displaying all dogs sorted ascending by breed" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printMyDogListMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - a. See the dogs in the database, one by one." << endl;
	cout << "\t 2 - b. Choose to adopt the dog." << endl;
	cout << "\t 3 - c. Choose not to adopt the dog and to continue to the next." << endl;
	cout << "\t 4 - d. See all the dogs of a given breed, having an age less than a given number." << endl;
	cout << "\t 5 - e. See the adoption list." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printCase4Menu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - a. See the dogs in the database, one by one." << endl;
	cout << "\t 2 - b. Choose to adopt the dog." << endl;
	cout << "\t 3 - c. Choose not to adopt the dog and to continue to the next." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::addDogToRepo()
{
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the name: ";
	std::string name;
	getline(cin, name);
	int years = 0, months = 0, days = 0;
	cout << "Enter the age: " << endl;
	cout << "\tYears: ";
	cin >> years;
	cin.ignore();
	cout << "\tMonths: ";
	cin >> months;
	cin.ignore();
	cout << "\tDays: ";
	cin >> days;
	cin.ignore();
	cout << "Photo link: ";
	std::string link;
	getline(cin, link);

	/*int res = this->ctrl.addDogToRepository(breed, name, years, months, days, link);
	if (res == 1)
		cout << "Dog successfully added;" << endl;
	else
		cout << "The dog already exists!" << endl;*/

	try
	{
		this->ctrl.addDogToRepository(breed, name, years, months,days, link);
	}
	catch (DogException& e)
	{
		for (auto d : e.getErrors())
			cout << d;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::displayAllDogsRepo()
{
	std::vector<Dog> v = this->ctrl.getRepo().getDogs();

	if (v.size() == 0)
	{
		cout << "There are no dogs in the repository." << endl;
		return;
	}

	for (auto d : v)
	{
		cout << "Breed: " << d.getBreed() << "; Name: " << d.getName() << "; Age: " << d.getAge().getYears() << "years," << d.getAge().getMonths() << "months," << d.getAge().getDays() << "days" << endl;
	}
}

//Lab activity
void UI::displayAllDogsSortedAscendingByBreedUI()
{
	this->ctrl.sortAscendingByBreedCtrl();
	std::vector<Dog> v = ctrl.getRepo().getDogs();
	if (v.size() == 0)
	{
		cout << "There are no dogs in the repository." << endl;
		return;
	}

	for (auto d : v)
	{
		cout << "Breed: " << d.getBreed() << "; Name: " << d.getName() << "; Age: " << d.getAge().getYears() << "years," << d.getAge().getMonths() << "months," << d.getAge().getDays() << "days" << endl;
	}

}

void UI::updateDogToRepo()
{
	cout << "Enter the breed of the dog that you search for: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the name of the dog that you search for: ";
	std::string name;
	getline(cin, name);

	cout << "Enter the new breed of the dog that you want to modify: ";
	std::string newbreed;
	getline(cin, newbreed);
	cout << "Enter the new name of the dog that you want to modify: ";
	std::string newname;
	getline(cin, newname);
	int years = 0, months = 0, days = 0;
	cout << "Enter the new age: " << endl;
	cout << "\tYears: ";
	cin >> years;
	cin.ignore();
	cout << "\tMonths: ";
	cin >> months;
	cin.ignore();
	cout << "\tDays: ";
	cin >> days;
	cin.ignore();
	cout << "New Photo link: ";
	std::string link;
	getline(cin, link);

	int res = this->ctrl.updateDogToRepository(breed, name, newbreed, newname, years, months, days, link);
	if (res != -1)
		cout << "Dog successfully updated;" << endl;
	else
		cout << "Updated failed!" << endl;
}

void UI::deleteDogToRepo()
{
	cout << "Enter the breed for the dog that you want to delete: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the name for the dog that you want to delete: ";
	std::string name;
	getline(cin, name);

	int res = this->ctrl.deleteDogToRepository(breed, name);
	if (res != -1)
		cout << "Dog successfully deleted;" << endl;
	else
		cout << "Something was wrong, it maight that the dog that you entered doesn't exist!" << endl;
}

///Manage the AdoptionList(User Mode)
/*void UI::showListAdoptedDogs()
{
	std::vector<Dog> DogsAdoptedList = this->ctrl.getAdoptionList().getAdoptedDogs();
	if (DogsAdoptedList.size() == 0)
	{
		cout << "There are no adopted dogs already" << endl;
		return;
	}
	for (auto d : DogsAdoptedList)
	{
		cout << "Breed: " << d.getBreed() << "; Name: " << d.getName() << "; Age: " << d.getAge().getYears() << "years," << d.getAge().getMonths() << " months," << d.getAge().getDays() << " days" << endl;
	}
}*/

void UI::displayAdoptionlistToFile()
{
	std::string filename;
	cout << "Input the file name (absolute path): ";
	getline(cin, filename);

	try
	{
		this->ctrl.saveAdoptionlist(filename);

		if (this->ctrl.getAdoptionList() == nullptr)
		{
			cout << "AdoptionList cannot be displayed!" << endl;
			return;
		}
		else
			this->ctrl.openAdoptionlist();
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addDogToRepo();
					break;
				case 2:
					this->displayAllDogsRepo();
					break;
				case 3:
					this->updateDogToRepo();
					break;
				case 4:
					this->deleteDogToRepo();
					break;
				case 5:
					this->displayAllDogsSortedAscendingByBreedUI();
				}
			}
		}

		///Manage AdoptionList(user mode)
		if (command == 2)
		{
			while (true)
			{
				UI::printMyDogListMenu();
				int commandAdoptionList{ 0 };
				cout << "Input the command: ";
				cin >> commandAdoptionList;
				cin.ignore();
				if (commandAdoptionList == 0)
					break;
				switch (commandAdoptionList)
				{
				case 1:
				{
					std::vector<Dog> v = this->ctrl.getRepo().getDogs();
					this->ctrl.showFirstDog(v);
					Dog d = this->ctrl.getCurrentDog(v);
					cout << "Now showing: " << d.getBreed() << " ; " << d.getName() << ";" << d.getAge().getYears() << "years, " << d.getAge().getMonths() << "months, " << d.getAge().getDays() << "days." << endl;
					break;
				}
				case 2:
				{
					std::vector<Dog> v = this->ctrl.getRepo().getDogs();
					Dog d = this->ctrl.getCurrentDog(v);
					this->ctrl.addDogToAdoptionList(d);
					break;
				}
				case 3:
				{
					std::vector<Dog> v = this->ctrl.getRepo().getDogs();
					this->ctrl.nextDog(v);
					Dog d = this->ctrl.getCurrentDog(v);
					cout << "Now showing: " << d.getBreed() << " - " << d.getName() << ";" << d.getAge().getYears() << "years, " << d.getAge().getMonths() << "months, " << d.getAge().getDays() << "days." << endl;
					break;
				}
				case 4:
				{
					cout << "Enter the breed for the dog that you search for:";
					std::string breed;
					getline(cin, breed);
					cout << "Enter an age (Years):";
					int years;
					cin >> years;

					if (breed != "")
					{
						while (true)
						{
							UI::printCase4Menu();
							int command{ 0 };
							cout << "Give a command:";
							cin >> command;
							if (command == 0)
								break;
							if (command == 1)
							{
								std::vector<Dog> v = this->ctrl.filterByBreedAndAge(breed, years);
								this->ctrl.showFirstDog(v);
								Dog d = this->ctrl.getCurrentDog(v);
								cout << "Now showing: " << d.getBreed() << " ; " << d.getName() << d.getAge().getYears() << "years," << d.getAge().getMonths() << "months, " << d.getAge().getDays() << "days." << endl;
							}
							if (command == 2)
							{
								std::vector<Dog> v = this->ctrl.filterByBreedAndAge(breed, years);
								Dog d = this->ctrl.getCurrentDog(v);
								this->ctrl.addDogToAdoptionList(d);
							}
							if (command == 3)
							{
								std::vector<Dog> v = this->ctrl.filterByBreedAndAge(breed, years);
								this->ctrl.nextDog(v);
								Dog d = this->ctrl.getCurrentDog(v);
								cout << "Now showing: " << d.getBreed() << " - " << d.getName() << d.getAge().getYears() << "years," << d.getAge().getMonths() << "months, " << d.getAge().getDays() << "days." << endl;
							}
						}
					}
					else
					{
						while (true)
						{
							UI::printCase4Menu();
							int command{ 0 };
							cout << "Give a command:";
							cin >> command;
							if (command == 0)
								break;
							if (command == 1)
							{
								std::vector<Dog> v = this->ctrl.getRepo().getDogs();
								this->ctrl.showFirstDog(v);
								Dog d = this->ctrl.getCurrentDog(v);
								cout << "Now showing: " << d.getBreed() << " ; " << d.getName() << d.getAge().getYears() << "years," << d.getAge().getMonths() << "months, " << d.getAge().getDays() << "days." << endl;
							}
							if (command == 2)
							{
								std::vector<Dog> v = this->ctrl.getRepo().getDogs();
								Dog d = this->ctrl.getCurrentDog(v);
								this->ctrl.addDogToAdoptionList(d);
							}
							if (command == 3)
							{
								std::vector<Dog> v = this->ctrl.getRepo().getDogs();
								this->ctrl.nextDog(v);
								Dog d = this->ctrl.getCurrentDog(v);
								cout << "Now showing: " << d.getBreed() << " - " << d.getName() << d.getAge().getYears() << "years," << d.getAge().getMonths() << "months, " << d.getAge().getDays() << "days." << endl;
							}
						}
					}
					break;
				}
				case 5:
					//this->showListAdoptedDogs();
					this->displayAdoptionlistToFile();
				}
			}
		}
	}
}
