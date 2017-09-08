#include "UI.h"
#include <Windows.h>
//#include "Tests.h"
#include "RepositoryException.h"
#include "CSVAdoptionList.h"
#include "HTMLAdoptionList.h"

using namespace std;

int main()
{
	//Tests::testAll();
	system("color f4");
	try
	{
		printf("Give the type of the AdoptionList file: CSV or HTML");
		std::string type;
		cin >> type;
		if (type == "CSV")
		{
			Repository repo("dogs.txt");
			FileAdoptionList* a = new CSVAdoptionList{};

			Controller ctrl(repo, a, DogValidator{});
			UI ui(ctrl);
			ui.run();
			delete a;
		}
		else
		{
			Repository repo("dogs.txt");
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