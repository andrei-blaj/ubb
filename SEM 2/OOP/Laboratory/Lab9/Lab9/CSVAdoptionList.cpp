#include "CSVAdoptionList.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryException.h"

using namespace std;

void CSVAdoptionList::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto d : this->dogs)
		f << d;

	f.close();
}

void CSVAdoptionList::displayAdoptionList() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Accessories\WordPad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
