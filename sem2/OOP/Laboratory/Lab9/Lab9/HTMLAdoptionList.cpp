#include "HTMLAdoptionList.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryException.h"

using namespace std;

void HTMLAdoptionList::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");
	f << "<!DOCTYPE html><html><head><title>AdoptionList</title></head><body><table border=1><tr>";
	for (auto d : this->dogs)
	{
		f<< "<tr>" << "<td>" << d.getBreed() << "</td>" << "<td>" << d.getName() << "</td>" << "<td><a href =" << d.getPhotograph() << ">Link</a></td>" << "</tr>";
	}
	f << "</table></body></html>";
	f.close();
}

void HTMLAdoptionList::displayAdoptionList() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
