#include "FileAdoptionList.h"

FileAdoptionList::FileAdoptionList() :AdoptionList{}, filename{ "" }
{
}

void FileAdoptionList::setFileName(const std::string& filename)
{
	this->filename = filename;
}